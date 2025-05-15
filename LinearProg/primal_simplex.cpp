#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to print the Simplex tableau
void printTableau(const vector<vector<double>>& tableau) {
    cout << "\nSimplex Tableau:\n";
    for (const auto& row : tableau) {
        for (double val : row) {
            cout << setw(10) << fixed << setprecision(2) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to find the column with the most negative reduced cost
int findEnteringVariable(const vector<double>& lastRow) {
    int col = -1;
    double minVal = 0;
    for (int j = 0; j < lastRow.size() - 1; j++) {
        if (lastRow[j] < minVal) {
            minVal = lastRow[j];
            col = j;
        }
    }
    return col;
}

// Function to find the leaving variable using the minimum ratio rule
int findLeavingVariable(const vector<vector<double>>& tableau, int enteringCol) {
    int row = -1;
    double minRatio = 1e9;
    for (int i = 0; i < tableau.size() - 1; i++) {
        double rhs = tableau[i].back();
        double coeff = tableau[i][enteringCol];
        if (coeff > 0) {
            double ratio = rhs / coeff;
            if (ratio < minRatio) {
                minRatio = ratio;
                row = i;
            }
        }
    }
    return row;
}

// Function to perform pivoting
void pivot(vector<vector<double>>& tableau, int pivotRow, int pivotCol) {
    double pivotElement = tableau[pivotRow][pivotCol];

    // Normalize the pivot row
    for (double& val : tableau[pivotRow]) {
        val /= pivotElement;
    }

    // Zero out the pivot column in other rows
    for (int i = 0; i < tableau.size(); i++) {
        if (i != pivotRow) {
            double factor = tableau[i][pivotCol];
            for (int j = 0; j < tableau[i].size(); j++) {
                tableau[i][j] -= factor * tableau[pivotRow][j];
            }
        }
    }
}

// Main Simplex Algorithm
void simplex(vector<vector<double>>& tableau) {
    while (true) {
        printTableau(tableau);

        // Step 1: Find entering variable (most negative reduced cost)
        int enteringCol = findEnteringVariable(tableau.back());
        if (enteringCol == -1) {
            cout << "Optimal solution reached!" << endl;
            break;
        }

        // Step 2: Find leaving variable (minimum ratio rule)
        int leavingRow = findLeavingVariable(tableau, enteringCol);
        if (leavingRow == -1) {
            cout << "Unbounded solution!" << endl;
            return;
        }

        // Step 3: Perform pivoting
        pivot(tableau, leavingRow, enteringCol);
        cout << "Pivoting: Entering variable (col " << enteringCol 
             << "), Leaving variable (row " << leavingRow << ")\n";
    }

    // Display final solution
    cout << "\nOptimal Solution Found:\n";
    for (int i = 0; i < tableau.size() - 1; i++) {
        cout << "x" << i + 1 << " = " << tableau[i].back() << endl;
    }
    cout << "Maximum Objective Value (z) = " << tableau.back().back() << endl;
}

int main() {
    // Example problem: Maximize z = 3x1 + 5x2
    // Subject to:
    // x1 + x2 <= 4
    // 2x1 + x2 <= 6
    // x1, x2 >= 0

    vector<vector<double>> tableau = {
        {1, 1, 1, 0, 4},   // Constraint 1: x1 + x2 + s1 = 4
        {2, 1, 0, 1, 6},   // Constraint 2: 2x1 + x2 + s2 = 6
        {-3, -5, 0, 0, 0}  // Objective: Max z = 3x1 + 5x2
    };

    simplex(tableau);

    return 0;
}
