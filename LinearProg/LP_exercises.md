Here is the **markdown version** of the PDF titled *"A production problem and the Primal Simplex method"* by György Dósa:

---

# A Production Problem and the Primal Simplex Method

### Sample and Exercises

**György Dósa – February 17, 2022**

---

## Problem Data:

|        | P1 | P2 | P3 | P4 | Capacity |
| ------ | -- | -- | -- | -- | -------- |
| Res1   | 1  | 2  | 1  | 2  | 40       |
| Res2   | 1  | 0  | 1  | 1  | 38       |
| Res3   | 1  | 1  | 3  | 2  | 26       |
| Profit | 11 | 15 | 14 | 18 |          |

---

## Step 1: Write the Model

Constraints:

```
x1 + 2x2 + x3 + 2x4 ≤ 40  
x1 +     + x3 + x4 ≤ 38  
x1 + x2 + 3x3 + 2x4 ≤ 26  
xj ≥ 0  for j = 1..4  
```

Objective function:

```
Maximize z = 11x1 + 15x2 + 14x3 + 18x4
```

---

## Step 2: Standard Form

Introduce slack variables $s_1, s_2, s_3$:

```
x1 + 2x2 + x3 + 2x4 + s1 = 40  
x1      + x3 + x4 + s2 = 38  
x1 + x2 + 3x3 + 2x4 + s3 = 26  
xj, sj ≥ 0  
```

Objective remains:

```
Maximize z = 11x1 + 15x2 + 14x3 + 18x4
```

---

## Step 3: Initial Simplex Tableau

| B  | xB | a1  | a2  | a3  | a4  | u1 | u2 | u3 |
| -- | -- | --- | --- | --- | --- | -- | -- | -- |
| u1 | 40 | 1   | 2   | 1   | 2   | 1  | 0  | 0  |
| u2 | 38 | 1   | 0   | 1   | 1   | 0  | 1  | 0  |
| u3 | 26 | 1   | 1   | 3   | 2   | 0  | 0  | 1  |
| z  | 0  | -11 | -15 | -14 | -18 | 0  | 0  | 0  |

---

## Step 4: Basis Transformations

### Preprocessing:

We compute the possible increments for choosing each entering variable:

* **a1**: $\frac{26}{1} = 26$
* **a2**: $\frac{40}{2} = 20$
* **a3**: $\frac{26}{3} ≈ 8.67$
* **a4**: $\frac{26}{2} = 13$

→ Best increment: a2 → Entering variable
→ Pivot row: u1

### New Tableau:

| B  | xB  | a1   | a2 | a3    | a4 | u1   | u2 | u3 |
| -- | --- | ---- | -- | ----- | -- | ---- | -- | -- |
| a2 | 20  | 1/2  | 1  | 1/2   | 1  | 1/2  | 0  | 0  |
| u2 | 38  | 1    | 0  | 1     | 1  | 0    | 1  | 0  |
| u3 | 6   | 1/2  | 0  | 5/2   | 1  | -1/2 | 0  | 1  |
| z  | 300 | -7/2 | 0  | -13/2 | -3 | 15/2 | 0  | 0  |

---

### Next Step:

Again evaluate:

* **a1**: $\frac{6}{1/2} = 12$
* **a3**: $\frac{6}{5/2} = 2.4$
* **a4**: $\frac{6}{1} = 6$

→ Best: a1 → Pivot row: u3

### New Tableau:

| B  | xB  | a1 | a2 | a3 | a4 | u1 | u2 | u3 |
| -- | --- | -- | -- | -- | -- | -- | -- | -- |
| a2 | 14  | 0  | 1  | -2 | 0  | 1  | 0  | -1 |
| u2 | 26  | 0  | 0  | -4 | -1 | 1  | 1  | -2 |
| a1 | 12  | 1  | 0  | 5  | 2  | -1 | 0  | 2  |
| z  | 342 | 0  | 0  | 11 | 4  | 4  | 0  | 7  |

---

### Optimality Check

All reduced costs (bottom row) are non-negative → **Optimal Solution Reached**

---

## Step 5: Evaluation

**Optimal solution:**

```
x = (12, 14, 0, 0 | 0, 26, 0), z = 342
```

* Produce:

  * 12 units of P1
  * 14 units of P2
* No units of P3 or P4
* 26 units of resource 2 remain unused
* z = 342

---

## Exercises

### 1)

|        | P1 | P2 | P3 | P4 | Capacity |
| ------ | -- | -- | -- | -- | -------- |
| Res1   | 1  | 2  | 1  | 2  | 40       |
| Res2   | 1  | 0  | 1  | 1  | 10       |
| Res3   | 1  | 1  | 3  | 2  | 26       |
| Profit | 11 | 15 | 28 | 18 |          |

→ $x_{\text{OPT}} = (0, 9.45, \frac{12}{5}, 0 \mid 0, 3.85, 0)$, $z_{\text{OPT}} = 349.2$

---

### 2)

|        | P1 | P2 | P3 | P4 | Capacity |
| ------ | -- | -- | -- | -- | -------- |
| Res1   | 1  | 2  | 1  | 2  | 40       |
| Res2   | 1  | 0  | 1  | 1  | 10       |
| Res3   | 1  | 1  | 3  | 2  | 15       |
| Profit | 11 | 5  | 28 | 18 |          |

→ $x_{\text{OPT}} = (\frac{15}{2}, 0, \frac{5}{2}, 0 \mid 30, 0, 0)$, $z_{\text{OPT}} = 152.5$

---

### 3)

|        | P1 | P2 | P3 | P4 | P5 | Capacity |
| ------ | -- | -- | -- | -- | -- | -------- |
| Res1   | 1  | 1  | 2  | 1  | 1  | 25       |
| Res2   | 0  | 1  | 0  | 1  | 2  | 42       |
| Res3   | 1  | 0  | 1  | 3  | 1  | 50       |
| Profit | 12 | 8  | 15 | 17 | 22 |          |

→ Multiple optima:
$x_{\text{OPT}_1} = (4, 0, 0, 0, 21 \mid 0, 0, 25)$
$x_{\text{OPT}_2} = (0, 0, 0, 8, 17 \mid 0, 0, 9)$
General solution:

$$
x_{\text{OPT}} = \lambda \cdot x_{\text{OPT}_1} + (1-\lambda) \cdot x_{\text{OPT}_2}, \quad 0 \leq \lambda \leq 1
$$

$$
z_{\text{OPT}} = 510
$$

---

Let me know if you'd like this markdown exported as a `.md` file or converted to another format like LaTeX or HTML.
