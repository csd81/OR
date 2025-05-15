/*
// Hungarian Algorithm for Assignment Problem


function HungarianMethod(cost_matrix):
n = number of rows/columns in cost_matrix
matrix = copy of cost_matrix

// Step 1: Row reduction
for each row in matrix:
    subtract the minimum value of the row from all elements in that row

// Step 2: Column reduction
for each column in matrix:
    subtract the minimum value of the column from all elements in that column

// Step 3: Cover all zeros using the minimum number of horizontal/vertical lines
while True:
    marked_zeros = find_independent_zero_positions(matrix)
    lines = cover_zeros_with_minimum_lines(matrix, marked_zeros)

    if number_of_lines == n:
        break  // we are ready for optimal assignment
    else:
        // Step 4: Adjust the matrix
        min_uncovered = minimum value in uncovered cells
        for each uncovered cell:
            subtract min_uncovered
        for each cell covered twice (row and column line):
            add min_uncovered

// Step 5: Assignment
result = assign_independent_zeros(marked_zeros)
return result

// Helper Functions Used:

function find_independent_zero_positions(matrix):
    Initialize mask_matrix of size n×n to track zeros: 0 = nothing, 1 = assigned, 2 = crossed
    For each row:
        If the row has a zero and no zero assigned in its column yet:
            assign that zero (mark as 1), block its row/column for future

    return mask_matrix

function cover_zeros_with_minimum_lines(matrix, mask_matrix):
    // Mark all rows without assigned zeros
    // Repeat:
    //   For each marked row:
    //     mark all columns with zeros in that row
    //   For each marked column:
    //     mark all rows that have assigned zeros in that column
    // Repeat until no more markings
    // Lines = all unmarked rows + all marked columns

    return number_of_lines

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

const int N = 6;
using Matrix = vector<vector<int>>;

void printMatrix(const Matrix& mat, const string& title) {
    cout << "\n" << title << ":\n";
    for (const auto& row : mat) {
        cout << "[ ";
        for (int val : row)
            cout << setw(2) << val << " ";
        cout << "]\n";
    }
}

void rowReduction(Matrix& mat) {
    for (int i = 0; i < N; ++i) {
        int rowMin = *min_element(mat[i].begin(), mat[i].end());
        for (int j = 0; j < N; ++j)
            mat[i][j] -= rowMin;
    }
}

void colReduction(Matrix& mat) {
    for (int j = 0; j < N; ++j) {
        int colMin = mat[0][j];
        for (int i = 1; i < N; ++i)
            colMin = min(colMin, mat[i][j]);
        for (int i = 0; i < N; ++i)
            mat[i][j] -= colMin;
    }
}

vector<int> findAssignments(const Matrix& mat) {
    vector<bool> rowCovered(N, false), colCovered(N, false);
    vector<int> assignment(N, -1);  // assignment[i] = column assigned to row i

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (mat[r][c] == 0 && !rowCovered[r] && !colCovered[c]) {
                assignment[r] = c;
                rowCovered[r] = true;
                colCovered[c] = true;
                break;
            }
        }
    }

    return assignment;
}

void printAssignment(const Matrix& original, const vector<int>& assignment) {
    int totalCost = 0;
    cout << "\nAssignment Result (✓ = assigned):\n";
    for (int i = 0; i < N; ++i) {
        cout << "[ ";
        for (int j = 0; j < N; ++j) {
            if (assignment[i] == j) {
                cout << "✓" << setw(2) << original[i][j] << " ";
                totalCost += original[i][j];
            } else {
                cout << setw(3) << original[i][j] << " ";
            }
        }
        cout << "]\n";
    }
    cout << "\nTotal Cost = " << totalCost << endl;
}

int main() {
    Matrix cost = {
        {1, 1, 2, 1, 1, 3},
        {2, 5, 4, 8, 6, 7},
        {3, 5, 4, 9, 2, 5},
        {4, 4, 4, 4, 5, 6},
        {2, 2, 2, 9, 7, 5},
        {9, 8, 7, 3, 2, 4}
    };

    printMatrix(cost, "Original Matrix");

    Matrix reduced = cost;
    rowReduction(reduced);
    printMatrix(reduced, "After Row Reduction");

    colReduction(reduced);
    printMatrix(reduced, "After Column Reduction");

    vector<int> assignment = findAssignments(reduced);
    printAssignment(cost, assignment);

    return 0;
}


