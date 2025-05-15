/*function solveTransportation(C, Supply, Demand):

    Step 1: Initialize matrix, allocations = zero matrix
    Step 2: While Supply and Demand remain:
        For each row i with remaining supply:
            compute row_penalty[i] = second lowest - lowest cost
        For each column j with remaining demand:
            compute col_penalty[j] = second lowest - lowest cost

        Choose max penalty (row or col)
        In selected row/col, pick the minimum cost cell (i, j)
        Allocate min(Supply[i], Demand[j]) to (i,j)
        Update Supply[i] and Demand[j]
        Mark exhausted rows/cols as unavailable
        Store allocation in matrix

    Step 3: Compute initial cost using allocations

    Step 4: Use MODI method to check optimality:
        Initialize u[i] and v[j] using allocated cells
        For each unallocated cell (i,j), compute reduced cost:
            r[i][j] = C[i][j] - u[i] - v[j]

        If all r[i][j] ≥ 0, optimal.
        Else: pick negative r[i][j], create loop, adjust allocations

    Output allocations and total cost
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Allocation {
    int amount;
    bool allocated;
};

void printMatrix(const vector<vector<int>>& cost, const vector<vector<Allocation>>& alloc) {
    int m = cost.size();
    int n = cost[0].size();
    cout << "\nCurrent Allocation Matrix (value(cost)):\n";
    cout << "     ";
    for (int j = 0; j < n; ++j)
        cout << setw(7) << "D" << j + 1;
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << "S" << i + 1 << " ";
        for (int j = 0; j < n; ++j) {
            if (alloc[i][j].allocated)
                cout << setw(4) << alloc[i][j].amount << "(" << cost[i][j] << ")";
            else
                cout << setw(7) << "-";
        }
        cout << endl;
    }
    cout << endl;
}

void vogelApproximation(vector<vector<int>> cost, vector<int> supply, vector<int> demand) {
    int m = cost.size();
    int n = cost[0].size();
    vector<vector<Allocation>> alloc(m, vector<Allocation>(n, {0, false}));

    while (true) {
        vector<int> rowPenalty(m, -1), colPenalty(n, -1);

        // Compute row penalties
        for (int i = 0; i < m; ++i) {
            if (supply[i] == 0) continue;
            vector<int> row;
            for (int j = 0; j < n; ++j)
                if (demand[j] > 0) row.push_back(cost[i][j]);
            sort(row.begin(), row.end());
            if (row.size() >= 2)
                rowPenalty[i] = row[1] - row[0];
            else if (row.size() == 1)
                rowPenalty[i] = row[0];
        }

        // Compute column penalties
        for (int j = 0; j < n; ++j) {
            if (demand[j] == 0) continue;
            vector<int> col;
            for (int i = 0; i < m; ++i)
                if (supply[i] > 0) col.push_back(cost[i][j]);
            sort(col.begin(), col.end());
            if (col.size() >= 2)
                colPenalty[j] = col[1] - col[0];
            else if (col.size() == 1)
                colPenalty[j] = col[0];
        }

        // Find max penalty
        int maxPen = -1, maxIdx = -1;
        bool rowMax = true;
        for (int i = 0; i < m; ++i)
            if (rowPenalty[i] > maxPen) maxPen = rowPenalty[i], maxIdx = i, rowMax = true;
        for (int j = 0; j < n; ++j)
            if (colPenalty[j] > maxPen) maxPen = colPenalty[j], maxIdx = j, rowMax = false;

        if (maxPen == -1) break; // done

        int minCost = INF, selRow = -1, selCol = -1;
        if (rowMax) {
            int i = maxIdx;
            for (int j = 0; j < n; ++j) {
                if (demand[j] > 0 && cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    selRow = i;
                    selCol = j;
                }
            }
        } else {
            int j = maxIdx;
            for (int i = 0; i < m; ++i) {
                if (supply[i] > 0 && cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    selRow = i;
                    selCol = j;
                }
            }
        }

        int x = min(supply[selRow], demand[selCol]);
        alloc[selRow][selCol] = {x, true};
        supply[selRow] -= x;
        demand[selCol] -= x;

        printMatrix(cost, alloc);
    }

    int totalCost = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (alloc[i][j].allocated)
                totalCost += alloc[i][j].amount * cost[i][j];

    cout << "Total Transportation Cost: " << totalCost << endl;
}

int main() {
    vector<vector<int>> cost = {
        {1, 3, 5, 7},
        {6, 2, 9, 1},
        {8, 4, 5, 2},
        {3, 8, 1, 1}
    };
    vector<int> supply = {12, 12, 14, 20};
    vector<int> demand = {13, 15, 16, 14};

    vogelApproximation(cost, supply, demand);
    return 0;
}
