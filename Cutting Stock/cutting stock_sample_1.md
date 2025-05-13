This document is a **step-by-step solution** to a **Cutting Stock Problem** using the **Gomory-Gilmore column generation method**. Here's a detailed breakdown of what's happening:

---

### 📦 Problem Setup

* **Stock length**: C = 14 units
* **Orders**: You need to cut specific numbers of items of various lengths from these stock materials:

| Size | Demand |
| ---- | ------ |
| 2    | 30     |
| 3    | 50     |
| 5    | 20     |
| 7    | 80     |

---

### 🔧 Phase 0 – Initial Setup

**Initial cutting patterns (a1 to a4)** are trivial (e.g., only one size per pattern):

* a1: 7 pieces of size 2
* a2: 4 pieces of size 3
* a3: 2 pieces of size 5
* a4: 2 pieces of size 7

This makes the initial basis `B = {a1, a2, a3, a4}`. The inverse of the basis matrix $B^{-1}$ is calculated (diagonal because patterns are disjoint).

Then the **dual prices** π are calculated:
$π = c_B \cdot B^{-1} = [1/7; 1/4; 1/2; 1/2]$

Then we solve the **slave problem** (a knapsack problem) to find a new column (cutting pattern) with a **reduced cost > 0**, indicating it's **profitable to add**.

🆕 Found: a5 = (2, 0, 2, 0)
This gives improvement z = 2/7 + 1 - 1 = 2/7 > 0 → **add to basis**

Use **minimum ratio test** to see who leaves: `a3` is removed.

---

### 🔁 Phase 1 – Update Basis and Repeat

New basis: `B = {a1, a2, a5, a4}`

* Update $B^{-1}$
* Compute new π
* Solve new slave problem again

🆕 Found: a6 = (0, 3, 1, 0)
z = 3/4 + 5/14 - 1 > 0 → profitable → add to basis

Use ratio test → `a2` leaves.

---

### 🔁 Phase 2 – Final Basis and Termination

New basis: `B = {a1, a6, a5, a4}`

* Again update $B^{-1}$
* Compute new π
* Solve slave problem → **no further improvements** → z = 0 → **optimal**

Now calculate:
$x_B = B^{-1} \cdot b = (80/21, 50/3, 5/3, 40) \Rightarrow z^* \approx 62.14 \Rightarrow \lceil z^* \rceil = 63$

Try rounding the solution vector to nearest integers:
→ x = (4, 17, 2, 40) → sum = 63 ✅

---

### ✅ Final Solution Summary

| Pattern | Times Used | What It Cuts                          |
| ------- | ---------- | ------------------------------------- |
| a1      | 4          | 4×7 of size 2 = 28 total size-2 items |
| a6      | 17         | 17×(3×3 + 1×5) = 51 size-3, 17 size-5 |
| a5      | 2          | 2×(2×2 + 2×5) = 4 size-2, 4 size-5    |
| a4      | 40         | 40×2 of size 7 = 80 size-7            |

**Final totals:**

* Size 2: 28 + 4 = 32 (need 30)
* Size 3: 51 (need 50)
* Size 5: 17 + 4 = 21 (need 20)
* Size 7: 80 (exact)

So all demands are satisfied (some slightly over) with 63 stock materials cut, which is optimal.

---

Would you like a visual diagram of the basis changes or an implementation in Python or C++?


Here is a **step-by-step breakdown** of the **Cutting Stock Problem** and how it is solved using the **column generation (Gomory-Gilmore method)**:

---

## 🟨 Problem Definition

We are given:

* **Stock length** (capacity): `C = 14`
* **Item sizes and demands**:

| Size | Demand |
| ---- | ------ |
| 2    | 30     |
| 3    | 50     |
| 5    | 20     |
| 7    | 80     |

Our goal is to **minimize the number of stock bars used** to cut all items.

---

## 🟦 Phase 0 – Start with Trivial Patterns

We begin with simple patterns where each only cuts one item type:

| Size | a₁ | a₂ | a₃ | a₄ |
| ---- | -- | -- | -- | -- |
| 2    | 7  | 0  | 0  | 0  |
| 3    | 0  | 4  | 0  | 0  |
| 5    | 0  | 0  | 2  | 0  |
| 7    | 0  | 0  | 0  | 2  |

Each pattern fits exactly into one 14-unit stock.

So, initial **basis**:
**B = {a₁, a₂, a₃, a₄}**

---

### 🔢 Step 1: Compute Basis Inverse (B⁻¹)

Since each pattern is disjoint and fits perfectly:

$$
B^{-1} =
\begin{bmatrix}
1/7 & 0   & 0   & 0 \\
0   & 1/4 & 0   & 0 \\
0   & 0   & 1/2 & 0 \\
0   & 0   & 0   & 1/2 \\
\end{bmatrix}
$$

---

### 🔢 Step 2: Compute Dual Prices (π)

$$
π = c_B \cdot B^{-1} = [1, 1, 1, 1] \cdot B^{-1} = [1/7, 1/4, 1/2, 1/2]
$$

---

### 🔢 Step 3: Solve Slave Problem

Find new cutting pattern that **maximizes**:

$$
π_1 a_1 + π_2 a_2 + π_3 a_3 + π_4 a_4 - 1
$$

Subject to:

$$
2a_1 + 3a_2 + 5a_3 + 7a_4 \leq 14 \quad\text{(stock capacity)}  
\quad a_i \in \mathbb{Z}_{\geq 0}
$$

Trying different feasible combinations, best one is:

**a₅ = (2, 0, 2, 0)**
→ 2×2 + 2×5 = 4 + 10 = 14 → feasible
→ Reduced cost = (2×1/7 + 2×1/2) − 1 = 2/7 > 0 → **profitable**

---

### 🔢 Step 4: Compute Leaving Variable

Let’s compute:

* **x\_B = B⁻¹·b** = (30, 50, 20, 80) demands

$$
x_B = 
\begin{bmatrix}
30/7 \\
50/4 \\
10 \\
40
\end{bmatrix}
$$

* **y = B⁻¹·a₅** =

$$
y = 
\begin{bmatrix}
2/7 \\
0 \\
1 \\
0
\end{bmatrix}
$$

Apply **minimum ratio test**:
Min { (30/7)/(2/7), 10/1 } = 10 → pivot row = 3 → **a₃ leaves**

---

## 🟦 Phase 1 – Add a₅, Remove a₃

New basis:
**B = {a₁, a₂, a₅, a₄}**

Update $B^{-1}$: only first row changes

$$
B^{-1} =
\begin{bmatrix}
1/7 & 0   & -1/7 & 0 \\
0   & 1/4 &  0   & 0 \\
0   & 0   & 1/2  & 0 \\
0   & 0   & 0    & 1/2 \\
\end{bmatrix}
$$

---

### 🔢 Step 5: Compute π again

$$
π = [1, 1, 1, 1] \cdot B^{-1} = [1/7, 1/4, 5/14, 1/2]
$$

---

### 🔢 Step 6: Solve Slave Problem Again

Try all feasible patterns with new prices:

Best: **a₆ = (0, 3, 1, 0)**
→ 3×3 + 5 = 14
→ Value = 3×1/4 + 5/14 − 1 = 3/4 + 5/14 − 1 = > 0 → **profitable**

---

### 🔢 Step 7: Compute x\_B and y

$$
x_B = 
\begin{bmatrix}
10/7 \\
50/4 \\
10 \\
40
\end{bmatrix}
\quad
y = 
\begin{bmatrix}
-1/7 \\
3/4 \\
1/2 \\
0
\end{bmatrix}
$$

Min ratio test:

Min { (50/4)/(3/4), 10/(1/2) } = 50/3 → pivot row = 2 → **a₂ leaves**

---

## 🟦 Phase 2 – Add a₆, Remove a₂

New basis:
**B = {a₁, a₆, a₅, a₄}**

Update $B^{-1}$:

$$
B^{-1} =
\begin{bmatrix}
1/7 & 1/21 & -1/7 & 0 \\
0   & 1/3  & 0    & 0 \\
0   & -1/6 & 1/2  & 0 \\
0   & 0    & 0    & 1/2 \\
\end{bmatrix}
$$

---

### 🔢 Step 8: Compute π Again

$$
π = [1, 1, 1, 1] \cdot B^{-1} = [1/7, 3/14, 5/14, 1/2]
$$

---

### 🔢 Step 9: Final Slave Problem

All gain/weight ratios now equal (1/14), so **no better column exists**, reduced cost = 0 → **optimal**

---

## 🟩 Final Step: Compute Real Solution

$$
x_B = B^{-1} \cdot b = (80/21, 50/3, 5/3, 40)
\Rightarrow z^* \approx 62.14
\Rightarrow \text{round up to } \boxed{63}
$$

Try rounding x\_B to integers:

**x = (4, 17, 2, 40)** → Sum = 63 ✅

---

## ✅ Final Cutting Plan

| Pattern | Times Used | Description                          |
| ------- | ---------- | ------------------------------------ |
| a₁      | 4          | 4×7 of size-2 = 28                   |
| a₆      | 17         | 17×(3×3, 1×5) = 51 size-3, 17 size-5 |
| a₅      | 2          | 2×(2×2, 2×5) = 4 size-2, 4 size-5    |
| a₄      | 40         | 2×40 of size-7 = 80                  |

**Total produced**:

* Size 2: 28 + 4 = **32** (need 30)
* Size 3: **51** (need 50)
* Size 5: 17 + 4 = **21** (need 20)
* Size 7: **80** (need 80)

All demands are fulfilled, some slightly over.

---

Would you like to see this solved computationally in Python or C++?









Here's the final cutting plan shown in a structured table. Next, I will implement the full Gomory-Gilmore cutting stock problem solver in **C++**, including the steps for:

* storing item sizes and demands
* managing patterns (columns)
* solving the master and slave problems iteratively
* updating the basis and computing dual prices
* rounding the final solution

Would you like me to proceed with the C++ implementation now?







```cpp

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

struct Pattern {
    vector<int> items; // how many of each item size
};

const int STOCK_LENGTH = 14;
const vector<int> itemSizes = {2, 3, 5, 7};
const vector<int> demands = {30, 50, 20, 80};
const double EPSILON = 1e-6;

// Initial patterns: trivial ones
vector<Pattern> initialPatterns() {
    vector<Pattern> patterns;
    for (int i = 0; i < itemSizes.size(); ++i) {
        vector<int> pattern(itemSizes.size(), 0);
        pattern[i] = STOCK_LENGTH / itemSizes[i];
        patterns.push_back({pattern});
    }
    return patterns;
}

// Dual prices: set as 1 / length of item in the pattern (since B^-1 is identity initially)
vector<double> getDualPrices(const vector<Pattern>& basis) {
    vector<double> pi(itemSizes.size(), 0.0);
    for (int i = 0; i < itemSizes.size(); ++i) {
        double total = 0.0;
        for (const auto& p : basis)
            total += p.items[i];
        pi[i] = total > 0 ? 1.0 / total : 0.0;
    }
    return pi;
}

// Solve slave problem: knapsack-like brute-force generation
Pattern generatePattern(const vector<double>& pi, double& reducedCost) {
    vector<int> best(itemSizes.size(), 0);
    double bestValue = -numeric_limits<double>::infinity();
    reducedCost = 0.0;

    for (int i2 = 0; i2 <= STOCK_LENGTH / itemSizes[0]; ++i2) {
        for (int i3 = 0; i3 <= STOCK_LENGTH / itemSizes[1]; ++i3) {
            for (int i5 = 0; i5 <= STOCK_LENGTH / itemSizes[2]; ++i5) {
                for (int i7 = 0; i7 <= STOCK_LENGTH / itemSizes[3]; ++i7) {
                    int totalLength = i2*2 + i3*3 + i5*5 + i7*7;
                    if (totalLength > STOCK_LENGTH) continue;
                    double value = i2*pi[0] + i3*pi[1] + i5*pi[2] + i7*pi[3];
                    if (value > bestValue) {
                        bestValue = value;
                        best = {i2, i3, i5, i7};
                    }
                }
            }
        }
    }

    reducedCost = bestValue - 1.0;
    return {best};
}

void printPattern(const Pattern& p) {
    for (int v : p.items) cout << setw(3) << v;
    cout << "\n";
}

bool isSamePattern(const Pattern& a, const Pattern& b) {
    return a.items == b.items;
}

int main() {
    vector<Pattern> basis = initialPatterns();

    cout << "Initial Basis Patterns:\n";
    for (const auto& p : basis) printPattern(p);

    while (true) {
        auto pi = getDualPrices(basis);

        double reducedCost;
        Pattern newPattern = generatePattern(pi, reducedCost);

        if (reducedCost < EPSILON) {
            cout << "\nNo improving pattern found. Optimal basis achieved.\n";
            break;
        }

        bool alreadyExists = false;
        for (const auto& p : basis) {
            if (isSamePattern(p, newPattern)) {
                alreadyExists = true;
                break;
            }
        }

        if (!alreadyExists) {
            basis.push_back(newPattern);
            cout << "\nAdded new pattern with reduced cost = " << reducedCost << ":\n";
            printPattern(newPattern);
        } else {
            cout << "\nDuplicate pattern found. Stopping.\n";
            break;
        }
    }

    cout << "\nFinal Set of Patterns:\n";
    for (const auto& p : basis) printPattern(p);

    return 0;
}

```