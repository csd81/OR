/*

Input: A, b, c (where Ax <= b, x >= 0, and objective is max cᵀx)

Add slack variables to convert inequalities to equalities.
Construct the initial tableau T.

while (there exists a negative coefficient in the objective row):
    1. Select pivot column (most negative coefficient in bottom row).
    2. For each row i:
        if tableau[i][pivot_col] > 0:
            compute ratio = tableau[i][RHS] / tableau[i][pivot_col]
    3. Choose row with minimum positive ratio → pivot row.
    4. Perform pivot operation:
        - Normalize pivot row
        - Zero out other entries in pivot column
end while

Output: Optimal solution from tableau

*/ 

#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

class Simplex {
    std::vector<std::vector<double>> tableau_;
    int numRows_, numCols_;

    int findEnteringVariable() {
        int enteringCol = -1;
        double minValue = 0;
        for (int j = 0; j < numCols_ - 1; ++j) {
            if (tableau_[numRows_ - 1][j] < minValue) {
                minValue = tableau_[numRows_ - 1][j];
                enteringCol = j;
            }
        }
        return enteringCol;
    }

    int findLeavingVariable(int enteringCol) {
        double minRatio = std::numeric_limits<double>::max();
        int leavingRow = -1;
        for (int i = 0; i < numRows_ - 1; ++i) {
            double coef = tableau_[i][enteringCol];
            if (coef > 0) {
                double ratio = tableau_[i][numCols_ - 1] / coef;
                if (ratio < minRatio) {
                    minRatio = ratio;
                    leavingRow = i;
                }
            }
        }
        return leavingRow;
    }

    void pivot(int enteringCol, int leavingRow) {
        double pivotElement = tableau_[leavingRow][enteringCol];
        for (int j = 0; j < numCols_; ++j)
            tableau_[leavingRow][j] /= pivotElement;

        for (int i = 0; i < numRows_; ++i) {
            if (i != leavingRow) {
                double factor = tableau_[i][enteringCol];
                for (int j = 0; j < numCols_; ++j)
                    tableau_[i][j] -= factor * tableau_[leavingRow][j];
            }
        }
    }

    void printTableau() {
        std::cout << "Current tableau:\n";
        for (const auto& row : tableau_) {
            for (double val : row)
                std::cout << std::setw(8) << val << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

public:
    Simplex(const std::vector<std::vector<double>>& tableau)
        : tableau_(tableau), numRows_(tableau.size()), numCols_(tableau[0].size()) {}

    void solve() {
        while (true) {
            int entering = findEnteringVariable();
            if (entering == -1) {
                std::cout << "Optimal solution found.\n";
                break;
            }

            int leaving = findLeavingVariable(entering);
            if (leaving == -1) {
                std::cerr << "Unbounded solution.\n";
                return;
            }

            pivot(entering, leaving);
            printTableau();
        }

        std::cout << "Objective value: " << tableau_[numRows_ - 1][numCols_ - 1] << "\n";
    }
};

int main() {
    std::vector<std::vector<double>> tableau = {
        {1, 2, 1, 3, 0, 0, 0, 0, 24},
        {0, 1, 1, 5, 1, 0, 1, 0, 43},
        {1, 0, 0, 2, 2, 0, 0, 1, 18},
        {-19, -23, -15, -42, -33, 0, 0, 0, 0}
    };

    /*
|        | P1 | P2 | P3 | P4 | P5 | Capacity (Cap) |
| ------ | -- | -- | -- | -- | -- | -------------- |
| Res1   | 1  | 2  | 1  | 3  | 0  | 24             |
| Res2   | 0  | 1  | 1  | 5  | 1  | 43             |
| Res3   | 1  | 0  | 0  | 2  | 2  | 18             |
| Profit | 19 | 23 | 15 | 42 | 33 |                |
    */

    Simplex simplex(tableau);
    simplex.solve();
    return 0;
}
