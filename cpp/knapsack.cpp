#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

struct Item {
    int index;
    double value, weight;
    double ratio;

    Item(int i, double v, double w) : index(i), value(v), weight(w), ratio(v/w) {}
};

struct Node {
    int level;
    double value;
    double weight;
    double bound;
    vector<int> taken;

    Node(int lvl, double val, double wt, double bnd, vector<int> tk)
        : level(lvl), value(val), weight(wt), bound(bnd), taken(tk) {}
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double bound(const Node& node, int capacity, const vector<Item>& items) {
    if (node.weight >= capacity) return 0;

    double val_bound = node.value;
    int i = node.level;
    double totalWeight = node.weight;

    while (i < items.size() && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        val_bound += items[i].value;
        i++;
    }
    if (i < items.size()) {
        double remain = capacity - totalWeight;
        val_bound += items[i].value * (remain / items[i].weight);
    }
    return val_bound;
}

void branchAndBoundKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), cmp);

    vector<Node> stack;
    Node root(0, 0, 0, bound(Node(0, 0, 0, 0, {}), capacity, items), {});
    stack.push_back(root);

    double maxValue = 0;
    vector<int> bestTaken;
    int step = 0;

    while (!stack.empty()) {
        Node node = stack.back(); stack.pop_back();

        cout << "Step " << step++ << ": Level=" << node.level << ", Value=" << node.value
             << ", Weight=" << node.weight << ", Bound=" << node.bound << ", Taken=";
        for (int x : node.taken) cout << x; cout << endl;

        if (node.level == items.size()) continue;

        int idx = node.level;

        // Take the item
        if (node.weight + items[idx].weight <= capacity) {
            vector<int> taken = node.taken;
            taken.push_back(1);
            Node left(
                idx + 1,
                node.value + items[idx].value,
                node.weight + items[idx].weight,
                0, taken);
            left.bound = bound(left, capacity, items);

            if (left.value > maxValue) {
                maxValue = left.value;
                bestTaken = taken;
            }

            if (left.bound > maxValue)
                stack.push_back(left);
        }

        // Don't take the item
        vector<int> taken = node.taken;
        taken.push_back(0);
        Node right(idx + 1, node.value, node.weight, 0, taken);
        right.bound = bound(right, capacity, items);

        if (right.bound > maxValue)
            stack.push_back(right);
    }

    cout << "\nBest value: " << maxValue << "\nBest selection: ";
    for (int x : bestTaken) cout << x << " "; cout << endl;
}

int main() {
    int capacity = 15;
    vector<Item> items = {
        {0, 8, 1},
        {1, 35, 5},
        {2, 13, 2},
        {3, 36, 6},
        {4, 22, 4},
        {5, 15, 3}
    };

    branchAndBoundKnapsack(items, capacity);
    return 0;
}
