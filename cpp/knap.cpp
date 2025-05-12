// the knapsack problem is a fundamental combinatorial optimization problem
// that seeks to find the optimal way to pack a set of items into a knapsack
// in a way that maximizes the total value without exceeding the weight capacity.
// This problem can be solved using various algorithms, including dynamic programming,
// branch and bound, and greedy algorithms.

// In this implementation, we will use dynamic programming.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <string>

int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    std::vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weights[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

int main() {
    int W = 50; // Maximum weight capacity of the knapsack
    std::vector<int> weights = {10, 20, 30}; // Weights of the items
    std::vector<int> values = {60, 100, 120}; // Values of the items

    int maxValue = knapsack(W, weights, values);
    std::cout << "Maximum value in knapsack: " << maxValue << std::endl;

    return 0;
}