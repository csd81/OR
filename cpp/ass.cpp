// the assignment problem is a fundamental combinatorial optimization problem
// that seeks to find the optimal way to assign a set of tasks to a set of agents
// in a way that minimizes the total cost or maximizes the total profit.
// This problem can be solved using various algorithms, including the Hungarian algorithm,
// the Kuhn-Munkres algorithm, and the Auction algorithm.
// In this implementation, we will use the Hungarian algorithm.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> hungarianAlgorithm(const vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    int m = costMatrix[0].size();
    vector<int> u(n, 0), v(m, 0), p(m, -1), way(m, -1);
    for (int i = 0; i < n; ++i) {
        vector<int> minv(m, INF);
        vector<bool> used(m, false);
        int j0 = 0;
        for (int j = 0; j < m; ++j) {
            minv[j] = costMatrix[i][j] - u[i] - v[j];
        }
        while (true) {
            used[j0] = true;
            int i0 = -1, delta = INF;
            for (int j = 0; j < m; ++j) {
                if (!used[j]) {
                    if (minv[j] < delta) {
                        delta = minv[j];
                        i0 = j;
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = i0;
            if (p[j0] == -1) break;
        }
        for (int j = 0; j < m; ++j) {
            if (used[j] && p[j] == -1) {
                p[j] = i;
            }
        }
    }
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int j = 0; j < m; ++j) {
        if (p[j] != -1) {
            result[p[j]][j] = 1;
        }
    }
    return result;
}