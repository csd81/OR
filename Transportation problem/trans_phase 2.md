Here's the cleaned **Markdown version** of the document titled **Transportation problem, Phase II**, preserving the structure and explanations:

---

# Transportation problem, **Phase II**

### This was (and still this is) the problem:

Fill in the cells so that:

* The sum is OK in each row and column
* The total cost is **minimum**

---

|    | D1 | D2 | D3 | D4 | Supply |
| -- | -- | -- | -- | -- | ------ |
| S1 | 1  | 5  | 8  | 4  | 18     |
| S2 | 2  | 3  | 5  | 1  | 13     |
| S3 | 1  | 4  | 2  | 5  | 42     |
| S4 | 3  | 7  | 6  | 6  | 58     |
|    | 34 | 15 | 22 | 60 |        |

---

We solve it in **2 phases**:

### Phase 1:

We already determined a feasible basic solution (with `4 + 4 - 1 = 7` cells used).

### Phase 2:

Starting from the given feasible basic solution, we will reach the optimal solution (by performing basis transformations).

---

## Optimality Test (Using Potentials)

We define `u₁, ..., u₄` for rows and `v₁, ..., v₄` for columns.

**Condition:**
For every *basis cell* $(i,j)$, the relation
`uᵢ + vⱼ = c(i,j)`
must hold.

You can choose one value freely (e.g., `u₁ = 0`) and solve for others using this system.

---

## Reduced Costs:

For each non-basic cell $(i,j)$, the **reduced cost** is:

```
r(i,j) = c(i,j) - (uᵢ + vⱼ)
```

If **all reduced costs ≥ 0**, the solution is **optimal**.

---

## Optimization Step (If Any Reduced Cost < 0):

* Choose the cell with the **most negative reduced cost**
* Form a **closed loop (cycle)** using only basis cells
* **Alternate + / -** assignments along the loop
* The minimum value on the negative positions determines how much we can adjust
* Apply the adjustment: Increase at `+` positions, decrease at `-` positions

Repeat this process until all reduced costs are non-negative.

---

## Summary of Phase II (Optimization Procedure)

1. Start with a **basic feasible solution** (using `m+n-1` allocations).
2. Compute **potentials** $uᵢ, vⱼ$ such that:
   $uᵢ + vⱼ = c(i,j)$ for each basic cell.
3. Compute **reduced costs** for non-basic cells:
   $r(i,j) = c(i,j) - (uᵢ + vⱼ)$
4. If all $r(i,j) ≥ 0$, you're done (optimal solution).
5. Else:

   * Choose the **most negative** reduced cost
   * Find a **cycle** through basic cells including that cell
   * Apply **+/-** adjustment along the loop
   * Update the tableau and repeat

---

If you'd like, I can simulate the full step-by-step optimization process on this specific transportation matrix in code or tables. Let me know!



Here's the Markdown conversion of the page you've uploaded, preserving both the **layout** and the **explanation**:

---

## We got this tableau (by Vogel-Korda)

* which seems very good, but
* we do not know yet whether it is optimal or not.

|    | v1     | v2     | v3     | v4     |
| -- | ------ | ------ | ------ | ------ |
| u1 | 1      | 5      | 8      | 4      |
|    | **18** |        |        |        |
| u2 | 2      | 3      | 5      | 1      |
|    |        |        |        | **13** |
| u3 | 1      | 4      | 2      | 5      |
|    | **5**  | **15** | **22** |        |
| u4 | 3      | 7      | 6      | 6      |
|    | **11** |        |        | **47** |

---

### **The next slave algorithm** will help:

Find the values of `u₁, ..., u₄` and `v₁, ..., v₄` so that:

* `uᵢ + vⱼ = c(i,j)` for each **basis cell (i,j)**

---

### 📌 **Claim:**

If we have a basic solution, then the above system of linear equations **does have a solution**,
and the **degree of freedom is exactly 1**.

So, we can **freely choose one variable**.
Let’s set: `u₁ = 0`

Then, the further variables will be determined by a **path-searching algorithm**, as follows:

---

### 🔁 **Repeat:**

* Find a **basis cell**, for which one variable is already determined, the other is not
* Calculate the value of the other one

**End**

---

Let me know if you want to **compute the potentials and reduced costs** based on this tableau!





Here is the **Markdown version** of the new page you've uploaded, showing the **potential values**, **reduced costs**, and **optimality test**:

---

### This is what we get:

|             | **v1 = 1** | **v2 = 4** | **v3 = 2** | **v4 = 4** |       |
| ----------- | ---------- | ---------- | ---------- | ---------- | ----- |
| **u1 = 0**  | **18**     | 5          | 8          | 4          |       |
|             |            |            | **1**      | **6**      | **0** |
| **u2 = -3** | 2          | 3          | 5          | **13**     |       |
|             |            | 4          | 2          | 6          |       |
| **u3 = 0**  | **5**      | **15**     | **22**     | 5          |       |
| **u4 = 2**  | **11**     | 7          | 6          | **47**     |       |
|             |            | **1**      | **2**      |            |       |

---

### ✅ The solution is unique (if `u₁ = 0`)

---

### Next: Determine the **reduced cost**:

For each **cell (i,j)**, compute:

```
reduced_cost(i,j) = c(i,j) - (uᵢ + vⱼ)
```

* We place this value in the **bottom-right corner** of the cell.
* For **basic cells**, the reduced cost is always **0** (not shown).

---

### 📌 Theorem:

If **all reduced costs ≥ 0**, the **current solution is optimal**.

---

### ✔️ So:

* Our solution **is currently optimal**
* ❗ However, **this does not imply** that the result of Vogel-Korda is **always** optimal!

---

Let me know if you'd like to continue with an example of a **non-optimal solution** and how to **improve it via pivoting/cycling**.


Here's the **Markdown-formatted** version of the example from the uploaded page, preserving structure and explanatory content:

---

## 🔁 Let us start a **new example**!

Suppose we are **already done with Phase I**, and we assume the following is a **feasible basic solution**
(*no matter how we got it*).

---

### Step 1: Check the **slave variables**

* Then check the **reduced cost components**.

  * If positive → mark as **`+`**
  * If negative → write the actual value (room for improvement)

---

### Cost and Reduced Cost Table

|       | **6**   | **2**  | **−1** | **0**          |
| ----- | ------- | ------ | ------ | -------------- |
| **0** | 1       | 2      | 3      | 1              |
|       | **-5**  | **8**  | **+**  | **+**          |
| **6** | 1       | 1      | 5      | 6              |
|       | **-11** | **-7** |        | **4** / **10** |
| **2** | 1       | 4      | 1      | 5              |
|       | **-7**  | **12** | **21** | **+**          |
| **2** | 8       | 7      | 6      | 2              |
|       | **15**  |        | **+**  | **2**          |

---

### ✅ Interpretation

* If **all reduced costs are `+` or `0`**, the solution is **optimal**.
* ❌ But now, we have **negative entries**:
  ⇒ This means the solution **can be improved**!

---

### ❓ How?

We need some definitions:

* **Edge**: Two cells that are in a common row or column
* **Path**: A sequence of adjacent edges:
  horizontal → vertical → horizontal → …
* **Cycle**: A path that ends where it started

---

### 📐 Theorem (on cycles):

> Starting from **any non-basic cell**, there is **exactly one cycle** that visits **only basic cells**
> (except the starting/ending point)

✅ This holds **only** if the basic cells form a valid system.

---

### 🧩 Let’s find such cycles!

Ready for the next page? I can also simulate the step-by-step improvement (cycle pivoting) in code or diagram if you'd like.







Here's the **Markdown version** of the latest page you uploaded, preserving the **transportation tableau**, **cycle structure**, and the **explanatory text**:

---

### 🔁 Let us find a cycle

We start (and end) at cell **(2,2)** — marked with **X**.

---

### Tableau with Cycle Highlighted

|       | **6**   | **2** | **−1** | **0** |                |
| ----- | ------- | ----- | ------ | ----- | -------------- |
| **0** | 1       | 2     | 3      | 1     |                |
|       | **−5**  | **8** | **+**  | **+** |                |
| **6** | 1       | **X** | 5      | 6     |                |
|       | **−11** |       | **−7** |       | **4** / **10** |
| **2** | 1       | 4     | 1      | 5     |                |
|       | **−7**  |       | **12** |       | **21**         |
| **2** | 8       | 7     | 6      | 2     |                |
|       | **15**  |       | **+**  | **+** |                |

---

### ✅ **Claim**:

If we **alternatively reduce/increase** the transported volume by **1 unit** along the cycle,
we gain the amount of the **reduced cost**.

---

### 💡 What this means:

* This transformation is **advantageous**
* Modifying 1 unit: gain = **7**
* Modifying 2 units: gain = **2 × 7 = 14**
* And so on…
* But we **cannot modify more than 4 units**!
* 🔚 **So, by this transformation, the gain is:** `4 × 7 = 28` (dollars)

---

Let us explore **another improvement option** next!

Let me know if you'd like to simulate the pivot operation or visualize the full improvement step.









Here is the **Markdown version** of the latest page you uploaded, maintaining both the **tableau layout** and the **step-by-step logic** of the improvement calculation:

---

## 🔄 Let us see another option

Starting the cycle from **cell (1,1)**, marked as **X**:

---

### Tableau with Marked Cycle

|       | **6**  | **2** | **−1** | **0** |        |
| ----- | ------ | ----- | ------ | ----- | ------ |
| **0** | **X**  | 2     | 3      | 1     |        |
|       |        | **8** | **+**  | **+** |        |
| **6** | 1      | 1     | **28** | 5     | 6      |
|       |        |       | **4**  |       | **10** |
| **2** | 1      | 4     | 1      | 5     |        |
|       | **12** |       | **21** |       |        |
| **2** | 8      | 7     | 6      | 2     |        |
|       | **15** |       | **+**  | **2** |        |

---

### 🔍 Analysis of the Cycle

* **We can modify by at most: 8 units**

**How do we get that?**

> These are the transported volumes along the **cycle**:
> `X, 8, 12, 21, 4, 10, 2, 15, X`

> In the improvement cycle, **every second value is increasing**, the rest are decreasing.
> So only the **odd-numbered (1st, 3rd, 5th, 7th, …)** values matter for the **minimum constraint**.

### ➤ Important values:

* Extract the **odd-indexed volumes**:
  `8, 21, 10, 15`

* Take the **minimum** among these:
  **min{8, 21, 10, 15} = 8**

---

### ✅ Result:

We can modify by 8 units.
Reduced cost for the starting cell = **5**

So the gain is:
**8 × 5 = 40**

---

Let me know if you'd like to explore the **next cycle** option or simulate this improvement step-by-step!






Here is the **Markdown version** of the latest tableau and explanation, based on the cycle that starts at cell (3,1):

---

## 🔄 Let us see one more option

Start the cycle at **cell (3,1)** (marked with **X**)

---

### Tableau with Cycle Path

|       | **6**  | **2**   | **−1** | **0**  |       |        |
| ----- | ------ | ------- | ------ | ------ | ----- | ------ |
| **0** | 1      | **40**  | 2      | 3      | 1     |        |
|       |        | **−5**  |        | **+**  | **+** |        |
| **6** | 1      | **110** | 1      | **28** | 5     | 6      |
|       |        |         |        | **4**  |       | **10** |
| **2** | **X**  | 4       | 1      | 5      |       |        |
|       | **12** |         | **21** |        |       |        |
| **2** | 8      | 7       | 6      | 2      |       |        |
|       | **15** |         | **+**  | **2**  |       |        |

---

### 📌 Observations:

* The **cycle does not contain cell (3,2)** ❌

* The values along the cycle path:
  `X → 15 → 10 → 21 → X`

* Take the **minimum** of the relevant decreasing volumes:
  **min{15, 10, 21} = 10**

---

### ✅ Result:

* Gain = **10 × 7 = 70**

---

### 📈 Comparison:

If we instead start at **cell (2,1)**,

* Reduced cost = **11**
* Gain = **10 × 11 = 110**

---

### Summary:

We are evaluating multiple improvement cycles and comparing **maximum gain**.
Let’s summarize all the candidate transformations next (as done in the upcoming page).

Let me know if you'd like a **table comparing all gains** or if you'd like to **perform the best transformation** step-by-step.








Here's the **Markdown version** of the last page you uploaded, summarizing the greedy improvement choice and the planned transformation:

---

## 🔽 Evaluation of Improvement Options

### Tableau Before Applying Greedy Transformation:

|       | **6**  | **2**   | **−1** | **0**  |       |        |
| ----- | ------ | ------- | ------ | ------ | ----- | ------ |
| **0** | 1      | **40**  | 2      | 3      | 1     |        |
|       |        | **−5**  |        | **+**  | **+** |        |
| **6** | 1      | **110** | 1      | **28** | 5     | 6      |
|       |        |         |        | **4**  |       | **10** |
| **2** | 1      | **105** | 4      | 1      | 5     |        |
|       | **12** |         | **21** |        |       |        |
| **2** | 8      | 7       | 6      | 2      |       |        |
|       | **15** |         | **+**  | **2**  |       |        |

---

### ✅ Four Improvement Options Exist

We can select **any**, but let’s choose the one that gives the **highest gain**
→ This is a **greedy choice**

---

### 💡 **Best Option:**

* Start at **cell (2,1)**
  → Gain = **10 × 11 = 110**

---

### 🔧 Transformation Steps (Δ = 10 units):

* ➕ Increase **(2,1)** by **10**
* ➖ Decrease **(4,1)** by **10**
* ➕ Increase **(4,4)** by **10**
* ❌ **(4,1)** leaves the basis (after reducing by 10 again)

---

### 📌 Result:

This pivot will result in a **new tableau** (to be shown on the next page), and potentially move us closer to the optimal solution.

Let me know if you'd like me to reconstruct the new tableau after this transformation or walk through the pivot update process.





Here is the **Markdown version** of the post-transformation tableau and its explanation:

---

## ✅ Tableau After the Transformation

|        | **−5** | **2**  | **−1** | **−11** |        |   |
| ------ | ------ | ------ | ------ | ------- | ------ | - |
| **0**  | 1      | 2      | 3      | 1       |        |   |
|        | **+**  |        | **8**  | **+**   | **+**  |   |
| **6**  | 1      | 1      | **28** | 5       | 6      |   |
|        | **10** |        |        |         | **4**  |   |
|        |        | **−7** |        |         | **+**  |   |
| **2**  | 1      | 4      | 1      | 5       |        |   |
|        |        | **12** |        | **21**  |        |   |
|        | **+**  |        |        | **+**   |        |   |
| **13** | 8      | 7      | **32** | 6       | 24     | 2 |
|        | **5**  |        | **X**  |         | **12** |   |
|        |        | **−8** |        | **−6**  |        |   |

---

### 📌 Notes

* ✅ **Slave variables** have already been updated after the transformation.
* ⚠️ **Reduced cost values** show multiple **negative components** still exist.
* 👉 **Next pivot** should occur in **cell (4,2)** (since it has a reduced cost of **−8**).

---

Would you like to walk through this next pivot as well, or summarize the remaining steps to reach optimality?







Here is the **final Markdown summary** of the last tableau and the conclusion of the second phase of the transportation problem:

---

## 🔄 Tableau After the Latest Transformation

*(Performed by adding and reducing 4 units alternately)*

|        | **3**  | **2** | **−5** | **−3** |   |
| ------ | ------ | ----- | ------ | ------ | - |
| **0**  | 1      | 2     | 2      | 3      | 1 |
|        | **−2** | **8** | **+**  | **+**  |   |
| **−2** | 1      | 1     | 5      | 6      |   |
|        | **14** |       | **+**  | **+**  |   |
| **6**  | 1      | **8** | 4      | 1      | 5 |
|        | **8**  |       | **25** |        |   |
|        | **−8** |       | **+**  |        |   |
| **5**  | 8      | 7     | 6      | 2      |   |
|        | **1**  | **4** |        | **12** |   |
|        |        |       | **+**  |        |   |

---

## 🔎 Observations

* There is **still room to improve** (e.g., **cell (3,1)** with reduced cost = −8)
* However, **gains are getting smaller**

---

## 📌 Summary of the Second Phase

### Step-by-step process:

1. **Start from a feasible basic solution**
   (which uses exactly `m + n − 1` cells, e.g., `4 + 4 − 1 = 7`)
2. **Repeat** the following steps:

   * Determine **slave variables** (`uᵢ`, `vⱼ`)
   * Compute the **reduced cost** for each non-basic cell:

     ```
     r(i,j) = c(i,j) - (uᵢ + vⱼ)
     ```
   * If **all reduced costs ≥ 0** → ✅ optimal solution
   * If **any reduced cost < 0** → improve the solution:

     * Choose a **cell with the most negative reduced cost** (Greedy strategy)
     * Find the **cycle** through the basis
     * Apply a **+/- adjustment** along the cycle (min value on negative positions)
     * **Update** the tableau

---

Let me know if you'd like to generate the **final solution matrix** or calculate the **total minimum cost** from this optimal tableau!







