
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

// Item structure
struct Item {
    int value;
    int weight;
    double ratio;
    int index;
};

// Node in B&B tree
struct Node {
    int level;
    int profit;
    int weight;
    double bound;
    vector<int> x; // 0 or 1 for each item

    bool operator<(const Node& other) const {
        return bound < other.bound; // max-heap
    }
};

// Compute upper bound using fractional knapsack
double computeBound(const Node& node, int capacity, const vector<Item>& items) {
    if (node.weight > capacity) return 0;

    double bound = node.profit;
    int remaining = capacity - node.weight;

    for (int i = node.level; i < items.size(); ++i) {
        if (items[i].weight <= remaining) {
            remaining -= items[i].weight;
            bound += items[i].value;
        } else {
            bound += items[i].ratio * remaining;
            break;
        }
    }
    return bound;
}

int knapsackBranchAndBoundLogged(int capacity, const vector<Item>& items, vector<int>& bestX) {
    priority_queue<Node> pq;
    Node u, v;
    int n = items.size();
    int maxProfit = 0;
    int nodeCount = 0;

    // initial root node
    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.x = vector<int>(n, 0);
    v.bound = computeBound(v, capacity, items);
    pq.push(v);

    cout << setw(8) << "Node#" << setw(8) << "Level"
         << setw(10) << "Weight" << setw(10) << "Profit"
         << setw(10) << "Bound" << setw(15) << "Selection (x)\n";
    cout << string(65, '-') << "\n";

    while (!pq.empty()) {
        v = pq.top(); pq.pop();
        nodeCount++;

        cout << setw(8) << nodeCount
             << setw(8) << v.level
             << setw(10) << v.weight
             << setw(10) << v.profit
             << setw(10) << fixed << setprecision(1) << v.bound
             << "   ";
        for (int bit : v.x) cout << bit;
        cout << "\n";

        if (v.bound <= maxProfit || v.level == n) continue;

        // Left child: include item
        u.level = v.level + 1;
        u.weight = v.weight + items[v.level].weight;
        u.profit = v.profit + items[v.level].value;
        u.x = v.x;
        u.x[items[v.level].index] = 1;

        if (u.weight <= capacity && u.profit > maxProfit) {
            maxProfit = u.profit;
            bestX = u.x;
        }

        u.bound = computeBound(u, capacity, items);
        if (u.bound > maxProfit) pq.push(u);

        // Right child: exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        u.x = v.x;
        u.x[items[v.level].index] = 0;
        u.bound = computeBound(u, capacity, items);
        if (u.bound > maxProfit) pq.push(u);
    }

    return maxProfit;
}

int main() {
    int capacity = 12;
    vector<Item> items = {
        {10, 1, 0.0, 0},
        {18, 2, 0.0, 1},
        {24, 3, 0.0, 2},
        {30, 4, 0.0, 3},
        {35, 5, 0.0, 4}
    };

    for (auto& item : items)
        item.ratio = (double)item.value / item.weight;

    // Sort by descending ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    vector<int> bestX;
    int maxProfit = knapsackBranchAndBoundLogged(capacity, items, bestX);

    cout << "\nMaximum value: " << maxProfit << "\n";
    cout << "Selected items (0-indexed): ";
    for (int i = 0; i < bestX.size(); ++i)
        if (bestX[i]) cout << i << " ";
    cout << endl;

    return 0;
}
