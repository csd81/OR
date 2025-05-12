# Operations Research

The slide you've uploaded introduces **Operations Research (OR)** as a subfield of **Optimization Methods**. Here's a summarized and clear breakdown:

---

### 📘 What is Operations Research?

- **OR is a part of Optimization Methods.**
- It focuses on **decision making** and **problem-solving** using mathematical models, statistics, and algorithms.
- It's used to find optimal or near-optimal solutions to complex decision-making problems.

---

### 📚 Recommended Reading

- **Wayne L. Winston**, *Operations Research: Applications and Algorithms*, Duxbury Press, 1991, 2nd edition.  
  ISBN: **0-534-92495-6**

This book is considered a standard reference in the field, covering a wide range of models and methods.

---

### 🌐 Additional Resources

- Hungarian digital textbook library: [https://www.tankonyvtar.hu/hu/tartalom/](https://www.tankonyvtar.hu/hu/tartalom/)
- Wikipedia entry for OR: [Operations Research – Wikipedia](https://en.wikipedia.org/wiki/Operations_research)

---

Would you like a deeper explanation of any OR topic such as **Linear Programming**, **Simplex Method**, or **Decision Analysis**?


**TL;DR:**

- **Linear Programming (LP)** is a key method in **Operations Research** for optimizing problems with linear constraints.
- Invented by **George Dantzig** in **1947** via the **Simplex Method**.
- The next part shows how to solve a basic production problem using this method.

**TL;DR:**

- **Linear Programming (LP)** is a key method in **Operations Research** for optimizing problems with linear constraints.
- Invented by **George Dantzig** in **1947** via the **Simplex Method**.
- The next part shows how to solve a basic production problem using this method.

### 🏭 TL;DR — Production Model (Simplex Setup)

- There are **5 products (P₁ to P₅)** and **3 resources (Res₁ to Res₃)**.
- Each product consumes certain units of each resource.
- Each resource has a limited **capacity**:  
  - Res₁: 24 units  
  - Res₂: 43 units  
  - Res₃: 18 units
- The **profit per unit** for each product:  
  P₁ = 19, P₂ = 23, P₃ = 15, P₄ = 42, P₅ = 33
- Goal: **Choose how many units to produce** of each product to **maximize profit**, while staying within resource limits.

➡️ This is the setup for applying the **Primal Simplex Method** in Linear Programming.

Here is the production problem data in table format:

|         | **P₁** | **P₂** | **P₃** | **P₄** | **P₅** | **Capacity** |
|---------|--------|--------|--------|--------|--------|--------------|
| **Res₁** |   1    |   2    |   1    |   3    |   0    |     24       |
| **Res₂** |   0    |   1    |   1    |   5    |   1    |     43       |
| **Res₃** |   1    |   0    |   0    |   2    |   2    |     18       |
| **Profit** | 19 | 23 | 15 | 42 | 33 |              |

Let me know if you want this turned into equations or a simplex tableau!

Here’s a concise breakdown of the slide:

---

### 🏭 **Production Model – Key Concepts**

- **Factory setup**:  
  - Produces several products: \( P_1, P_2, P_3, P_4, P_5 \)  
  - Uses **three resources**: \( \text{Res}_1, \text{Res}_2, \text{Res}_3 \)

- **Example explained**:  
  Producing **1 unit of \( P_4 \)** uses:  
  - 3 units of Res₁  
  - 5 units of Res₂  
  - 2 units of Res₃  
  ➡️ Yields a **profit of 42**

- **Profit calculation**:  
  If the production plan is \( x = (0, 8, 0, 1, 0) \)  
  And profit vector is \( c = (19, 23, 15, 42, 33) \)  
  Then total profit =  
  \[
  c \cdot x = 19 \cdot 0 + 23 \cdot 8 + 15 \cdot 0 + 42 \cdot 1 + 33 \cdot 0 = 226
  \]

- **Objective**:  
  Maximize profit **while staying within the resource limits**.

---

Let me know if you'd like this converted into LP constraints or Simplex tableau form!

Here's the table and the test production plans shown on the slide:

---

### 📊 **Production Table**

|         | **P₁** | **P₂** | **P₃** | **P₄** | **P₅** | **Capacity** |
|---------|--------|--------|--------|--------|--------|--------------|
| **Res₁** |   1    |   2    |   1    |   3    |   0    |     24       |
| **Res₂** |   0    |   1    |   1    |   5    |   1    |     43       |
| **Res₃** |   1    |   0    |   0    |   2    |   2    |     18       |
| **Profit** | 19 | 23 | 15 | 42 | 33 |              |

---

### 🧪 **Test Production Plans and Profit Calculations**

| Plan | Production Vector \(x = (P₁, P₂, P₃, P₄, P₅)\) | Profit \(z\) |
|------|-----------------------------------------------|-------------|
| a    | (18, 0, 0, 0, 0)                              | \(18×19 = 342\) |
| b    | (0, 12, 0, 0, 0)                              | \(12×23 = 276\) |
| c    | (0, 0, 24, 0, 0)                              | \(24×15 = 360\) |
| d    | (0, 0, 0, 8, 0)                               | \(8×42 = 336\)  |
| e    | (0, 0, 0, 0, 9)                               | \(9×33 = 297\)  |
| f    | (18, 3, 0, 0, 0)                              | \(18×19 + 3×23 = 411\) |
| g    | (0, 0, 24, 0, 9)                              | \(24×15 + 9×33 = 657\) |

---

### ❓ Conclusion:
- Plan **g** gives the **highest profit** so far: **657**
- Question: *Is it optimal, or is there a better plan?*

This is the lead-in to solving it **systematically using the Simplex Method**. Want to walk through that next?

Here’s a **clear summary of the definitions and examples** from the slide:

---

### ✅ **Definitions**

- **Solution**:  
  A vector \( x \) is a **solution** if it satisfies all the **constraints**.

- **Feasible Solution**:  
  A solution is **feasible** if \( x \geq 0 \).  
  (i.e., all values are non-negative and still satisfy the constraints.)

- **Optimal Solution**:  
  A **feasible solution** that gives the **maximum profit** among all feasible solutions.

---

### 🧮 **Table of Coefficients (Repeated)**

|         | **P₁** | **P₂** | **P₃** | **P₄** | **P₅** | **Capacity** |
|---------|--------|--------|--------|--------|--------|--------------|
| **Res₁** |   1    |   2    |   1    |   3    |   0    |     24       |
| **Res₂** |   0    |   1    |   1    |   5    |   1    |     43       |
| **Res₃** |   1    |   0    |   0    |   2    |   2    |     18       |
| **Profit** | 19 | 23 | 15 | 42 | 33 |              |

---

### 🧪 **Examples**

| Vector \( x \)              | Is it a solution? | Is it feasible? | Notes |
|-----------------------------|-------------------|------------------|-------|
| \( (-1, 1, 1, 1, 1) \)      | ✅ Yes             | ❌ No             | Negative component |
| \( (10, 10, 0, 0, 0) \)     | ❌ No              | ✅ Yes            | Exceeds capacity |
| \( (5, 1, 1, 0, 0) \)       | ✅ Yes             | ✅ Yes            | Feasible solution |

---

👉 At this point in the lecture, the method to **find the optimal solution** (e.g. using **Simplex**) hasn’t been introduced yet — it’s coming next!

Want to jump into how the Simplex method solves this?

This slide sets up the motivation for applying the **Simplex Method**:

---

### 🔍 **How to Find a Feasible/Optimal Solution?**

1. **Does an optimal solution even exist?**
2. **If it does, how many solutions are there?**
3. **How do we find one (or all)?**

---

### 💡 Method:
- One powerful approach: **(Primal) Simplex Method**  
- It will be introduced briefly in the next slides.

---

### ⚠️ Heads-up:
> **This will be the first exercise in the mid-test!!!!!**

So definitely worth learning how to apply the Simplex method correctly.  
Want to continue with a Simplex step-by-step example next?

This slide formally introduces the **Linear Programming (LP)** problem structure using standard mathematical notation:

---

### 📘 **Linear Programming Notation**

- **Coefficient matrix** \( A \):  
  Describes how much each product uses each resource.

- **Right-hand side vector** \( b \):  
  The **capacity limits** of the resources.

- **Profit (objective) vector** \( c \):  
  Profit per unit of each product.

---

### 🧮 **General LP Form**

\[
\begin{aligned}
Ax &\leq b \quad \text{(constraints)} \\
x &\geq 0 \quad \text{(non-negativity)} \\
z &= c \cdot x \to \max \quad \text{(maximize profit)}
\end{aligned}
\]

---

This structure sets up for the **Simplex Method**, which will solve the LP by moving from one vertex (feasible solution) to a better one until the optimal is reached.

Want to go through the detailed form next (as hinted in the last line)?

This slide gives the **full mathematical formulation** of the linear programming problem based on the production model.

---

### 🔧 **Detailed Linear Program (LP) Formulation**

#### **Constraints (from resource limits):**

\[
\begin{align*}
x_1 + 2x_2 + x_3 + 3x_4 &\leq 24 \quad \text{(Res₁)} \\
x_2 + x_3 + 5x_4 + x_5 &\leq 43 \quad \text{(Res₂)} \\
x_1 + 2x_4 + 2x_5 &\leq 18 \quad \text{(Res₃)} \\
x_i &\geq 0 \quad \text{for } i = 1, \dots, 5
\end{align*}
\]

#### **Objective Function (maximize profit):**

\[
z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5 \rightarrow \max
\]

---

This formulation is now **ready for solving** using the **Simplex Method**.  
Want to move on to the **Simplex tableau setup** or go through the steps of the **Primal Simplex Method** next?


This slide shows the **first step** in solving the Linear Program using the **Primal Simplex Method**:

---

### 🪛 Step 1: Convert Inequalities to Equalities  
We introduce **slack variables** \( s_1, s_2, s_3 \) to transform the “≤” constraints into equalities:

#### ✅ **Slack Form (Standard Form)**

\[
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4 + s_1 &= 24 \\
x_2 + x_3 + 5x_4 + x_5 + s_2 &= 43 \\
x_1 + 2x_4 + 2x_5 + s_3 &= 18
\end{aligned}
\]

With the **non-negativity constraints**:

\[
x \geq 0, \quad s \geq 0
\]

---

### 🎯 Objective Function (to Maximize):

\[
z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5
\]

---

Now the system is in a form suitable for **Simplex tableau construction**. Want to build the initial tableau next?

Here's a breakdown of the slide introducing the **Simplex Tableau** — a compact format to solve LP problems:

---

### 🧮 **Simplex Tableau (Initial Form)**

| **B** | **xᴮ** | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|------|--------|----|----|----|----|----|----|----|----|
| u₁   | 24     | 1  | 2  | 1  | 3  | 0  | 1  | 0  | 0  |
| u₂   | 43     | 0  | 1  | 1  | 5  | 1  | 0  | 1  | 0  |
| u₃   | 18     | 1  | 0  | 0  | 2  | 2  | 0  | 0  | 1  |
| z    | 0      | -19 | -23 | -15 | -42 | -33 | 0 | 0 | 0 |

---

### 📘 **Explanation of Terms**

- **B** = Current **basis** = {u₁, u₂, u₃} (initially the slack variables)
- **xᴮ** = Values of the basic variables = (24, 43, 18)
- The bottom row (**z-row**) shows **reduced costs** (negative values indicate potential for profit increase if we pivot that variable into the basis)

---

### ✅ **Feasible Basic Solution**

From the tableau:
\[
x = (0, 0, 0, 0, 0 \mid 24, 43, 18)
\]
All decision variables \(x_i = 0\), and slack variables \(s_1 = 24\), \(s_2 = 43\), \(s_3 = 18\)

✔️ This solution satisfies all constraints and non-negativity  
❗ But it's not optimal — since the **z-row has negative values**, we can improve it

---

Want to proceed to the **first pivot step** of the Simplex Method?

This slide presents a **crucial theorem** in the **Simplex Method** that guides the algorithm's progress:

---

### 📘 **Simplex Theorem (Decision Rule)**

Exactly **one** of the following will occur when examining the **last row** (reduced costs \( z_j - c_j \)) of the simplex tableau:

#### a) **All entries are ≥ 0**  
✅ Then the current basic solution is **optimal**.

#### b) **A negative entry exists**, but its **entire column has no positive entries**  
❌ Then the solution is **unbounded** — the objective value can increase indefinitely.

#### c) **A negative entry exists**, and its column has **some positive entry**  
🔁 Then we can **pivot** (do a basis transformation) to improve the objective value (this is the normal case for next step).

---

### 📌 How to Apply It?

1. Look at the **last row** of the tableau (row \( z \)):
   - If all are ≥ 0 → ✅ Optimal.
   - If any negative, check:
     - Does that column have any **positive entries** in constraint rows?  
       - If **yes** → pivot there (entering variable).
       - If **no** → ❌ unbounded.

---

Let me know if you'd like to walk through this on your current tableau to pick the pivot column and row!

This slide explains how the **Primal Simplex Method (Phase 2)** works in practice:

---

### 🔄 **Simplex Method – Core Ideas**

- ✅ We **perform basis transformations** to move from one solution to a better one.

- ✅ We **maintain primal feasibility**:  
  All decision variables \( x_i \geq 0 \) 𝑥_𝑖 ≥0 — no negative values allowed!

- 🧮 This is ensured using the **Minimum Ratio Rule** during pivoting:
  - Select a pivot row such that the solution remains feasible.

---

### 🚩 When do we improve the solution?

- If a **reduced cost** (in the last row) is **negative**,  
  we **can increase the objective** by moving in that variable’s direction.

---

### 🛑 **When to Stop (Dual Feasibility)**

- If all reduced costs are **≥ 0** and current solution is feasible (i.e., \( x \geq 0 \)),  
  ➤ Then this solution is **optimal**.

---

### 🧠 Final Claim

> The Simplex Method is **finite** — if done smartly, it **converges quickly** in practice.

---

Let me know if you’d like to proceed with the next step of the algorithm (i.e., perform a pivot in the current tableau)!


This slide walks through the **first pivot step** in the **Simplex Method**, applying the **Minimum Ratio Rule**:

---

### 🔄 **Entering and Leaving Variable Decision**

- Suppose we pick **column \( a_2 \)** (corresponding to variable \( x_2 \)) to **enter the basis**.
- To determine which row leaves the basis, apply the **Minimum Rule**:

\[
\text{Compare: } \frac{24}{2}, \frac{43}{1}, \text{ skip row 3 (coefficient is 0)}
\]

\[
\Rightarrow \min\left(\frac{24}{2}, \frac{43}{1}\right) = \frac{24}{2} = 12
\]

✅ So **row 1** (value 24) is the **leaving vector**, and \( u_1 \) leaves the basis.

---

### ⚙️ Pivot Summary:

- **Entering variable**: \( x_2 \) (column \( a_2 \))
- **Leaving variable**: \( u_1 \)
- **Pivot element**: \( 2 \) (bolded in the tableau)

---

This is the first actual **pivot step** in the Primal Simplex algorithm.  
Would you like me to show how to update the tableau with this pivot?

This slide explains **how to perform the basis transformation (pivoting)** in the Simplex Method:

---

### 🔁 **Basis Transformation Steps**

Given:
- Pivot element = **2** (from row 1, column \( a_2 \))

#### 🔧 Row Operations:
1. **Normalize the pivot row**:
   - Divide the **entire row** by the pivot value (2)

2. **Update other rows**:
   - For row 2: subtract \( \frac{1}{2} \times \text{pivot row} \)  
     (since the \( a_2 \) coefficient in row 2 is 1)
   - For row 3: subtract \( \frac{0}{2} \times \text{pivot row} \)  
     (so no change needed here)
   - For the objective (z): add \( \frac{23}{2} \times \text{pivot row} \)  
     (because \( -23 \) is the reduced cost of \( a_2 \))

---

### 🧠 Tip:
The coefficient in each row's **pivot column** becomes the **numerator**,  
The **pivot value** is always the **denominator**.

This ensures **primal feasibility** and helps move toward an optimal solution.

---

Would you like me to show you the updated tableau (after these transformations)?

This slide shows the **result of the first pivot** and sets up for the second pivot:

---

### 🔁 **Before Pivot (Initial Tableau Recap)**

| B   | xᴮ | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|-----|----|----|----|----|----|----|----|----|----|
| u₁ | 24 | 1  | 2  | 1  | 3  | 0  | 1  | 0  | 0  |
| u₂ | 43 | 0  | 1  | 1  | 5  | 1  | 0  | 1  | 0  |
| u₃ | 18 | 1  | 0  | 0  | 2  | 2  | 0  | 0  | 1  |
| z  | 0  | -19| -23| -15| -42| -33| 0  | 0  | 0  |

---

### ✅ **After First Pivot (x₂ enters, u₁ leaves)**

| B   | xᴮ | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|-----|----|----|----|----|----|----|----|----|----|
| a₂ | 12 | 1/2| 1  | 1/2| 3/2| 0  | 1/2| 0  | 0  |
| u₂ | 31 | -1/2| 0| 1/2| 7/2| 1  | -1/2| 1| 0  |
| u₃ | 18 | 1  | 0  | 0  | 2  | 2  | 0  | 0  | 1  |
| z  |276 | -15/2| 0| -7/2| -15/2| -33| 23/2| 0| 0  |

---

### 📍Next Pivot Decision:

- **a₅** has the **most negative reduced cost** (−33), so **x₅ will enter**.
- Using the **minimum rule**, look at the ratios for \( a₅ \) column:
  - Row u₃: \( \frac{18}{2} = 9 \) (only valid positive denominator)

➡️ So: **x₅ enters**, and **u₃ leaves the basis**.

---

Would you like to see the next tableau (after this pivot)?


This slide shows the **second pivot result**, after variable \( a_5 \) entered and \( u_3 \) left the basis.

---

### ✅ **Before Pivot:**
| B   | xᴮ | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|-----|----|----|----|----|----|----|----|----|----|
| a₂ | 12 | 1/2| 1  | 1/2| 3/2| 0  | 1/2| 0  | 0  |
| u₂ | 31 | -1/2| 0| 1/2| 7/2| 1  | -1/2| 1| 0  |
| u₃ | 18 | 1  | 0  | 0  | 2  | 2  | 0  | 0  | 1  |
| z  |276 | -15/2| 0| -7/2| -15/2| -33| 23/2| 0| 0  |

---

### 🔁 **After Pivot (x₅ enters, u₃ leaves):**

| B   | xᴮ | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|-----|----|----|----|----|----|----|----|----|----|
| a₂ | 12 | 1/2| 1  | 1/2| 3/2| 0  | 1/2| 0  | 0  |
| u₂ | 22 | -1 | 0  | 1/2| 5/2| 0  | -1/2| 1| -1/2 |
| a₅ | 9  | 1/2| 0  | 0  | 1  | 1  | 0  | 0  | 1/2 |
| z  |573 | 9  | 0  | -7/2| 51/2| 0 | 23/2| 0| 33/2 |

---

### 🔎 What's next?

- Only one negative value remains in the objective row: **–7/2** under \( a_3 \)
  - So \( a_3 \) (i.e., \( x_3 \)) will **enter the basis**.
- Using the **Minimum Ratio Rule**, we find which variable will **leave the basis** next.

Want to continue with the next pivot or review the pivot rule in action?

This slide **summarizes the logic behind changes in the objective function** during the Simplex Method:

---

### 📈 **Effect of Column Choice on Objective Value**

1. **Negative entry in the objective row (reduced cost)**  
   ➤ Choosing this column to enter the basis will **increase the objective value**.  
   ✅ This is what we want when maximizing.

2. **Positive entry in the objective row**  
   ➤ Choosing it would **decrease the objective**,  
   ❌ So we **avoid** doing this in maximization problems.

3. **Zero in the objective row**  
   ➤ No change in the objective value occurs.

---

### ⚠️ Important Condition: **Non-degeneracy**

- The logic **only works reliably** if the **basic solution is non-degenerate**,  
  meaning **all basic variable values are strictly positive** (e.g., \( x_2, s_2, x_5 > 0 \)).

- If a basic variable is **zero**, the pivot might not change the solution,
  and the objective might **not improve**.

---

Up next, the slide promises to show **what happened after the last transformation** (pivot involving \( a_3 \)). Want to continue with that next tableau?


This slide presents the **final Simplex tableau** and announces the **optimal solution**:

---

### 🏁 **Final Tableau (After Pivot on \(a_3\))**

| B   | xᴮ | a₁ | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃ |
|-----|----|----|----|----|----|----|----|----|----|
| a₃ | 24 | 1  | 2  | 1  | 3  | 0  | 1  | 0  | 0  |
| u₂ | 10 | -3/2| -1| 0  | 1  | 0  | -1 | 1  | -1/2 |
| a₅ | 9  | 1/2| 0  | 0  | 1  | 1  | 0  | 0  | 1/2 |
| z  |657 |25/2| 7  | 0  |36  | 0  |15  | 0  |33/2 |

---

### ✅ **Optimal Solution Found!**

- **Basic variables**:  
  \[
  x_3 = 24, \quad x_5 = 9, \quad s_2 = 10
  \]

- **Non-basic (zero)**:  
  \[
  x_1 = x_2 = x_4 = s_1 = s_3 = 0
  \]

- **Maximum Profit**:  
  \[
  z_{\text{OPT}} = 657
  \]

📌 This matches the best value from earlier guesswork \( z = 24 \cdot 15 + 9 \cdot 33 = 657 \), now confirmed formally via the Simplex method.

---

Let me know if you’d like a recap of all pivot steps, or help trying another LP problem!


This final **evaluation slide** wraps up the problem and interprets the **optimal solution**:

---

### 🏆 **Optimal Solution Summary**

- **Solution vector**:
  \[
  x_B = (0, 0, 24, 0, 9 \mid 0, 10, 0)
  \]
  - Produce:
    - **24 units of product \(P_3\)**
    - **9 units of product \(P_5\)**
    - **No units of \(P_1, P_2, P_4\)**

- **Slack variables**:
  - **10 units of resource \(Res_2\)** remain unused
  - All other resources are **fully consumed**

- **Maximum profit (objective value)**:
  \[
  z_{\text{OPT}} = 657
  \]

---

### 💡 Insight

- The final result **matches the earlier "guessed" best plan**:  
  \( x = (0, 0, 24, 0, 9) \), which we originally tried manually.
- This shows that **greedy guesses can sometimes be optimal**,  
  but only the **Simplex Method** guarantees a correct solution.

---

Let me know if you’d like to try another example, visualize the result, or get a step-by-step Simplex summary!


This final slide gives a **clear summary of the Primal Simplex Method**:

---

### 📘 **Summary of Primal Simplex**

- ✅ We perform **basis transformations** at each step.
- ✅ We maintain **primal feasibility**:  
  All \( x_i \geq 0 \), but allow negative values in the reduced cost row.

- 🔽 We **select a column with a negative reduced cost**  
  → This ensures the **objective value increases**.

- 🛑 When **no negatives remain in the objective row**, we achieve:
  - **Dual feasibility**
  - ➕ Combined with primal feasibility ⇒ we have found the **optimal solution**.

---

### 📣 Final Note:
> **"Please do calculate several exercises!!!!!"**

Practicing multiple examples is key to mastering the Simplex method — want to try solving one now together?


Ez a dia az **Operációkutatás tantárgy tematikáját** mutatja be:

---

### 📘 **Tematika – Operációkutatás**

1. **Lineáris programozás**  
   (pl. Simplex-módszer, célfüggvény maximalizálása)

2. **Szállítási feladat**  
   (optimális elosztás, szállítási költség minimalizálása)

3. **Hozzárendelési feladat**  
   (pl. munkások feladatokhoz rendelése költség vagy idő alapján)

4. **(Némi) Játékelmélet**  
   (stratégiai döntések, nyereség-veszteség mátrixok)

5. **Diszkrét programozás**, azon belül:
   - 🎒 **Hátizsák feladat** (kapacitáskorlátos kiválasztás)
   - 🧳 **Utazó ügynök probléma** (legrövidebb útvonal keresése)

6. **Cutting Stock feladat**  
   (anyagoptimalizálás, pl. fémcsövek, papírgurigák szabása)

---

Ha szeretnéd, részletesen is elmagyarázom valamelyik témakört — melyik érdekel legjobban?

Ez a dia az **operációkutatás (OpKut)** történelmi hátterét mutatja be:

---

### 🕰️ **A kezdet – OpKut**

- 📌 **Hadműveleti Operációk Kutatása**  
  Az operációkutatás eredetileg katonai tervezéshez, logisztikai döntések támogatásához alakult ki (pl. 2. világháború alatt).

- 📈 **Lineáris programozás**  
  Később ipari és gazdasági optimalizálási problémákhoz is alkalmazni kezdték.

- 👨‍🏫 **George Dantzig**  
  A lineáris programozás egyik úttörője, a **szimplex módszer** megalkotója (1947).

---

A képen is ő látható – George Dantzig, akinek munkája megalapozta a modern optimalizálást.

Szeretnél egy rövid áttekintést a szimplex módszerről is?


Ez a dia egy **klasszikus lineáris programozási problémát**, egy **termelési optimalizálási feladatot** mutat be.

---

### 🏭 **Egy termelési probléma – Adott táblázat:**

|        | T₁ | T₂ | T₃ | T₄ | T₅ | Készlet |
|--------|----|----|----|----|----|---------|
| **Erőf₁** | 1  | 2  | 1  | 3  | 0  | 24      |
| **Erőf₂** | 0  | 1  | 1  | 5  | 1  | 43      |
| **Erőf₃** | 1  | 0  | 0  | 2  | 2  | 18      |
| **Haszon** | 19 | 23 | 15 | 42 | 33 |         |

---

### 📌 Mit jelent ez?

- **T₁–T₅**: Ötféle termék, amit előállíthatunk.
- **Erőf₁–Erőf₃**: Háromféle erőforrás (pl. gépidő, alapanyag, munkaóra).
- Az egyes számok azt mutatják, hány egységet használunk fel az adott erőforrásból, ha **1 egységet** gyártunk egy adott termékből.
- A "Haszon" sor a **termékenkénti nyereséget** mutatja.

---

### 🎯 **Cél**:  
Olyan gyártási tervet találni, amely:

- nem lépi túl az erőforrás-készleteket,
- és **maximalizálja az összes hasznot**.

---

Szeretnéd, hogy közösen felállítsuk a matematikai modellt vagy megoldjuk ezt a feladatot?

Ez a dia segít **megérteni a termelési modell logikáját** az előző táblázat alapján:

---

### 🧮 **Termelési modell alapelvei:**

- **Termékek**: \( T_1, T_2, ..., T_5 \)
- **Erőforrások**: 3 különböző típus (pl. gépidő, anyag, munkaóra)
- **Készlet**: Az elérhető mennyiség minden erőforrásból

---

### Példák:

- Ha **1 egységet** termelünk \( T_1 \)-ből → adott mennyiségű erőforrást fogyasztunk a táblázat szerint.
- Ha **8 egység \( T_2 \)** és **1 egység \( T_4 \)** → az 1. erőforrásból:
  \[
  8 \cdot 2 + 1 \cdot 3 = 19 \text{ egység fogy}
  \]

---

### 💡 **Termelési terv** példa:

- \( x = (0, 8, 0, 1, 0) \): azaz 8 egység \( T_2 \), 1 egység \( T_4 \)
- Haszonvektor \( c = (19, 23, 15, 42, 33) \)
- Összes haszon:
  \[
  c \cdot x = 23 \cdot 8 + 42 \cdot 1 = 184 + 42 = 226
  \]

---

### ❓ **A kérdés**:

> Mi lesz a „legjobb” termelési terv?  
> (Az, ami **nem lépi túl** az erőforrásokat, de **maximalizálja a hasznot**.)

Ez egy **lineáris programozási feladat**, amelyet a következő lépésekben a **szimplex módszerrel** fogunk megoldani.

Szeretnéd, hogy együtt beállítsuk a modell egyenleteit is?


Ez a dia azt szemlélteti, hogyan próbálhatunk ki különböző **termelési terveket** (produkciós vektorokat), hogy kiszámoljuk a hozzájuk tartozó **hasznot** (célfüggvény értéket).

---

### 📊 Próbálkozások (kézi becslés):

| Terv \(x\)                     | Z érték (haszon)   | Megjegyzés                      |
|-------------------------------|--------------------|----------------------------------|
| a: \( (18, 0, 0, 0, 0) \)     | \( z_1 = 18 \cdot 19 = 342 \) |
| b: \( (0, 12, 0, 0, 0) \)     | \( z_2 = 12 \cdot 23 = 276 \) |
| c: \( (0, 0, 24, 0, 0) \)     | \( z_3 = 24 \cdot 15 = 360 \) |
| d: \( (0, 0, 0, 8, 0) \)      | \( z_4 = 8 \cdot 42 = 336 \) |
| e: \( (0, 0, 0, 0, 9) \)      | \( z_5 = 9 \cdot 33 = 297 \) |
| f: **???**                    | **???** (keresett optimális terv?) |

---

### 🔍 Mi történik itt?

Ezek **egyszerű, egytermékes próbálkozások** – minden esetben csak egyetlen termékből gyártunk egy adott maximális mennyiséget (amennyit az erőforrások engednek).

Az „f” lehet egy **kombinált megoldás**, amely többféle terméket is tartalmaz, és **nagyobb összhasznot eredményez** – például:

\[
x = (0, 0, 24, 0, 9) \Rightarrow z = 24 \cdot 15 + 9 \cdot 33 = 360 + 297 = 657
\]

Ez az előző anyagok alapján a **valódi optimális megoldás** lesz.

---

Szeretnéd, hogy most lépésről lépésre végigmenjünk a teljes megoldási folyamaton a **szimplex módszerrel**?


Íme a dia alapján rekonstruált **termelési probléma táblázata** a próbálkozásokkal együtt:

---

### 📋 **Termelési probléma – erőforrás- és haszonmátrix**

|         | **T₁** | **T₂** | **T₃** | **T₄** | **T₅** | **Készlet** |
|---------|--------|--------|--------|--------|--------|-------------|
| **Erőf₁** | 1      | 2      | 1      | 3      | 0      | 24          |
| **Erőf₂** | 0      | 1      | 1      | 5      | 1      | 43          |
| **Erőf₃** | 1      | 0      | 0      | 2      | 2      | 18          |
| **Haszon** | 19     | 23     | 15     | 42     | 33     |             |

---

### ✅ **Próbálkozások és kiszámolt hasznok:**

| **Terv**              | **x**                     | **Haszon** (\(z\)) |
|-----------------------|---------------------------|---------------------|
| a                     | (18, 0, 0, 0, 0)          | 342                 |
| b                     | (0, 12, 0, 0, 0)          | 276                 |
| c                     | (0, 0, 24, 0, 0)          | 360                 |
| d                     | (0, 0, 0, 8, 0)           | 336                 |
| e                     | (0, 0, 0, 0, 9)           | 297                 |
| f                     | (0, 8, 0, 1, 0)           | 226                 |
| g (jobb megoldás)     | (0, 0, 24, 0, 9)          | **657**             |

---

Ha szeretnéd, ebből a kiindulópontból megmutathatom, hogyan néz ki a lineáris modell, vagy hogyan indítjuk el a **szimplex algoritmust**. Szólj, ha érdekel!

Íme a dián szereplő **definíciók és a kapcsolódó táblázat** áttekinthető formában:

---

### 📘 **Definíciók – Megoldások típusai:**

| Típus | Jelölés | Leírás |
|-------|---------|--------|
| **Megoldás** | mo | Ha az \(x\) vektort behelyettesítjük, és **nem lépjük túl a készleteket** |
| **Megengedett megoldás** | memo | Olyan megoldás, amelyben **minden komponens nemnegatív** |
| **Optimális megoldás** | opt mo | Olyan megengedett megoldás, amely a **legnagyobb hasznot** adja |

---

### 📊 **Erőforrás- és haszonmátrix**

|         | **T₁** | **T₂** | **T₃** | **T₄** | **T₅** | **Készlet** |
|---------|--------|--------|--------|--------|--------|-------------|
| **Erőf₁** | 1      | 2      | 1      | 3      | 0      | 24          |
| **Erőf₂** | 0      | 1      | 1      | 5      | 1      | 43          |
| **Erőf₃** | 1      | 0      | 0      | 2      | 2      | 18          |
| **Haszon** | 19     | 23     | 15     | 42     | 33     |             |

---

### 🧮 **Példák**

- \( x = (-1, 1, 1, 1, 1) \):  
  ✅ **Megoldás** (mert nem lépi túl a készleteket)  
  ❌ **Nem megengedett megoldás** (negatív érték van benne)

- \( x = (10, 1, 1, 0, 0) \):  
  ✅ **Megengedett megoldás** (nemnegatív és nem lépi túl a készleteket)

---

Ha szeretnéd, kiszámolhatjuk, hogy az utóbbi példában mennyi az összes haszon, vagy összevethetjük más tervekkel. Folytassuk?


Ez a dia az optimális megoldás keresésének kulcskérdéseit és egy lehetséges módszert foglalja össze:

---

### 🔍 **Hogyan keressünk optimális megoldást?**

1. **Van-e egyáltalán?**  
   → Lehet, hogy nincs megengedett megoldás, ezért először ezt kell ellenőrizni.

2. **Ha van, akkor mennyi?**  
   → Az optimális megoldás **nem mindig egyedi** – többféle megoldás is elérheti ugyanazt az optimális értéket.

3. **Hogyan találjuk meg?**  
   → Itt jön képbe a **matematikai módszerek** alkalmazása.

4. **Egy lehetséges módszer: a Szimplex Módszer**  
   → Ez egy jól ismert algoritmus lineáris programozási problémák megoldására.  
   → **Hatékony**, **lépésről lépésre halad**, és mindig egy sarokponti (bázis) megoldás felé lép.

---

Ha szeretnéd, mutathatok egy egyszerű példát a szimplex módszer gyakorlati alkalmazására. Érdekelne?


Ez a dia a **lineáris programozási feladatok (LP)** matematikai modelljét vezeti be, a következő jelölésekkel és formában:

---

### 📌 **Hogyan keressünk optimális megoldást?**

#### 🔣 Jelölések:
- **A**: az együttható mátrix – a felhasználási arányokat tartalmazza az erőforrásokra és termékekre nézve
- **b**: az erőforrások készlete – mennyi áll rendelkezésre az egyes erőforrásokból
- **c**: a célfüggvény együtthatói – mennyi nyereséget hoz egy-egy termék

---

### 📐 A lineáris programozási feladat általános alakja:

\[
\begin{aligned}
& Ax \leq b \quad &\text{(korlátok)} \\
& x \geq 0 \quad &\text{(nemnegativitás)} \\
& z = c \cdot x \rightarrow \max \quad &\text{(cél: maximalizálni a hasznot)}
\end{aligned}
\]

---

📎 **Megnevezés**: **Lineáris Program** (röviden **LP**)

Ez az alapmodell minden lineáris optimalizálási problémánál kiindulási pont – és ezt fogja megoldani például a **szimplex módszer**.

Szeretnéd, hogy leírjam a konkrét példát is részletesen ezek alapján?Ez a dia a **lineáris programozási feladatok (LP)** matematikai modelljét vezeti be, a következő jelölésekkel és formában:

---

### 📌 **Hogyan keressünk optimális megoldást?**

#### 🔣 Jelölések:
- **A**: az együttható mátrix – a felhasználási arányokat tartalmazza az erőforrásokra és termékekre nézve
- **b**: az erőforrások készlete – mennyi áll rendelkezésre az egyes erőforrásokból
- **c**: a célfüggvény együtthatói – mennyi nyereséget hoz egy-egy termék

---

### 📐 A lineáris programozási feladat általános alakja:

\[
\begin{aligned}
& Ax \leq b \quad &\text{(korlátok)} \\
& x \geq 0 \quad &\text{(nemnegativitás)} \\
& z = c \cdot x \rightarrow \max \quad &\text{(cél: maximalizálni a hasznot)}
\end{aligned}
\]

---

📎 **Megnevezés**: **Lineáris Program** (röviden **LP**)

Ez az alapmodell minden lineáris optimalizálási problémánál kiindulási pont – és ezt fogja megoldani például a **szimplex módszer**.

Szeretnéd, hogy leírjam a konkrét példát is részletesen ezek alapján?


Ez a dia a **konkrét lineáris programozási feladat** részletes matematikai megfogalmazását mutatja:

---

### 📋 **Lineáris programozási modell részletesen:**

#### 🧮 **Feltételek (korlátok):**
- \( x_1 + 2x_2 + x_3 + 3x_4 \leq 24 \)  
  *(1. erőforrás korlátja)*
- \( x_2 + x_3 + 5x_4 + x_5 \leq 43 \)  
  *(2. erőforrás korlátja)*
- \( x_1 + 2x_4 + 2x_5 \leq 18 \)  
  *(3. erőforrás korlátja)*

#### 🟢 **Nemnegativitási feltétel:**
- \( x_i \geq 0 \), ahol \( 1 \leq i \leq 5 \)

---

#### 🎯 **Célfüggvény (maximalizálandó haszon):**

\[
z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5 \rightarrow \max
\]

---

Ez egy **klasszikus lineáris programozási probléma**, ahol a cél a haszon maximalizálása az adott erőforrás-korlátokon belül. A következő lépés a **szimplex módszerrel** való megoldás lesz.

Ha szeretnéd, kiszámolhatom a kezdő alapmegoldást vagy végigvihetjük együtt a szimplex algoritmust is. Érdekel?


Ez a dia azt mutatja, hogyan **készítjük elő a lineáris programot a Szimplex módszerhez**, azaz:

---

### 🔁 **Első lépés: Egyenlőtlenségek → egyenletek**

Bevezetjük az **úgynevezett maradék változókat** (*slack variables*), hogy az egyenlőtlenségeket átalakítsuk egyenletekké:

#### 🧮 Átalakított feltételek:
\[
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4 + s_1 &= 24 \\
x_2 + x_3 + 5x_4 + x_5 + s_2 &= 43 \\
x_1 + 2x_4 + 2x_5 + s_3 &= 18
\end{aligned}
\]

ahol:
- \( s_1, s_2, s_3 \) a **maradék (slack) változók**, melyek a kihasználatlan erőforrásokat reprezentálják.

#### 🟢 **Feltétel:**
\[
x \geq 0, \quad s \geq 0
\]

---

### 🎯 **Célfüggvény:**
\[
z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5 \rightarrow \max
\]

---

Ez az **alapforma** szükséges ahhoz, hogy elindulhassunk a **Szimplex algoritmussal**. A következő lépés a **kezdeti szimplex tábla felírása**.

Szeretnéd, hogy ezt is lépésről lépésre levezessük?



Ez a dia azt mutatja meg, hogyan néz ki a lineáris program **Szimplex táblázatos formában**, amely az algoritmus egyik kulcslépése. Lássuk részletesen:

---

### 📊 **Szimplex Tábla (Simplex Tableau)**

|   B   | \( x_B \) | \( a_1 \) | \( a_2 \) | \( a_3 \) | \( a_4 \) | \( a_5 \) | \( u_1 \) | \( u_2 \) | \( u_3 \) |
|-------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|
| \( u_1 \) | 24        | 1         | **2**       | 1         | 3         | 0         | 1         | 0         | 0         |
| \( u_2 \) | 43        | 0         | 1         | 1         | 5         | 1         | 0         | 1         | 0         |
| \( u_3 \) | 18        | 1         | 0         | 0         | 2         | 2         | 0         | 0         | 1         |
| \( z \)   | 0         | -19       | -23       | -15       | -42       | -33       | 0         | 0         | 0         |

---

### 🧠 Magyarázat:

- **\( B \)**: Az aktuális **bázisváltozók** (jelenleg: \( u_1, u_2, u_3 \), vagyis a slack változók).
- **\( x_B \)**: A bázisváltozók értékei a megoldásban – jelen esetben:
  \[
  x_B = (0, 0, 0, 0, 0 \mid 24, 43, 18)
  \]
- **A mátrix többi része**: A koefficiensek a korlátozó egyenletekből.

---

### ℹ️ Fontos fogalmak:

- **Bázismegoldás**: A változók, amelyek **nem szerepelnek** a bázisban, azok **nullák**.
- **Redukált költségek** (alsó sor): A célfüggvény (profit) növekedésének vagy csökkenésének iránya, ha az adott változót beemelnénk a bázisba.
  - **Ha negatív**, akkor az adott oszlopban levő változó **növelésével nőne a profit** → ezek lehetnek következő belépők.
  - **Ha nulla vagy pozitív**, akkor nem javítja a célértéket.

---

### ❓ **Mire jó ez?**

- **Megmondja**, hogyan válasszuk ki a következő változót a bázisba (pl. amelyik oszlopban a legalacsonyabb negatív érték van).
- **Lehetővé teszi** a lépésenkénti optimalizációt a Szimplex módszer segítségével.
- **Vizualizálhatóvá teszi** a lineáris program egy állapotát.

---

Szeretnéd, hogy innen folytassuk a szimplex lépésekkel, pl. hogyan választjuk ki a pivot elemet, és milyen transzformációk jönnek?


Ez a dia egy **alaptételt** fogalmaz meg a szimplex módszer működéséről, amelyet **Dantzig-féle tételként** is ismerünk. A szimplex tábla legalsó sora (az úgynevezett **redukált költségsor**) alapján 3 esetet különböztetünk meg:

---

### 📌 **Tétel – A szimplex tábla három esete:**

#### 1. **Nincs negatív szám a legalján (z-sorban):**
- A **redukált költségek** (utolsó sor) minden eleme **nemnegatív**.
- Ez azt jelenti, hogy **nincs lehetőség a célérték további növelésére**, tehát:
  > **A bázismegoldás optimális.**

---

#### 2. **Van negatív szám alul, de az oszlopában nincs pozitív szám a tábla belsejében:**
- Tehát van olyan változó, amely javíthatna a célfüggvényen, de **nem tud belépni** a bázisba, mert a pivothoz tartozó oszlopban nincs pozitív szám.
- Ez azt jelenti, hogy:
  > **A célfüggvény értéke felülről nem korlátos (unbounded), azaz nem létezik maximum.**

---

#### 3. **Van negatív szám alul és van hozzá tartozó pozitív szám a fenti sorokban is:**
- Ez azt jelenti, hogy a megfelelő **báziscsere végrehajtható**, és:
  > A célfüggvény **értéke javulni fog** → **folytatjuk a lépéseket**.

---

### ❓ **Mire jó ez nekünk?**

Ez a tétel megmondja, **mikor állhatunk meg**, **mikor van baj** (nem korlátos megoldás), és **mikor kell továbblépni** egy új bázismegoldás felé a szimplex módszer során.

---

Szeretnéd, hogy a következő diát is értelmezzem? Szívesen végigmegyek a teljes példán is, ha kéred!


Ez a dia a **szimplex módszer** működésének második fázisát, a **prímál szimplex** algoritmus lényegét magyarázza el.

---

### 📌 **Szimplex módszer (prímál módszer – 2. fázis):**

#### 🔄 Báziscserék:
- A megoldás minden lépésben egy új bázismegoldásra vált, azaz **báziscserét** hajtunk végre.

#### ✅ **Megengedettség megőrzése**:
- Az új megoldásnak **megengedettnek kell maradnia**, vagyis minden komponensnek **nemnegatívnak** kell lennie.
- Ezt a **minimum szabály** biztosítja: olyan sort választunk, amelyiknél az új változó bevezetése nem eredményez negatív értéket.

#### 📈 **Cél: a célfüggvény növelése**:
- Csak akkor cserélünk bázist, ha van olyan **nem bázisváltozó**, amelynek **redukált költsége negatív** – ez növelni tudja a célfüggvényt.

#### 🛑 **Optimalitás feltétele**:
- Ha **nincs több negatív elem** a redukált költség sorban (utolsó sor), akkor:
  > **Elértük az optimális megoldást.**

#### 🔁 **Állítás – Végesség**:
- A szimplex módszer **véges lépésszámmal** eljut a megoldáshoz, **ha jól hajtjuk végre** (pl. nem esünk végtelen ciklusba – ezt degenerációkezeléssel ki lehet védeni).
- A gyakorlatban általában nagyon **gyorsan konvergál**.

---

Ha szeretnéd, folytatom a következő diával vagy részletesen elmagyarázok példát is az előző táblázatok alapján.

Ez a dia a **szimplex módszer egyik lépését** mutatja be, konkrétan a **báziscsere folyamatát** a szimplex táblában.

---

### 🔄 **Mi történik itt?**

#### **Előző tábla (ez volt):**
- A bázis: `u₁`, `u₂`, `u₃`
- Az `a₂` oszlopban lévő értékek alapján a **minimum szabály** szerint `u₁` hagyta el a bázist, `a₂` pedig belépett.

#### **Új tábla (ez lett):**
- A bázis: `a₂`, `u₂`, `u₃`
- A táblázat újra van számolva **Gauss-eliminációs lépéssel**.
- A pivot elem: `2` a `u₁` sorban és `a₂` oszlopban.

---

### 🔁 **Következő lépés:**

A dia végén ezt írja:
> „Most válasszuk az **a₅** vektort a bázisba belépőnek. A **minimum szabály** szerint **u₃** hagyja el a bázist.”

Ez a **következő pivot** lépés:
- Belép: `a₅`
- Kilép: `u₃`

Ez a döntés a `a₅` oszlop (amelyben a legnegatívabb érték a célfüggvény sorában van: `-33`) és a minimális `x_B / a₅` arány alapján történik.

---

Ha kéred, elmagyarázom részletesen a következő táblázat számítását vagy megcsinálhatjuk lépésről lépésre. Szívesen segítek!



Ez a dia bemutatja a **szimplex algoritmus újabb lépését**, amely a következő változásokkal jár:

---

### 🧮 **Ez volt (előző tábla):**

- A bázis: `a₂`, `u₂`, `u₃`
- A `z` sorban még mindig van negatív érték (−33 az `a₅` oszlopban)
- Ezért: **az `a₅` oszlop belép a bázisba** (mert itt a legnagyobb abszolút értékű negatív szám van)

### ⚖️ **Minimum szabály alkalmazása:**

A minimum szabály szerint azt vizsgáljuk, melyik sorból lépjen ki a változó:

- `a₂` sor: `a₅` érték = 0 → nem jó
- `u₂` sor: `a₅` érték = 1 → 31 / 1 = 31
- `u₃` sor: `a₅` érték = **2** → **18 / 2 = 9** → ez a minimum!

➡️ Tehát: **`u₃` kilép**, és **`a₅` belép** a bázisba. A pivot elem: **2**

---

### ✅ **Ez lett (új tábla):**

- A bázis: `a₂`, `u₂`, `a₅`
- Az új `z` érték: **573**
- A `z` sorban csak egy negatív érték maradt (`a₃` oszlopban: −7/2)

Következtetés:
- **A folyamat még nem fejeződött be**, mert van még negatív elem a célfüggvény sorában → tehát **még egy báziscserét kell végezni**.
- Következő belépő: `a₃`

---

Szeretnéd, hogy végigmenjünk a következő lépésen is? Szívesen segítek kiszámolni vagy elmagyarázni!

Ez az utolsó előtti dia azt foglalja össze, mi történik a **szimplex algoritmusban** az **utolsó negatív redukált költség** kezelése után:

---

### 🔁 **Áttekintés – Hogyan változik a célfüggvény?**

1. **Negatív redukált költségű oszlop lép be:**
   - A célfüggvény **növekszik**
   - Ez a kívánt eset, mivel maximalizálni akarjuk az értéket

2. **Pozitív redukált költségű oszlop lép be (általában nem történik):**
   - A célfüggvény **csökken**

3. **0 redukált költségű oszlop lép be:**
   - A célfüggvény **nem változik**

---

### 🔍 **Jelenlegi helyzet:**
- Csak **az `a₂` oszlop** maradt negatív redukált költséggel → **ez lép be a bázisba**
- **`a₂` hagyja el a bázist** a minimum szabály szerint
- Bázis most: `a₂`, `u₂`, `a₅`  
- Mivel minden bázishoz tartozó `x` érték **pozitív**, a megoldás **nemdegenerált**

---

### ℹ️ **Degenerált megoldás:**
- Akkor degenerált, ha a bázisban lévő változók közül **legalább egy nullát vesz fel**
- Most ez **nem áll fenn**, tehát minden változás a célfüggvény javulásával jár

---

### Következő lépés:
A báziscsere után meglátjuk a végső táblát és az **optimális megoldást**.

Készen állsz a következő, utolsó diára? 😄

Ez az utolsó dia összefoglalja a **szimplex módszer** alkalmazásával kapott **végső, optimális megoldást**:

---

### ✅ **Optimális megoldás:**
A végső bázis megoldás:  
\[
\mathbf{x_B} = (0, 0, 24, 0, 9 \mid 0, 10, 0)
\]
Ez azt jelenti:

- **x₃ = 24** → a harmadik termékből 24 egységet termelünk  
- **x₅ = 9** → az ötödik termékből 9 egységet termelünk  
- **A többi x változó (x₁, x₂, x₄) = 0** → a többi termékből nem termelünk

---

### 📦 **Erőforrás-felhasználás:**

- Az **u₂ (második erőforrás)** → 10 egység **megmaradt**
- A többi erőforrás (u₁, u₃) **teljesen el lett használva**  
  (mivel hozzájuk tartozó érték: 0)

---

### 🎯 **Célfüggvény értéke:**
\[
z_{OPT} = 657
\]
Ez az elérhető **maximális nyereség** a megadott korlátok mellett.

---

### 🧠 Mit tanultunk ebből?
- A **szimplex módszer** végigjárja a csúcspontokat (bázisokat)
- Minden lépésben **javítja** (vagy nem rontja) a célértéket
- Ha nincs több negatív érték a redukált költségek sorában → **optimumban vagyunk**

Ha szeretnél, csinálhatunk közösen egy új szimplex példát gyakorlásképp. Érdekel? 😊


This page introduces a **production optimization problem** and how it can be solved using the **Primal Simplex method**. Here's a summary and interpretation of the content:

---

### 🏭 **Production Problem Data Table**

|       | P₁ | P₂ | P₃ | P₄ | Cap |
|-------|----|----|----|----|-----|
| Res₁ | 1  | 2  | 1  | 2  | 40  |
| Res₂ | 1  | 0  | 1  | 1  | 38  |
| Res₃ | 1  | 1  | 3  | 2  | 26  |
| Profit | 11 | 15 | 14 | 18 |     |

This shows the **resources used** by four products (P₁ to P₄), the **capacity limits** for each resource (Res₁ to Res₃), and the **profit** per unit for each product.

---

### 🧮 **Step 1: Write the model**

Maximize:
\[
z = 11x_1 + 15x_2 + 14x_3 + 18x_4
\]

Subject to constraints:
\[
\begin{aligned}
x_1 + 2x_2 + x_3 + 2x_4 &\leq 40 \quad \text{(Resource 1)} \\
x_1 + x_3 + x_4 &\leq 38 \quad \text{(Resource 2)} \\
x_1 + x_2 + 3x_3 + 2x_4 &\leq 26 \quad \text{(Resource 3)} \\
x_j &\geq 0 \quad \text{for } j = 1 \text{ to } 4
\end{aligned}
\]

---

### 🔁 **Step 2: Convert to equations (add slack variables)**

\[
\begin{aligned}
x_1 + 2x_2 + x_3 + 2x_4 + s_1 &= 40 \\
x_1 + x_3 + x_4 + s_2 &= 38 \\
x_1 + x_2 + 3x_3 + 2x_4 + s_3 &= 26 \\
x_j, s_j &\geq 0 \\
z &= 11x_1 + 15x_2 + 14x_3 + 18x_4 \rightarrow \max
\end{aligned}
\]

Now we have the standard form of a linear program.

---

### 📋 **Step 3: Build the first simplex tableau**

This step wasn't fully visible on the page, but it's the setup for applying the **simplex algorithm** to find the **optimal solution** step-by-step starting from the feasible slack-based solution.

---

If you'd like, I can walk you through solving this example using the simplex method from start to end — or translate this into Hungarian too. Would you prefer to continue in English or Hungarian?


This page continues the **Primal Simplex method** with **Step 4**, focusing on **choosing the entering variable** and starting the **basis transformation**. Here's a detailed breakdown:

---

### 📊 **Simplex Tableau**

| B   | x_B | a₁ | a₂ | a₃ | a₄ | u₁ | u₂ | u₃ |
|-----|-----|----|----|----|----|----|----|----|
| u₁ | 40  | 1  | 2  | 1  | 2  | 1  | 0  | 0  |
| u₂ | 38  | 1  | 0  | 1  | 1  | 0  | 1  | 0  |
| u₃ | 26  | 1  | 1  | 3  | 2  | 0  | 0  | 1  |
| z   | 0   | -11| -15| -14| -18| 0  | 0  | 0  |

- Bottom row (z): reduced costs → tells us how increasing each variable would affect the objective function.
- Negative reduced cost values (like -15 under a₂) indicate **potential for improvement**.

---

### ⚙️ **Step 4: Basis Transformation**

#### 🔍 Objective: Choose a column with **negative reduced cost** to enter the basis.
- **a₁, a₂, a₃, a₄** are all candidates (since they have negative reduced cost).

#### ✅ **Smart greedy choice**:
We want the column that yields the **greatest improvement per unit of resource** (most increase in the objective). This is done via:

#### 🔁 **Preprocessing Calculation** (Minimum ratio test):

- For **a₁**:  
  - u₃ has the smallest ratio → 26 / 1 = **26**,  
  - Improvement per unit: 26 × 11 = **286**

- For **a₂**:  
  - u₁ has the smallest ratio → 40 / 2 = **20**,  
  - Improvement per unit: 20 × 15 = **300**

- For **a₃**:  
  - u₃ has the smallest ratio → 26 / 3 ≈ **8.67**,  
  - Improvement per unit: 8.67 × 14 ≈ **121.33**

- For **a₄**:  
  - u₃ has the smallest ratio → 26 / 2 = **13**,  
  - Improvement per unit: 13 × 18 = **234**

#### 🥇 Best choice: **a₂**
It gives the highest potential increase to the objective function (**300**).

---

### ✏️ Next Step:
Perform the pivot transformation with **a₂** entering the basis and **u₁** leaving (since it had the smallest ratio for that column). This transformation will create the new simplex tableau.

Let me know if you want the next tableau calculated or translated into Hungarian!


This page shows two key pivot steps in the **Primal Simplex Method**, detailing the transformations to reach the new simplex tableau.

---

### 🔁 **First Transformation**
We pivot on **a₂** (because it gave the largest improvement in the objective function), replacing **u₁** with **a₂** in the basis.

#### ✅ Resulting Tableau:

| B   | x_B | a₁   | a₂ | a₃   | a₄  | u₁   | u₂ | u₃ |
|-----|-----|------|----|------|-----|------|----|----|
| a₂  | 20  | 1/2  | 1  | 1/2  | 1   | 1/2  | 0  | 0  |
| u₂  | 38  | 1    | 0  | 1    | 1   | 0    | 1  | 0  |
| u₃  | 6   | 1/2  | 0  | 5/2  | 1   | -1/2 | 0  | 1  |
| z   | 300 | -7/2 | 0  | -13/2| -3  | 15/2 | 0  | 0  |

---

### 📊 Preprocessing Again:
We choose the next entering variable based on which will increase the objective function the most:

#### Test each column:
- **a₁**: min ratio = 6 / (1/2) = **12** → gain = 12 × 3.5 = **42**
- **a₃**: min ratio = 6 / (5/2) = 2.4 → gain ≈ **15.6**
- **a₄**: min ratio = 6 / 1 = **6** → gain = 6 × 3 = **18**

#### ✅ Best choice: **a₁** again.

---

### 🔁 **Second Transformation**
Pivot on **a₁**, replacing **u₃** with **a₁**.

#### ✅ Final Tableau on This Page:

| B   | x_B | a₁ | a₂ | a₃  | a₄ | u₁ | u₂ | u₃ |
|-----|-----|----|----|-----|----|----|----|----|
| a₂  | 14  | 0  | 1  | -2  | 0  | 1  | 0  | -1 |
| u₂  | 26  | 0  | 0  | -4  | -1 | 1  | 1  | -2 |
| a₁  | 12  | 1  | 0  | 5   | 2  | -1 | 0  | 2  |
| z   | 342 | 0  | 0  | 11  | 4  | 4  | 0  | 7  |

---

### 🎯 Summary:
- The basis is now: **a₂, u₂, a₁**
- Basic variables: `x_B = (14, 26, 12)`
- Objective value `z = 342`
- All reduced costs in row z are **non-negative**, so we've reached **optimality** 🎉

---

Let me know if you’d like this in Hungarian or want to continue with the next steps!


Here's a summary and explanation of what's shown on this page of the document:

---

### ✅ **Step 5: Evaluation (Final Step in Simplex Method)**

- **Optimal solution vector:**
  \[
  x_{OPT} = (12,\ 14,\ 0,\ 0\ |\ 0,\ 26,\ 0)
  \]
  - The first part is the product quantities (x₁ to x₄).
  - The second part is the slack variables (s₁ to s₃).
  - The optimal value of the objective function: \( z_{OPT} = 342 \)

#### ✅ Interpretation:
- Produce **12 units of P₁**, **14 units of P₂**, and none of P₃ or P₄.
- Use up all resources **Res₁** and **Res₃**.
- **26 units** remain unused from **Res₂**.
- The **objective value (profit)** is **342**.

---

### 🧠 **Exercises for Practice**

#### **Exercise 1:**
| Product | P₁ | P₂ | P₃ | P₄ | Cap |
|---------|----|----|----|----|-----|
| Res₁    | 1  | 2  | 1  | 2  | 40  |
| Res₂    | 1  | 0  | 1  | 1  | 10  |
| Res₃    | 1  | 1  | 3  | 2  | 26  |
| Profit  | 11 | 15 | 28 | 18 |     |

- **Optimal solution:**
  \[
  x_{OPT} = \left(0,\ \frac{94}{5},\ \frac{12}{5},\ 0\ \big|\ 0,\ \frac{38}{5},\ 0\right)
  \]
  - \( z_{OPT} = 349.2 \)

---

#### **Exercise 2:**
Similar setup as Ex.1 but **Res₃ capacity reduced to 15**, **P₂ profit reduced to 5**.

- **Optimal solution:**
  \[
  x_{OPT} = \left(\frac{15}{2},\ 0,\ \frac{5}{2},\ 0\ \big|\ 30,\ 0,\ 0\right)
  \]
  - \( z_{OPT} = 152.5 \)

---

#### **Exercise 3:**
Now with 5 products:

| Product | P₁ | P₂ | P₃ | P₄ | P₅ | Cap |
|---------|----|----|----|----|----|-----|
| Res₁    | 1  | 1  | 2  | 1  | 1  | 25  |
| Res₂    | 0  | 1  | 0  | 1  | 2  | 42  |
| Res₃    | 1  | 0  | 1  | 3  | 1  | 50  |
| Profit  | 12 | 8  | 15 | 17 | 22 |     |

- **Two optimal extreme solutions:**
  - \( x_{OPT_1} = (4,\ 0,\ 0,\ 0,\ 21\ |\ 0,\ 0,\ 25) \)
  - \( x_{OPT_2} = (0,\ 0,\ 0,\ 8,\ 17\ |\ 0,\ 0,\ 9) \)
- General form of solution:
  \[
  x_{OPT} = \lambda \cdot x_{OPT_1} + (1 - \lambda) \cdot x_{OPT_2}, \quad 0 \leq \lambda \leq 1
  \]
- \( z_{OPT} = 510 \)

This shows that the optimal solution is **not unique** — it's on a **line segment** between two points.

---

Let me know if you'd like a **Hungarian version**, or a **step-by-step explanation** of one of the exercises!