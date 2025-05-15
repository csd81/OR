
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
    int index;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
    vector<int> x;
    string path;
    int id;
    int parentId;

    bool operator<(const Node& other) const {
        return bound < other.bound; // max-heap
    }
};

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

int knapsackBnBTree(int capacity, const vector<Item>& items, vector<int>& bestX) {
    priority_queue<Node> pq;
    Node u, v;
    int n = items.size();
    int maxProfit = 0;
    int nodeCounter = 0;

    // initial root node
    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.x = vector<int>(n, 0);
    v.bound = computeBound(v, capacity, items);
    v.path = "ROOT";
    v.id = nodeCounter++;
    v.parentId = -1;
    pq.push(v);

    vector<Node> tree; // to store all nodes for visualization

    while (!pq.empty()) {
        v = pq.top(); pq.pop();
        tree.push_back(v);

        if (v.bound <= maxProfit || v.level == n) continue;

        // LEFT CHILD: take the item
        u.level = v.level + 1;
        u.weight = v.weight + items[v.level].weight;
        u.profit = v.profit + items[v.level].value;
        u.x = v.x;
        u.x[items[v.level].index] = 1;
        u.path = v.path + " → x" + to_string(v.level) + "=1";
        u.id = nodeCounter++;
        u.parentId = v.id;
        u.bound = computeBound(u, capacity, items);
        if (u.weight <= capacity && u.profit > maxProfit) {
            maxProfit = u.profit;
            bestX = u.x;
        }
        if (u.bound > maxProfit) pq.push(u);

        // RIGHT CHILD: skip the item
        u.weight = v.weight;
        u.profit = v.profit;
        u.x = v.x;
        u.x[items[v.level].index] = 0;
        u.path = v.path + " → x" + to_string(v.level) + "=0";
        u.id = nodeCounter++;
        u.parentId = v.id;
        u.bound = computeBound(u, capacity, items);
        if (u.bound > maxProfit) pq.push(u);
    }

    // Output tree
    cout << "\n📊 Branch and Bound Tree:\n";
    for (const Node& node : tree) {
        cout << node.path << " | profit = " << node.profit
             << ", weight = " << node.weight
             << ", bound = " << node.bound << "\n";
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

    // sort by decreasing ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    vector<int> bestX;
    int maxProfit = knapsackBnBTree(capacity, items, bestX);

    cout << "\n✅ Optimal value: " << maxProfit << "\n";
    cout << "Selected items (0-indexed): ";
    for (int i = 0; i < bestX.size(); ++i)
        if (bestX[i]) cout << i << " ";
    cout << endl;

    return 0;
}
