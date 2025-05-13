The document `LP7.pdf` is a lecture on **Linear Programming (LP)** and the **Simplex Method**, delivered by György Dósa at Pannon University. Here's a structured overview and key points extracted:

---

### 📘 **Topics Covered**

1. **Introduction to Operations Research**

   * Origin in military planning (operations research)
   * Linear Programming (LP)
   * George Dantzig and the Simplex Method

2. **Application Areas**

   * Transportation Problem
   * Assignment Problem
   * Game Theory (briefly)
   * Discrete Programming:

     * Knapsack Problem
     * Traveling Salesman
     * Cutting Stock Problem

---

### 🏭 **Production Problem Example**

You are given:

* 5 products (T1–T5)
* 3 resource constraints (with capacities 24, 43, and 18)
* Profit per unit of product (19, 23, 15, 42, 33)

**Objective**: Maximize profit given resource constraints.

---

### 🧮 **Linear Program Formulation**

Let variables `x1` to `x5` be the units produced of T1 to T5:

```
Maximize: z = 19x1 + 23x2 + 15x3 + 42x4 + 33x5

Subject to:
x1 + 2x2 + x3 + 3x4         ≤ 24
      x2 + x3 + 5x4 + x5    ≤ 43
x1           + 2x4 + 2x5    ≤ 18
xi ≥ 0  for all i
```

---

### 📋 **Simplex Method Setup**

Slack variables `s1`, `s2`, and `s3` are added to convert inequalities to equalities.

Initial Simplex Tableau includes:

* Slack variables in the basis
* Negative reduced costs in the objective row → improvement possible

---

### 🔁 **Simplex Iteration Steps**

1. **Pivot Selection** using the most negative reduced cost
2. **Minimum Ratio Rule** for choosing which variable leaves the basis
3. **Row Operations** to update the tableau

**Several iterations** are shown step-by-step with pivot operations, updated tableaus, and improved objective values.

---

### ✅ **Optimal Solution**

Final production plan:

```
x = (0, 0, 24, 0, 9)
z = 657
```

* Produce 24 units of T3 and 9 units of T5.
* 10 units of the 2nd resource remain unused.
* All constraints satisfied, and all variables ≥ 0 → optimal solution.

---

Would you like me to extract and format the tableau iterations for practice, or generate a Python/C++ program that solves this LP using the simplex method?



### 📊 Slide 5/20 — **Egy termelési probléma** (A Production Problem)

This slide presents a **linear programming (LP) example** involving production planning.

#### **Matrix/Table Format**

|            | T1 | T2 | T3 | T4 | T5 | **Készlet** (Capacity) |
| ---------- | -- | -- | -- | -- | -- | ---------------------- |
| **Erőf1**  | 1  | 2  | 1  | 3  | 0  | 24                     |
| **Erőf2**  | 0  | 1  | 1  | 5  | 1  | 43                     |
| **Erőf3**  | 1  | 0  | 0  | 2  | 2  | 18                     |
| **Haszon** | 19 | 23 | 15 | 42 | 33 |                        |

---

#### **Explanation**

* **Products:** T1 to T5
* **Resources:** Erőf1, Erőf2, Erőf3 (resource constraints)
* **Készlet:** Maximum units of each resource available
* **Haszon (Profit):** Profit earned by producing one unit of the respective product

---

#### **Example Calculation:**

If we produce:

* 8 units of T2
* 1 unit of T4

Then the consumption of **Erőf1** is:

```
(8 × 2) + (1 × 3) = 16 + 3 = 19 units
```

The same calculation can be done for Erőf2 and Erőf3 using the matrix.

---

#### **Objective:**

Find the production plan `x = (x1, x2, x3, x4, x5)` that:

* **Maximizes total profit**:
  `z = 19x1 + 23x2 + 15x3 + 42x4 + 33x5`
* **Satisfies resource constraints** given by the rows Erőf1–Erőf3.

Would you like me to convert this into a linear program or solve it using code?


### 📊 Slide 6/20 — **Termelési terv példák** (Examples of Production Plans)

This slide builds upon the production matrix and shows how different product combinations affect resource usage and profit.

---

#### 🏗️ **Plan Example**

Suppose we choose to produce:

```
x = (0, 8, 0, 1, 0)
```

That is:

* 0 units of T1
* 8 units of T2
* 0 units of T3
* 1 unit of T4
* 0 units of T5

Then, using the resource matrix:

##### **Erőf1 consumption**:

```
8 × 2 + 1 × 3 = 16 + 3 = 19 units
```

##### **Erőf2 consumption**:

```
8 × 1 + 1 × 5 = 8 + 5 = 13 units
```

##### **Erőf3 consumption**:

```
8 × 0 + 1 × 2 = 0 + 2 = 2 units
```

All of these are within the allowed capacities (24, 43, 18).

---

#### 💰 **Profit Calculation**

Let profit vector be:

```
c = (19, 23, 15, 42, 33)
```

Then total profit:

```
c · x = 19×0 + 23×8 + 15×0 + 42×1 + 33×0 = 184 + 42 = 226
```

---

#### ❓ **Goal**

> Mi lesz a "legjobb" termelési terv?
> ("What will be the **best** production plan?")

This leads into the optimization goal: **maximize total profit while respecting the resource constraints**.

Would you like to generate all feasible plans manually or solve this using the Simplex method in Python or C++?

### 📊 Slide 7/20 — **Guessing Production Plans**

This slide suggests **trial production plans** and computes the resulting profit $z$ for each:

---

#### 🧪 Trial Plans (Guesses)

| Plan Label | Production Vector $x$ | Profit Calculation | Total Profit $z$ |
| ---------- | --------------------- | ------------------ | ---------------- |
| **a**      | $(18, 0, 0, 0, 0)$    | $18 × 19 = 342$    | **342**          |
| **b**      | $(0, 12, 0, 0, 0)$    | $12 × 23 = 276$    | **276**          |
| **c**      | $(0, 0, 24, 0, 0)$    | $24 × 15 = 360$    | **360**          |
| **d**      | $(0, 0, 0, 8, 0)$     | $8 × 42 = 336$     | **336**          |
| **e**      | $(0, 0, 0, 0, 9)$     | $9 × 33 = 297$     | **297**          |
| **f**      | ???                   | ???                | ???              |

---

### 🧠 Interpretation

These are *feasible guesses* that produce only one type of product at a time, within the resource limits.
Plan **c** gives the highest profit so far: **360**.

> But is that the **optimal** plan? Probably not — it doesn't mix products, which might lead to a better result.

Would you like to propose a plan **f** now, mixing products manually, and calculate its profit?








### 📊 Slide 8/20 — **Megoldás, megengedett megoldás, optimális megoldás**

This slide introduces **definitions** crucial to understanding Linear Programming feasibility and optimality.

---

### 🧮 **Definitions**

Let $x$ be a production vector (e.g., $x = (x_1, x_2, x_3, x_4, x_5)$).

* **Megoldás (Solution)**:
  A vector $x$ is a **solution** if it satisfies the **resource constraints**, i.e., does **not exceed** resource limits when substituted.

* **Megengedett megoldás (Feasible Solution)**:
  A solution where **all components of $x$ are non-negative** (no negative production).

* **Optimális megoldás (Optimal Solution)**:
  A feasible solution that **maximizes** the profit among all feasible solutions.

---

### 🧪 Examples

| Vector $x$         | Type                       | Why?                                  |
| ------------------ | -------------------------- | ------------------------------------- |
| $(-1, 1, 1, 1, 1)$ | Solution, **not feasible** | Violates non-negativity constraint    |
| $(10, 1, 1, 0, 0)$ | **Feasible Solution**      | All constraints met, and non-negative |

---

This prepares the groundwork for understanding how the **Simplex Method** searches through feasible solutions to find the optimal one.

Want to try checking if one of our guessed vectors (from slide 7) is feasible in terms of all resource constraints?



### 📊 Slide 9/20 — **Hogyan keressünk optimális megoldást?**

**(How do we find the optimal solution?)**

This slide introduces the **Simplex Method** as a solution technique for linear programs.

---

### ❓ Key Questions Asked:

1. **Van-e egyáltalán?**
   *Does a solution exist at all?*

2. **Ha igen, akkor mennyi van?**
   *If yes, how many solutions exist?*

3. **Hogyan találjuk meg?**
   *How do we find the optimal one?*

---

### ✅ **Suggested Method**

> **Egy lehetséges megoldási módszer: Szimplex Módszer**
> *A possible solution method: The Simplex Method*

---

This is a transition slide — it sets up for turning the production problem into **standard linear programming form** and applying the **Simplex Algorithm** to find the optimal production plan.

Would you like to see the LP expressed in matrix/vector notation or proceed to how it's formally written (slide 10)?






### 📊 Slide 11/20 — **Formulating the Linear Program with Slack Variables**

This slide shows how to **convert inequalities into equations** by adding **slack variables**, preparing the problem for the **Simplex Method**.

---

### 📐 Original Constraints:

From earlier:

```
x₁ + 2x₂ + x₃ + 3x₄           ≤ 24      →  add s₁
       x₂ + x₃ + 5x₄ + x₅     ≤ 43      →  add s₂
x₁           + 2x₄ + 2x₅      ≤ 18      →  add s₃
```

---

### ✅ Converted System (Standard Form):

We introduce slack variables $s_1, s_2, s_3 \ge 0$:

$$
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4         + s_1 &= 24 \\
       x_2 + x_3 + 5x_4 + x_5 + s_2 &= 43 \\
x_1           + 2x_4 + 2x_5     + s_3 &= 18 \\
x_i, s_j &\ge 0 \quad \text{for all } i, j
\end{aligned}
$$

---

### 🎯 Objective Function:

$$
\text{Maximize } z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5
$$

---

This is the **canonical form** of a Linear Programming problem, ready for the **Simplex Tableau** setup in the next slide.

Would you like me to show the matrix $A$, vector $b$, and vector $c$ explicitly too?





Certainly! Based on Slide 11/20 and the standard linear program you've formulated, here is the **explicit matrix and vector form**:

---

### 📘 Standard Linear Program Form:

$$
\begin{aligned}
\text{Maximize } & z = \mathbf{c}^T \mathbf{x} \\
\text{Subject to } & A\mathbf{x} = \mathbf{b},\quad \mathbf{x} \geq 0
\end{aligned}
$$

---

### 🧮 Variables

Let:

* Decision variables: $\mathbf{x} = (x_1, x_2, x_3, x_4, x_5, s_1, s_2, s_3)^T$
* Slack variables $s_1, s_2, s_3$ are added to convert inequalities to equalities

---

### 🧾 Matrix $A$ (Coefficients):

$$
A =
\begin{bmatrix}
1 & 2 & 1 & 3 & 0 & 1 & 0 & 0 \\
0 & 1 & 1 & 5 & 1 & 0 & 1 & 0 \\
1 & 0 & 0 & 2 & 2 & 0 & 0 & 1 \\
\end{bmatrix}
$$

Each row corresponds to a constraint.

---

### 📦 Vector $b$ (Right-hand sides):

$$
\mathbf{b} =
\begin{bmatrix}
24 \\
43 \\
18 \\
\end{bmatrix}
$$

---

### 💰 Vector $c$ (Objective function coefficients):

$$
\mathbf{c} =
\begin{bmatrix}
19 \\
23 \\
15 \\
42 \\
33 \\
0 \\
0 \\
0 \\
\end{bmatrix}
$$

---

Now you're fully set to initialize the **Simplex tableau**.
Would you like to see the **initial tableau** constructed from this data?

Great question!

The reason we write the objective function as:

$$
z = \mathbf{c}^T \mathbf{x}
$$

is because of **matrix multiplication rules**.

---

### ⚙️ Why $\mathbf{c}^T \mathbf{x}$?

Let’s break it down:

* $\mathbf{c}$ is a **column vector** with the coefficients of the objective function (e.g. profits).
* $\mathbf{x}$ is also a **column vector** of decision variables.

Matrix multiplication is only defined when the number of **columns of the first** matrix matches the number of **rows of the second**.
So:

* $\mathbf{c}^T$: a **row vector** (1 × n)
* $\mathbf{x}$: a **column vector** (n × 1)

Then:

$$
\mathbf{c}^T \mathbf{x} = \text{a scalar (1 × 1)}
$$

which is exactly what we want — the **total value of the objective function** (e.g. total profit).

---

### 🔢 Example:

If:

$$
\mathbf{c} =
\begin{bmatrix}
19 \\
23 \\
15
\end{bmatrix},\quad
\mathbf{x} =
\begin{bmatrix}
1 \\
2 \\
3
\end{bmatrix}
$$

Then:

$$
\mathbf{c}^T \mathbf{x} = [19\ 23\ 15] \cdot
\begin{bmatrix}
1 \\
2 \\
3
\end{bmatrix} = 19×1 + 23×2 + 15×3 = 19 + 46 + 45 = 110
$$

---

So:

* The transpose $\mathbf{c}^T$ is not because we **changed** the vector — it's because matrix multiplication requires it in that form to compute the dot product.

Would you like me to write it using summation notation instead?


Absolutely! Here's the **summation notation** version of the objective function:

---

### 🎯 Objective Function in Summation Form:

$$
z = \sum_{i=1}^{n} c_i \cdot x_i
$$

Where:

* $n$ is the number of decision variables (e.g. 5 products),
* $c_i$ is the **profit per unit** of product $i$,
* $x_i$ is the **quantity** produced of product $i$.

---

### 🧾 For your specific example:

$$
z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5 = \sum_{i=1}^{5} c_i x_i
$$

This expresses the same thing as $\mathbf{c}^T \mathbf{x}$, but using classical summation notation instead of linear algebra form.

Would you like to write the constraints in summation form too?




### 📊 Slide 11/20 — **Standard Form of the LP with Slack Variables**

This slide shows how we take the inequality constraints and convert them into **equations**, so the problem fits the Simplex Method framework.

---

### 🔁 **Slack Variable Transformation**

We start from the inequality constraints (from Slide 10):

$$
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4 &\leq 24 \\
x_2 + x_3 + 5x_4 + x_5 &\leq 43 \\
x_1 + 2x_4 + 2x_5 &\leq 18
\end{aligned}
$$

To convert them to equalities, we **add slack variables** $s_1, s_2, s_3$ (one per constraint):

$$
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4 + s_1 &= 24 \quad \text{(first constraint)} \\
x_2 + x_3 + 5x_4 + x_5 + s_2 &= 43 \quad \text{(second constraint)} \\
x_1 + 2x_4 + 2x_5 + s_3 &= 18 \quad \text{(third constraint)}
\end{aligned}
$$

---

### 🟰 Complete LP in Standard Form

$$
\begin{aligned}
&x_1 + 2x_2 + x_3 + 3x_4 + s_1 = 24 \\
&x_2 + x_3 + 5x_4 + x_5 + s_2 = 43 \\
&x_1 + 2x_4 + 2x_5 + s_3 = 18 \\
&x_i \geq 0,\ s_j \geq 0 \quad \text{for all } i, j \\
&\text{Maximize } z = 19x_1 + 23x_2 + 15x_3 + 42x_4 + 33x_5
\end{aligned}
$$

---

This step is crucial because the **Simplex Method** operates on systems of linear equations with **equalities**, not inequalities.

Would you like to see how this translates into a **simplex tableau** (next step in Slide 12)?

$$
\begin{aligned}
x_1 + 2x_2 + x_3 + 3x_4         + s_1 &= 24 \\
       x_2 + x_3 + 5x_4 + x_5 + s_2 &= 43 \\
x_1           + 2x_4 + 2x_5     + s_3 &= 18 \\
x_i, s_j &\ge 0 \quad \text{for all } i, j
\end{aligned}
$$

### 📊 Slide 12/20 — **Initial Simplex Tableau**

This slide introduces the **Simplex Tableau**, the core data structure of the Simplex Method.

---

### 🧾 What the Tableau Represents

The simplex tableau encodes:

* The current **basic variables** (slack variables at first)
* The **right-hand side** values (resource availability)
* The **coefficients** of the decision variables in constraints
* The **reduced costs** (from the objective function)

---

### 📋 Initial Tableau Structure

| **B** | **xB** | a₁  | a₂  | a₃  | a₄  | a₅  | u₁ | u₂ | u₃ |
| ----- | ------ | --- | --- | --- | --- | --- | -- | -- | -- |
| u₁    | 24     | 1   | 2   | 1   | 3   | 0   | 1  | 0  | 0  |
| u₂    | 43     | 0   | 1   | 1   | 5   | 1   | 0  | 1  | 0  |
| u₃    | 18     | 1   | 0   | 0   | 2   | 2   | 0  | 0  | 1  |
| **z** | 0      | −19 | −23 | −15 | −42 | −33 | 0  | 0  | 0  |

---

### 📘 Explanation

* **B** = current basic variables (slack vars initially: u₁ = s₁, u₂ = s₂, u₃ = s₃)
* **xB** = values of the basic variables (24, 43, 18)
* **a₁–a₅** = coefficients of variables $x_1$ to $x_5$
* **u₁–u₃** = identity columns for slack variables
* **z row** = reduced costs (cᵢ – zᵢ) — here it's simply –cᵢ since $x_i = 0$

---

### 🔍 Meaning

This tableau represents an initial basic feasible solution:

* $x_1 = x_2 = x_3 = x_4 = x_5 = 0$
* $s_1 = 24,\ s_2 = 43,\ s_3 = 18$
* $z = 0$

From here, the **Simplex algorithm** will iteratively improve the solution by pivoting.

Shall we proceed to Slide 13 and look at the conditions for optimality and unboundedness?


### 📊 Slide 14/20 — **Tétel: A szimplex tábla három esete (Dantzig)**

**(Theorem: The Three Cases of the Simplex Tableau)**

This is a **fundamental result** in the Simplex Method introduced by George Dantzig. It classifies what to do based on the entries in the **bottom row** of the tableau (the reduced cost row).

---

### 📘 The Three Cases:

#### ✅ **Case 1 – Optimality Reached:**

> **"Ha a legalsó sorban nincs negatív szám..."**
> **If there are *no negative numbers* in the bottom row**, i.e., all reduced costs are non-negative:

* ⇒ **The current solution is optimal**.
* No improving direction exists — we’ve reached the best possible $z$.

---

#### ❌ **Case 2 – Unbounded Objective Function:**

> **"...de az összes ilyen oszlopban... nincs pozitív szám..."**
> If **there is a negative reduced cost** (improvement seems possible), **but all entries above it in that column are ≤ 0**, then:

* ⇒ **The LP is unbounded above**.
* We can increase the entering variable indefinitely, and the objective value $z \to \infty$.
* This is a warning: **no finite optimal solution exists**.

---

#### 🔁 **Case 3 – Continue Pivoting (Most Common):**

> **"Egyébként..."**
> If there is a **negative number in the bottom row** *and* the column above it contains a **positive entry**:

* ⇒ We can perform a **pivot** (basis exchange),
* This keeps the solution **feasible** (thanks to the minimum ratio rule),
* And **improves** the objective value (or at least doesn't worsen it),
* ⇒ Proceed with the next simplex iteration.

---

### ❓ **Why is this useful?**

* It tells us **when to stop** (Case 1),
* **When the problem is unbounded** (Case 2),
* And **when to continue iterating** (Case 3).

This logic is applied repeatedly in the Simplex Method until an optimal solution is found or unboundedness is detected.

Would you like to simulate these three cases with numerical tableau examples next?

Great! Let's explain the **Minimum Ratio Rule**, a key decision step in the Simplex Method used when **pivoting**.

---

### 🎯 **Purpose of the Minimum Ratio Rule**

When you have chosen a **column** to enter the basis (because its reduced cost is negative, meaning it can improve the objective), you now need to decide:

> **Which row (i.e., basic variable) should leave the basis?**

This is where the **Minimum Ratio Rule** comes in.

---

### 📐 **How the Rule Works**

For each row (constraint), compute the ratio:

$$
\text{Ratio} = \frac{\text{Right-Hand Side (xB value)}}{\text{Corresponding positive coefficient in the pivot column}}
$$

Only compute this **if the pivot column's entry in that row is > 0** — we **ignore nonpositive values** (since they can’t restrict increasing the entering variable).

---

### ✅ **Choose the Row with the Smallest Ratio**

* The row with the **smallest non-negative ratio** determines the **pivot row**.
* This ensures:

  * The new solution remains **feasible** (non-negative values),
  * We increase the entering variable **as much as possible** without violating constraints.

---

### 🧮 **Example**

Suppose you're bringing in $x_2$ because its reduced cost is negative.

And your tableau has:

| Row | RHS (xB) | Coefficient in $x_2$ column | Ratio        |
| --- | -------- | --------------------------- | ------------ |
| R1  | 24       | 2                           | 12           |
| R2  | 43       | 1                           | 43           |
| R3  | 18       | 0                           | ✖️ (ignored) |

Since 0 can't be used, we **ignore R3**.
From R1 and R2, the smallest ratio is **12**, so **Row 1** is the pivot row.

---

### 🔒 Why This Works

The **minimum ratio ensures** that:

* We don’t "over-assign" a variable,
* All values in the next basic solution remain **≥ 0** (feasible).

Would you like to see a worked-out example using this rule with real values?





### 📊 Slide 15/20 — **Szimplex módszer (Prímál szimplex módszer második fázisa)**

**(Simplex Method – Primal Simplex, Phase Two)**

This slide explains **how the Simplex method iteratively improves the solution** in its second phase.

---

### 🛠️ **Core Concepts**

1. **Báziscseréket végzünk**
   → We perform **basis exchanges** (pivoting).

2. **Megengedettség fenntartása**
   → We must ensure that the **current solution remains feasible**, i.e., all components of $x \geq 0$.
   ✅ This is ensured by the **minimum ratio rule**.

3. **Célfüggvény növelése (ha lehet)**
   → To **increase the objective function** (maximize profit), we:

   * Select a column where the **reduced cost is negative**.
   * Bring this variable into the basis (pivot **into** this column).

4. **Optimalitás kritériuma**
   → If **no reduced cost is negative** (i.e., all ≥ 0), then:

   * 🏁 We have reached **optimality**.
   * The current solution is **optimal**, so the algorithm **stops**.

5. **Állítás**

   > "A szimplex módszer véges sok lépésben véget ér"
   > → The **Simplex method terminates in a finite number of steps**
   > ✅ And usually does so **quickly in practice**.

---

### 📌 Summary

This slide describes the **core decision logic** of each Simplex iteration:

* When to pivot
* When to stop
* Why the method doesn’t go on forever

Would you like to see an animation or code version of this logic in action?



Great! Let's implement a **code version** of the **Primal Simplex Method (Phase 2)** that reflects the logic from Slide 15/20.

---

### ✅ Python Implementation (Basic Version)

This version:

* Solves LPs in standard form (`Ax = b`, `x ≥ 0`, `maximize cᵀx`)
* Uses **tableau-based pivoting**
* Implements the **minimum ratio rule**
* Stops when all reduced costs are non-negative (optimality)

---

```python
import numpy as np

def simplex(c, A, b):
    m, n = A.shape

    # Add slack variables to A
    A_slack = np.hstack([A, np.eye(m)])
    c_extended = np.hstack([c, np.zeros(m)])

    # Initial tableau
    tableau = np.zeros((m + 1, n + m + 1))
    tableau[:m, :n + m] = A_slack
    tableau[:m, -1] = b
    tableau[-1, :n + m] = -c_extended

    basis = list(range(n, n + m))  # Indices of slack variables

    def pivot(tableau, row, col):
        tableau[row] /= tableau[row, col]
        for r in range(len(tableau)):
            if r != row:
                tableau[r] -= tableau[r, col] * tableau[row]

    while True:
        # Step 1: Find entering variable (most negative cost coefficient)
        col = np.argmin(tableau[-1, :-1])
        if tableau[-1, col] >= 0:
            break  # Optimal reached

        # Step 2: Find leaving variable using minimum ratio rule
        ratios = [
            tableau[i, -1] / tableau[i, col] if tableau[i, col] > 0 else np.inf
            for i in range(m)
        ]
        row = np.argmin(ratios)
        if ratios[row] == np.inf:
            raise Exception("Unbounded solution")

        # Step 3: Pivot
        pivot(tableau, row, col)
        basis[row] = col

    # Extract solution
    x = np.zeros(n + m)
    for i in range(m):
        x[basis[i]] = tableau[i, -1]

    return x[:n], tableau[-1, -1]

# Example usage
c = np.array([19, 23, 15, 42, 33])
A = np.array([
    [1, 2, 1, 3, 0],
    [0, 1, 1, 5, 1],
    [1, 0, 0, 2, 2]
])
b = np.array([24, 43, 18])

solution, optimal_value = simplex(c, A, b)
print("Optimal solution:", solution)
print("Optimal value z =", optimal_value)
```

---

### 🧪 Output for the Example Problem

This matches the setup from slides 5–15, and should return:

```plaintext
Optimal solution: [ 0.  0. 24.  0.  9.]
Optimal value z = 657.0
```

Would you like a C++ version too?




Here's a **C++ implementation** of the **Primal Simplex Method (Phase 2)** that mirrors the logic from the slides — especially slide 15/20 — and the Python version I just provided.

---

### ✅ C++ Code (Simplex Method)

This implementation:

* Solves LPs in standard form
* Uses tableau-based pivoting
* Handles slack variables
* Stops when the reduced costs are non-negative

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

typedef vector<double> Row;
typedef vector<Row> Matrix;

void pivot(Matrix &tableau, int pivotRow, int pivotCol) {
    int m = tableau.size();
    int n = tableau[0].size();

    double pivotElement = tableau[pivotRow][pivotCol];
    for (int j = 0; j < n; ++j)
        tableau[pivotRow][j] /= pivotElement;

    for (int i = 0; i < m; ++i) {
        if (i != pivotRow) {
            double factor = tableau[i][pivotCol];
            for (int j = 0; j < n; ++j)
                tableau[i][j] -= factor * tableau[pivotRow][j];
        }
    }
}

pair<vector<double>, double> simplex(const Matrix &A, const Row &b, const Row &c) {
    int m = A.size();       // number of constraints
    int n = A[0].size();    // number of original variables

    // Build initial tableau
    Matrix tableau(m + 1, Row(n + m + 1, 0.0)); // +slacks +RHS
    vector<int> basis(m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            tableau[i][j] = A[i][j];
        tableau[i][n + i] = 1.0;         // slack variable
        tableau[i].back() = b[i];        // RHS
        basis[i] = n + i;
    }

    for (int j = 0; j < n; ++j)
        tableau[m][j] = -c[j];

    // Simplex loop
    while (true) {
        int pivotCol = -1;
        for (int j = 0; j < n + m; ++j) {
            if (tableau[m][j] < -1e-9) {
                pivotCol = j;
                break;
            }
        }

        if (pivotCol == -1)
            break; // Optimal reached

        double minRatio = numeric_limits<double>::infinity();
        int pivotRow = -1;
        for (int i = 0; i < m; ++i) {
            if (tableau[i][pivotCol] > 1e-9) {
                double ratio = tableau[i].back() / tableau[i][pivotCol];
                if (ratio < minRatio) {
                    minRatio = ratio;
                    pivotRow = i;
                }
            }
        }

        if (pivotRow == -1) {
            cerr << "Unbounded solution!" << endl;
            exit(1);
        }

        pivot(tableau, pivotRow, pivotCol);
        basis[pivotRow] = pivotCol;
    }

    // Extract solution
    vector<double> x(n, 0.0);
    for (int i = 0; i < m; ++i) {
        if (basis[i] < n)
            x[basis[i]] = tableau[i].back();
    }

    double z = tableau[m].back();
    return {x, z};
}

int main() {
    Matrix A = {
        {1, 2, 1, 3, 0},
        {0, 1, 1, 5, 1},
        {1, 0, 0, 2, 2}
    };

    Row b = {24, 43, 18};
    Row c = {19, 23, 15, 42, 33};

    auto [solution, z] = simplex(A, b, c);

    cout << "Optimal solution:\n";
    for (double val : solution)
        cout << fixed << setprecision(4) << val << " ";
    cout << "\nOptimal value z = " << fixed << setprecision(4) << z << endl;

    return 0;
}
```

---

### 🧪 Output for This Problem:

```plaintext
Optimal solution:
0.0000 0.0000 24.0000 0.0000 9.0000 
Optimal value z = 657.0000
```

Would you like this version to also **print each tableau step** (like in the lecture slides)?

16/20:



### 📊 Slide 16/20 — **Pivotálás: Minimum szabály és sorátalakítás lépései**

This slide gives a detailed, **step-by-step walkthrough of how a pivot operation is performed** in the Simplex Method using the **minimum ratio rule**.

---

### 🎯 Scenario

We are pivoting **column $a_2$** into the basis (because its reduced cost is most negative).
We apply the **minimum ratio rule** to determine which row to pivot on.

#### 📐 Step 1: Apply Minimum Ratio Rule

We look at the RHS values (basic variable values) and the pivot column values:

$$
\min\left\{ \frac{24}{2}, \frac{43}{1} \right\} = \frac{24}{2} = 12
$$

* We choose the **row where the ratio is minimum**, so the **pivot row is the first** (RHS = 24, column value = 2).
* So $u_1$ leaves the basis, and $a_2$ enters.

---

### 🔁 Step 2: Perform the Pivot Operation

Let the **pivot element** be $a = 2$. The pivot element is at the intersection of the entering column and the leaving row.

We do:

1. **Divide the entire pivot row** by the pivot element:
   → normalize the row so the pivot becomes 1.

2. **Row operations for the rest:**

   * Subtract:

     * $\frac{1}{2} \times \text{pivot row}$ from the second row (since $a_{2,2} = 1$),
     * $\frac{0}{2} \times \text{pivot row}$ from the third row (since $a_{3,2} = 0$),
     * $\frac{-23}{2} \times \text{pivot row}$ from the objective row (i.e., **add** $\frac{23}{2} \times$ pivot row).

These are standard **elementary row operations** in simplex tableau transformation.

---

### 🤓 How Did We Get These Coefficients?

* From the pivot column: take the values **above and below the pivot**.
* Divide each by the **pivot element** (denominator is always the pivot).

So:

* 1/2 from second row: (43 → 1 in that column)
* 0/2 from third row: (18 → 0 in that column)
* −23/2 from objective row (because reduced cost for $a_2$ was −23)

---

This process updates the tableau so that:

* The new basic variable is $x_2$
* The solution remains feasible
* And the objective value **improves**

Would you like the updated tableau after this transformation, as shown on Slide 17?

### 📊 Slide 17/20 — **Simplex Tableau After First Pivot (a₂ enters, u₁ leaves)**

This slide shows the **before-and-after** effect of performing one pivot operation in the Simplex method, using the **minimum ratio rule** and pivot transformations explained in Slide 16.

---

### 🔁 **Before Pivot (ez volt)**

| B  | xB | a₁  | a₂  | a₃  | a₄  | a₅  | u₁ | u₂ | u₃ |
| -- | -- | --- | --- | --- | --- | --- | -- | -- | -- |
| u₁ | 24 | 1   | 2   | 1   | 3   | 0   | 1  | 0  | 0  |
| u₂ | 43 | 0   | 1   | 1   | 5   | 1   | 0  | 1  | 0  |
| u₃ | 18 | 1   | 0   | 0   | 2   | 2   | 0  | 0  | 1  |
| z  | 0  | −19 | −23 | −15 | −42 | −33 | 0  | 0  | 0  |

→ You selected **a₂ to enter the basis**.
→ Using **min(24/2, 43/1) = 12**, row u₁ is chosen to leave.

---

### ✅ **After Pivot (ez lett)**

| B  | xB  | a₁    | a₂ | a₃   | a₄    | a₅  | u₁   | u₂ | u₃ |
| -- | --- | ----- | -- | ---- | ----- | --- | ---- | -- | -- |
| a₂ | 12  | 1/2   | 1  | 1/2  | 3/2   | 0   | 1/2  | 0  | 0  |
| u₂ | 31  | −1/2  | 0  | 1/2  | 7/2   | 1   | −1/2 | 1  | 0  |
| u₃ | 18  | 1     | 0  | 0    | 2     | 2   | 0    | 0  | 1  |
| z  | 276 | −15/2 | 0  | −7/2 | −15/2 | −33 | 23/2 | 0  | 0  |

You now have:

* **a₂ in the basis** with value 12
* **Objective function value increased to 276**
* **Still negative reduced costs** → Continue

---

### ➡️ Next Step

> "Most válasszuk az a₅ vektort a bázisba belépőnek. A minimum szabály szerint u₃ hagyja el a bázist."

This means:

* **a₅ enters**, and using the minimum ratio rule, **u₃ leaves** the basis.

The next tableau (on Slide 18) will show the result of this pivot.

Would you like a walkthrough of this next pivot step as well?


### 📊 Slide 18/20 — **Second Pivot: a₅ Enters, u₃ Leaves**

This slide presents the **next Simplex iteration**, showing the transformation after pivoting **a₅ into the basis**, replacing **u₃**.

---

### 🔁 **Before the Pivot (ez volt):**

| B  | xB  | a₁    | a₂ | a₃   | a₄    | a₅  | u₁   | u₂ | u₃ |
| -- | --- | ----- | -- | ---- | ----- | --- | ---- | -- | -- |
| a₂ | 12  | 1/2   | 1  | 1/2  | 3/2   | 0   | 1/2  | 0  | 0  |
| u₂ | 31  | −1/2  | 0  | 1/2  | 7/2   | 1   | −1/2 | 1  | 0  |
| u₃ | 18  | 1     | 0  | 0    | 2     | 2   | 0    | 0  | 1  |
| z  | 276 | −15/2 | 0  | −7/2 | −15/2 | −33 | 23/2 | 0  | 0  |

* **Pivot column:** a₅ (because −33 is the most negative in the z-row)
* **Pivot row (using minimum ratio rule):**
  From a₅ column: 31/1 = 31, 18/2 = 9 → minimum is 9 → **u₃** leaves

---

### ✅ **After the Pivot (ez lett):**

| B  | xB  | a₁  | a₂ | a₃   | a₄   | a₅ | u₁   | u₂ | u₃   |
| -- | --- | --- | -- | ---- | ---- | -- | ---- | -- | ---- |
| a₂ | 12  | 1/2 | 1  | 1/2  | 3/2  | 0  | 1/2  | 0  | 0    |
| u₂ | 22  | −1  | 0  | 1/2  | 5/2  | 0  | −1/2 | 1  | −1/2 |
| a₅ | 9   | 1/2 | 0  | 0    | 1    | 1  | 0    | 0  | 1/2  |
| z  | 573 | 9   | 0  | −7/2 | 51/2 | 0  | 23/2 | 0  | 33/2 |

---

### 🔍 Interpretation

* **New basic variables**: a₂, a₅, u₂
* **Objective value (z)** has increased from **276 to 573**
* Only one negative reduced cost remains: **−7/2 for a₃** → might still improve

---

Would you like to go through Slide 19/20, where the next and final pivot leads to the **optimal solution**?


### 📊 Slide 19/20 — **Last Negative Reduced Cost and Basis Degeneracy Check**

This slide sets up the **final pivot** and offers a general summary of how the **objective function behaves** during Simplex steps.

---

### 🔴 One Last Negative Entry

> „Egyetlen negatív szám maradt az alsó sorban…”
> There is **one negative reduced cost** left in the bottom row — it will guide the next pivot.

* That column’s variable **enters** the basis
* According to the minimum ratio rule, **a₂ leaves** the basis

---

### 🔁 **How the Objective Function Changes**

Depending on which variable enters the basis:

* 🔺 If the **reduced cost is negative**,
  → the objective function **usually increases**.

* 🔻 If the **reduced cost is positive**,
  → the objective function **usually decreases**.

* ➖ If the **reduced cost is zero**,
  → the objective function **does not change**.

These rules **hold only if the solution is non-degenerate**.

---

### 🧮 **Degeneracy Note**

A **degenerate solution** occurs if **any basic variable value is zero**.

But here:

> „Jelenleg B(a₂, u₂, a₅)… és minden érték x₂, s₂, x₅ közül pozitív”
> → The current basis contains $a_2, u_2, a_5$, and all corresponding basic values are **positive**.

✅ So, the current solution is **non-degenerate**, and we can expect:

* The pivot to succeed,
* The objective to **strictly improve**.

---

### 👀 What’s Next?

> "Lássuk mi történik a báziscsere után"
> Let’s now look at the **final tableau** on Slide 20, which will give us the **optimal solution**.
> Would you like to continue to that?


### 📊 Slide 20/20 — **Final Pivot → Optimal Solution**

This final slide shows the **last step of the Simplex method**, where the optimal solution is reached.

---

### 🔁 Before (ez volt):

| B  | xB  | a₁  | a₂ | a₃   | a₄   | a₅ | u₁   | u₂ | u₃   |
| -- | --- | --- | -- | ---- | ---- | -- | ---- | -- | ---- |
| a₂ | 12  | 1/2 | 1  | 1/2  | 3/2  | 0  | 1/2  | 0  | 0    |
| u₂ | 22  | −1  | 0  | 1/2  | 5/2  | 0  | −1/2 | 1  | −1/2 |
| a₅ | 9   | 1/2 | 0  | 0    | 1    | 1  | 0    | 0  | 1/2  |
| z  | 573 | 9   | 0  | −7/2 | 51/2 | 0  | 23/2 | 0  | 33/2 |

→ **a₃** has a negative reduced cost (−7/2), so it **enters the basis**
→ Use minimum ratio rule to find pivot row: a₂ leaves

---

### ✅ After (ez lett):

| B  | xB  | a₁   | a₂ | a₃ | a₄ | a₅ | u₁ | u₂ | u₃   |
| -- | --- | ---- | -- | -- | -- | -- | -- | -- | ---- |
| a₃ | 24  | 1    | 2  | 1  | 3  | 0  | 1  | 0  | 0    |
| u₂ | 10  | −3/2 | −1 | 0  | 1  | 0  | −1 | 1  | −1/2 |
| a₅ | 9   | 1/2  | 0  | 0  | 1  | 1  | 0  | 0  | 1/2  |
| z  | 657 | 25/2 | 7  | 0  | 36 | 0  | 15 | 0  | 33/2 |

---

### 🧮 Final Result

$$
\boxed{
x_B = (0,\ 0,\ 24,\ 0,\ 9\ \mid\ 0,\ 10,\ 0)
}
$$

* Produce **24 units of T3** and **9 units of T5**
* Do **not produce** T1, T2, T4
* **10 units of resource 2 remain unused**
* **Objective value (profit)** is $z = \boxed{657}$

---

### ✅ Summary:

* The solution is **optimal**
* The basis is **non-degenerate**
* The method terminated with all **reduced costs ≥ 0**

Would you like to see this final result plotted, summarized in LaTeX, or encoded into a solver script?
