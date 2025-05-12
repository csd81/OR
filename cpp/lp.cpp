// Linear programming problem
// This problem can be solved using various algorithms, including the Simplex algorithm,
// the Interior Point method, and the Dual Simplex algorithm.
// In this implementation, we will use the Simplex algorithm.

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
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <complex>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <stack>

namespace LP {
    struct Constraint {
        std::vector<double> coefficients;
        double rhs;
        char sense;
    };

    struct Objective {
        std::vector<double> coefficients;
        bool maximize;
    };
    struct Solution {
        std::vector<double> values;
        double objectiveValue;
    };
class Simplex {
public:
    Simplex(const Objective& objective, const std::vector<Constraint>& constraints)
        : objective_(objective), constraints_(constraints) {
        numVariables_ = objective_.coefficients.size();
        numConstraints_ = constraints_.size();
        tableau_.resize(numConstraints_ + 1, std::vector<double>(numVariables_ + numConstraints_ + 1, 0));
        for (int i = 0; i < numConstraints_; ++i) {
            for (int j = 0; j < numVariables_; ++j) {
                tableau_[i][j] = constraints_[i].coefficients[j];
            }
            tableau_[i][numVariables_ + i] = 1; // Slack variable
            tableau_[i].back() = constraints_[i].rhs;
        }
        for (int j = 0; j < numVariables_; ++j) {
            tableau_[numConstraints_][j] = -objective_.coefficients[j];
        }
    }
    Solution solve() {
        while (true) {
            int pivotCol = findPivotColumn();
            if (pivotCol == -1) {
                break; // Optimal solution found
            }
            int pivotRow = findPivotRow(pivotCol);
            if (pivotRow == -1) {
                throw std::runtime_error("Problem is unbounded.");
            }
            pivot(pivotRow, pivotCol);
        }
        return extractSolution();
    }
private:
    int findPivotColumn() {
        int pivotCol = -1;
        double minValue = 0;
        for (int j = 0; j < numVariables_ + numConstraints_; ++j) {
            if (tableau_[numConstraints_][j] < minValue) {
                minValue = tableau_[numConstraints_][j];
                pivotCol = j;
            }
        }
        return pivotCol;
    }
    int findPivotRow(int pivotCol) {
        int pivotRow = -1;
        double minRatio = std::numeric_limits<double>::max();
        for (int i = 0; i < numConstraints_; ++i) {
            if (tableau_[i][pivotCol] > 0) {
                double ratio = tableau_[i].back() / tableau_[i][pivotCol];
                if (ratio < minRatio) {
                    minRatio = ratio;
                    pivotRow = i;
                }
            }
        }
        return pivotRow;
    }
    void pivot(int pivotRow, int pivotCol) {
        double pivotValue = tableau_[pivotRow][pivotCol];
        for (int j = 0; j < tableau_[pivotRow].size(); ++j) {
            tableau_[pivotRow][j] /= pivotValue;
        }
        for (int i = 0; i < tableau_.size(); ++i) {
            if (i != pivotRow) {
                double factor = tableau_[i][pivotCol];
                for (int j = 0; j < tableau_[i].size(); ++j) {
                    tableau_[i][j] -= factor * tableau_[pivotRow][j];
                }
            }
        }
    }
    Solution extractSolution() {
        Solution solution;
        solution.values.resize(numVariables_);
        for (int j = 0; j < numVariables_; ++j) {
            solution.values[j] = tableau_[0][j];
        }
        solution.objectiveValue = tableau_[0].back();
        return solution;
    }

    Objective objective_;
    std::vector<Constraint> constraints_;
    int numVariables_;
    int numConstraints_;
    std::vector<std::vector<double>> tableau_;
};
} // namespace LP

int main() {
    LP::Objective objective;
    objective.coefficients = {3, 5};
    objective.maximize = true;

    std::vector<LP::Constraint> constraints = {
        {{2, 3}, 12, '<'},
        {{1, 2}, 8, '<'},
        {{1, 1}, 4, '<'}
    };

    LP::Simplex simplex(objective, constraints);
    LP::Solution solution = simplex.solve();

    std::cout << "Optimal solution: ";
    for (double value : solution.values) {
        std::cout << value << " ";
    }
    std::cout << "\nObjective value: " << solution.objectiveValue << std::endl;

    return 0;
}