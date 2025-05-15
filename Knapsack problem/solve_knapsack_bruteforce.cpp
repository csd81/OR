#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    // Item values and weights
    vector<int> values  = {10, 18, 24, 30, 35}; // g
    vector<int> weights = {1,  2,  3,  4,  5};  // w
    int capacity = 12;
    int n = values.size();

    int maxValue = 0;
    vector<int> bestSolution;

    // Try all subsets (2^n)
    for (int mask = 0; mask < (1 << n); ++mask) {
        int totalWeight = 0;
        int totalValue = 0;
        vector<int> current(n);

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                totalWeight += weights[i];
                totalValue  += values[i];
                current[i] = 1;
            } else {
                current[i] = 0;
            }
        }
        
        for (int bit : current) {
            cout << bit << " " ;
        }
        
        cout << " " << totalWeight << " " << capacity << (totalWeight <= capacity ? " + " : " - ")  <<  maxValue  << " ";
        if (totalWeight <= capacity && totalValue > maxValue){
            cout << totalValue  << endl;}
        else{ cout << "(" << totalValue << ")" << endl;}

        if (totalWeight <= capacity && totalValue > maxValue) {
            maxValue = totalValue;
            bestSolution = current;
        }
    }

    // Output the result
    cout << "Maximum value: " << maxValue << endl;
    cout << "Best item selection (x vector): ";
    for (int bit : bestSolution) {
        cout << bit << " ";
    }
    cout << endl;

    // Recalculate weight
    int finalWeight = 0;
    for (int i = 0; i < n; ++i) {
        finalWeight += bestSolution[i] * weights[i];
    }
    cout << "Total weight: " << finalWeight << " / Capacity: " << capacity << endl;

    return 0;
}