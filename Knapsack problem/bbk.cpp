#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<bool> taken;

    // For priority queue (max-heap)
    bool operator<(const Node& other) const {
        return bound < other.bound;
    }
};

// Compute upper bound for a node (fractional knapsack)
double bound(Node node, int n, int C, const vector<Item>& items) {
    if (node.weight >= C) return 0;

    double result = node.profit;
    int totalWeight = node.weight;

    for (int i = node.level; i < n; ++i) {
        if (totalWeight + items[i].weight <= C) {
            totalWeight += items[i].weight;
            result += items[i].value;
        } else {
            int remain = C - totalWeight;
            result += items[i].ratio * remain;
            break;
        }
    }
    return result;
}

int branchAndBoundKnapsack(const vector<Item>& items, int C, vector<bool>& bestTaken) {
    int n = items.size();
    priority_queue<Node> pq;
    Node u, v;

    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.taken = vector<bool>(n, false);
    v.bound = bound(v, n, C, items);
    pq.push(v);

    int maxProfit = 0;

    while (!pq.empty()) {
        v = pq.top(); pq.pop();

        if (v.bound <= maxProfit || v.level >= n) continue;

        // Left child (include item)
        u.level = v.level + 1;
        u.weight = v.weight + items[v.level].weight;
        u.profit = v.profit + items[v.level].value;
        u.taken = v.taken;
        u.taken[v.level] = true;

        if (u.weight <= C && u.profit > maxProfit) {
            maxProfit = u.profit;
            bestTaken = u.taken;
        }

        u.bound = bound(u, n, C, items);
        if (u.bound > maxProfit) pq.push(u);

        // Right child (exclude item)
        u.weight = v.weight;
        u.profit = v.profit;
        u.taken = v.taken;
        u.taken[v.level] = false;
        u.bound = bound(u, n, C, items);
        if (u.bound > maxProfit) pq.push(u);
    }

    return maxProfit;
}

int main() {
    // Define items
    vector<Item> items = {
        {8, 1}, {35, 5}, {13, 2}, {36, 6}, {22, 4}, {15, 3}
    };
    int C = 15;

    // Compute value-to-weight ratio
    for (int i = 0; i < items.size(); ++i) {
        items[i].ratio = (double)items[i].value / items[i].weight;
        items[i].index = i;
    }

    // Sort by decreasing ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    vector<bool> bestTaken;
    int maxProfit = branchAndBoundKnapsack(items, C, bestTaken);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Items taken (original indices): ";
    for (int i = 0; i < bestTaken.size(); ++i) {
        if (bestTaken[i]) cout << items[i].index << " ";
    }
    cout << endl;

    return 0;
}