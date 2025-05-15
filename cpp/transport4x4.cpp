#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <tuple>

using namespace std;

struct Cell {
    int i, j, cost, alloc;
    bool isBasic;
};

const int INF = numeric_limits<int>::max();

void printMatrix(const vector<vector<Cell>>& matrix) {
    cout << "\nCurrent Allocation Matrix (A=allocated, -=empty):\n";
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            if (cell.alloc > 0 || cell.isBasic)
                cout << setw(6) << cell.cost << "(A" << cell.alloc << ")";
            else
                cout << setw(6) << cell.cost << "(-)";
        }
        cout << endl;
    }
    cout << endl;
}

int findPenalty(const vector<int>& costs) {
    if (costs.size() < 2) return INF;
    vector<int> tmp = costs;
    sort(tmp.begin(), tmp.end());
    return tmp[1] - tmp[0];
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

void vogelApproximation(vector<vector<Cell>>& matrix, vector<int>& supply, vector<int>& demand) {
    int m = matrix.size(), n = matrix[0].size();

    cout << "\n=== VAM: Vogel's Approximation Method ===\n";

    while (true) {
        // Check if finished
        bool done = true;
        for (int s : supply) if (s > 0) done = false;
        for (int d : demand) if (d > 0) done = false;
        if (done) break;

        // Compute penalties
        vector<pair<int, int>> rowPenalty(m, { -1, -1 });
        vector<pair<int, int>> colPenalty(n, { -1, -1 });

        for (int i = 0; i < m; ++i) {
            vector<int> rowCosts;
            for (int j = 0; j < n; ++j) if (demand[j] > 0) rowCosts.push_back(matrix[i][j].cost);
            if (!rowCosts.empty())
                rowPenalty[i] = { findPenalty(rowCosts), i };
        }
        for (int j = 0; j < n; ++j) {
            vector<int> colCosts;
            for (int i = 0; i < m; ++i) if (supply[i] > 0) colCosts.push_back(matrix[i][j].cost);
            if (!colCosts.empty())
                colPenalty[j] = { findPenalty(colCosts), j };
        }

        // Find max penalty
        int maxP = -1, iBest = -1, jBest = -1;
        bool isRow = true;
        for (auto [pen, i] : rowPenalty) if (pen > maxP) maxP = pen, iBest = i, isRow = true;
        for (auto [pen, j] : colPenalty) if (pen > maxP) maxP = pen, jBest = j, isRow = false;

        if (isRow) {
            int minCost = INF, jMin = -1;
            for (int j = 0; j < n; ++j) {
                if (demand[j] > 0 && matrix[iBest][j].cost < minCost) {
                    minCost = matrix[iBest][j].cost;
                    jMin = j;
                }
            }
            int alloc = min(supply[iBest], demand[jMin]);
            matrix[iBest][jMin].alloc = alloc;
            matrix[iBest][jMin].isBasic = true;
            supply[iBest] -= alloc;
            demand[jMin] -= alloc;
            cout << "Allocated " << alloc << " to cell (" << iBest+1 << "," << jMin+1 << ") with cost " << matrix[iBest][jMin].cost << endl;
        } else {
            int minCost = INF, iMin = -1;
            for (int i = 0; i < m; ++i) {
                if (supply[i] > 0 && matrix[i][jBest].cost < minCost) {
                    minCost = matrix[i][jBest].cost;
                    iMin = i;
                }
            }
            int alloc = min(supply[iMin], demand[jBest]);
            matrix[iMin][jBest].alloc = alloc;
            matrix[iMin][jBest].isBasic = true;
            supply[iMin] -= alloc;
            demand[jBest] -= alloc;
            cout << "Allocated " << alloc << " to cell (" << iMin+1 << "," << jBest+1 << ") with cost " << matrix[iMin][jBest].cost << endl;
        }
        printMatrix(matrix);
        pause();
    }
}

void modiMethod(const vector<vector<Cell>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> u(m, INF), v(n, INF);

    // Step 1: Assign u[0] = 0, compute others from basic cells
    u[0] = 0;
    bool updated;
    do {
        updated = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j].isBasic) {
                    if (u[i] != INF && v[j] == INF) {
                        v[j] = matrix[i][j].cost - u[i]; updated = true;
                    } else if (v[j] != INF && u[i] == INF) {
                        u[i] = matrix[i][j].cost - v[j]; updated = true;
                    }
                }
            }
        }
    } while (updated);

    // Step 2: Compute opportunity costs for non-basic cells
    cout << "\n=== MODI Method: Opportunity Costs ===\n";
    bool optimal = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!matrix[i][j].isBasic) {
                int delta = matrix[i][j].cost - (u[i] + v[j]);
                cout << "Delta[" << i+1 << "," << j+1 << "] = " << delta << endl;
                if (delta < 0) optimal = false;
            }
        }
    }
    if (optimal) cout << "\nCurrent solution is OPTIMAL.\n";
    else cout << "\nCurrent solution is NOT optimal (negative deltas exist).\n";
}

int main() {
    vector<vector<int>> costs = {
        {7, 3, 5, 7},
        {6, 2, 9, 1},
        {8, 4, 5, 2},
        {3, 8, 1, 4}
    };
    vector<int> supply = {12, 12, 14, 20};
    vector<int> demand = {13, 15, 16, 14};

    int m = supply.size(), n = demand.size();
    vector<vector<Cell>> matrix(m, vector<Cell>(n));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = {i, j, costs[i][j], 0, false};

    vogelApproximation(matrix, supply, demand);

    cout << "\n=== END OF VAM ===\n";
    pause();
    modiMethod(matrix);

    return 0;
}
