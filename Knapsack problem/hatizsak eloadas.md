The document you uploaded is a lecture-style explanation of the **Knapsack problem**, particularly focused on solving it using **Branch and Bound (B\&B)**, with examples and strategy outlines. Here's a structured explanation of the key parts:

---

## 🧳 **Knapsack Problem Overview**

We are given:

* A set of items, each with a **weight (capacity used)** and a **value (profit or usefulness)**.
* A **knapsack** (bag) with limited capacity (`k`), e.g., `k = 15`.

The **goal**:
Select a subset of items to **maximize total value**, without exceeding the knapsack’s capacity.

---

## 🔢 **Mathematical Formulation**

### Decision Variables:

Let `x_i ∈ {0, 1}` — where

* `x_i = 1` means item `i` is included in the knapsack,
* `x_i = 0` otherwise.

### Constraints:

* Weight constraint: `w1*x1 + w2*x2 + ... + wn*xn ≤ k`
* Objective: `z = v1*x1 + v2*x2 + ... + vn*xn → max`

This is a classic **0-1 Integer Linear Programming** problem (NP-hard).

---

## ⚙️ **Relaxed Problem**

To make it easier to solve (e.g. for estimation), we **relax** the constraint `x_i ∈ {0, 1}` to `x_i ∈ [0, 1]`.
This gives an **upper bound** for the original problem's solution.

### Greedy Relaxation:

* Items are sorted by **value per unit weight** (fajlagos haszon).
* We add as much of each item as possible to the knapsack in that order.
* If the next full item doesn't fit, we include a **fraction** of it (if allowed).

This gives an upper bound like `z = 97.5`, even if the actual max integer solution is lower (e.g. `z = 92`).

---

## 🌲 **Branch and Bound Strategy**

The algorithm explores a **solution tree**:

* Each node is a partial solution (bitvector like `x = (1,1,0,1,...)`).
* We compute bounds for each branch.

### Main components:

1. **Feasible Set**: tracks remaining possibilities.
2. **Bounding Function**: estimates best value (e.g., by relaxation).
3. **Branching**: split solution into sub-cases (include item vs exclude item).
4. **Pruning**:

   * If the bound is worse than the best known solution, discard.
   * If constraints are inconsistent (e.g. over capacity), discard.

Termination: when all sets are either evaluated or pruned.

---

## 🧪 **Example Tree Exploration**

Bitvectors are used to represent item selection:

* `(1,1,1,1,0,0)` → items 1–4 included, 5–6 excluded.
* Nodes are evaluated with their objective values (`z = ...`).
* The method computes a **gap** between upper bound and best solution found.

---

## 🧮 **Felsőkorlátos Hátizsák (Upper Bound Variant)**

A variation includes **item multiplicities** (e.g. you can include 2 units of item 2), and the relaxed problem may allow **non-integer values** for estimates.

In this variant:

* `x_i` can take values like 1.5 or 2.0 (for estimating only).
* Final decision variables remain integer in the solution.

---

## 🧠 **Key Takeaways**

* **Relaxation** gives **upper bounds**.
* **Branch & Bound** systematically explores only **promising branches**.
* **Greedy heuristics** help in quickly estimating relaxed solutions.
* **Optimality** is confirmed when no branch has better bound than current best.

---

Would you like a full implementation of this strategy in C++ or Python with a branching tree and bound tracker?



# DISZKRÉT PROGRAMOZÁS

## 🎒 Hátizsák feladat

| haszon | 8 | 35 | 13 | 36 | 22 | 15 |
|--------|---|----|----|----|----|----|
| súly   | 1 | 5  | 2  | 6  | 4  | 3  |

📦 **Kapacitás**: `k = 15`

---

**Válogassuk ki a tárgyakat úgy, hogy a haszon legyen maximális és a kapacitást ne lépjük túl!**

---

### B&B – Branch and Bound – Korlátozás és szétválasztás algoritmus

---

### ① Változókat vezetünk be!

\[
x_i = \begin{cases}
1, & \text{ha az } i. \text{ tárgyat bepakoljuk} \\
0, & \text{egyébként}
\end{cases}
\]

---

### ② Modell felírása:

\[
\begin{cases}
1x_1 + 5x_2 + 2x_3 + 6x_4 + 4x_5 + 3x_6 = 15 \\
x_i \in \{0,1\}, \quad i = 1, \ldots, 6 \\
Z = 8x_1 + 35x_2 + 13x_3 + 36x_4 + 22x_5 + 15x_6 \to \max
\end{cases}
\]

📌 **NP-teljes feladat**

---

### ③ A feladat relaxációja:

\[
\begin{cases}
1x_1 + 5x_2 + 2x_3 + 6x_4 + 4x_5 + 3x_6 = 15 \\
0 \leq x_i \leq 1, \quad i = 1, \ldots, 6 \\
Z = 8x_1 + 35x_2 + 13x_3 + 36x_4 + 22x_5 + 15x_6 \to \max
\end{cases}
\]

---

**Fajlagos haszon:**  
\[
\frac{\text{haszon}}{\text{súly}}
\]




## Állítás:

Tegyük fel, hogy a tárgyak a **fajlagos haszon szerint csökkenő sorrendben** vannak.  
(Ha nem, sorbarendezzük.)

**Ekkor a relaxált feladat megoldása a következő:**

Ebben a sorrendben belepakolom a tárgyakat a zsákba, amíg belefér.  
Ha a következő nem fér bele, de marad hely, akkor tört szerint kipótoljuk.

\[
x^{opt} = (1, 1, 1, 1, \frac{1}{2}, 0)
\]

\[
Z = 92 + 5{,}5 = 97{,}5
\]

---

Tekintsünk egy olyan feladatot, ahol a célfüggvényt maximalizáljuk és tekintsük a feladatnak valamely **relaxációját**.

---

### Állítás:

Ekkor a relaxált feladat optimális megoldásának értéke legalább akkora,  
mint az eredeti feladat optimális megoldásának értéke.

---

### gap:





Here's the **Markdown (MD)** version of the third page of the knapsack presentation, preserving the **original Hungarian text and diagram-like layout**:

---

```markdown
## B & B algoritmikus stratégiája:

### ①
\[
x = (1,1,1,1,\frac{1}{2},0) \quad Z = 92 + 5{,}5 = 97{,}5
\]

📌 `gap`  
```

74           94     97
alsó korlát     ↑     felső korlát
jelenlegi legjobb

```

---

### x₅ = 0 →  
\[
x = (1,1,1,1,0,1) \quad Z = 92 + 5 = 97
\]

### x₅ = 1 →  
\[
x = (1,1,1,1,1,0) \quad Z = 78 + 18 = 96
```

---

#### x₄ = 0 →

$$
x = (1,1,1,0,0,1) \quad Z = 71 + 24 = 95
$$

#### x₄ = 1 →

$$
x = (1,1,1,0,1,0) \quad Z = 93
$$

---

#### x₂ = 1

$$
x = (1,1,1,0,0,1) \quad Z = 71
$$

#### x₄ = 1

$$
x = (1,1,0,1,0,1) \quad Z = 94
$$

---

#### x = (1,0,1,1,1,0) → Z = 79 + 10 = 89

#### x = (0,1,0,1,1,0) → Z = 93

---

## 🧩 A módszer 4 összetevője:

1. **Alaphalmaz**
   (összes megengedett megoldás)

2. **Célfüggvény becslése**

3. **Szétválasztási stratégia**

   * mindig azt a halmazt osztjuk tovább, ahol a Z a legnagyobb
   * amelyik halmaznál a becslés rosszabb, mint ami a legjobb megoldás, azt kidobjuk
   * ha nincs több koordináta, ott nem osztunk tovább

4. **Megengedettség vizsgálat**

   * ahol ellentmondásosak a feltételek, azt kidobjuk

---

🛑 Akkor van vége a feladatnak, ha a megtalált eddigi legjobb
és az összes élő halmaz maximuma találkozik.

```

---

Would you like this turned into a full printable `.md` file or continue to the next slide?
```



Here's the **Markdown (MD)** version of the fourth page, preserving the **text and visual structure** from your "felsőkorlátos hátizsák feladat" slide:

---

```markdown
## 🎒 *Felsőkorlátos hátizsák feladat*

### Adatok:

| h  | 2 | 1 | 3 |
|----|---|---|---|
| a  | 3 | 2 | 5 |

📦 **Kapacitás**: `k = 16`  
📌 `gap`:  
```

128        154          156.2
↓          ↑             ↑
alsó        legjobb     felső
korlát      megoldás     korlát

```

---

### 🌳 Fa bejárása:

#### ①
\[
x = (1, 1, 2, \frac{3}{5}) \quad Z = 128 + 28{,}2 = 156{,}2
\]

---

#### x₃ = 1 →  
\[
x = (1, 2, 1) \quad Z = 128
\]

#### x₃ = 2 →  
\[
x = (1, 1.5, 2) \quad Z = 145 + 10 = 155
\]

---

#### x₂ = 2 →  
\[
x = (1, 1, 2.5) \quad Z = 145 + 9{,}4 = 154{,}4
\]

#### x = (0, 2, 2)  
\[
Z = 154 \quad \text{egyetlen optimális megoldás}
\]

---

#### x₃ = 3 →  
\[
x = (1, 1, 2) \quad Z = 145
\]

\[
x = (2, 1, 0{,}3) \quad Z = 141 + 10{,}5 = 151{,}5
\]

---

## ℹ️ Ugyanez a feladat, de k = 17

---

Valamely csúcsban relaxált feladat optimális megoldását így számítjuk:

1. **Amit muszáj, beletesszük a zsákba**

2. **3 lehetőség van**:
   - a) Amit be kellene tenni a zsákba, de **nem fér be** → nincs megengedett megoldás  
   - b) Amit be kellene tenni a zsákba, és **pont belefér** → megvan az optimális megoldás  
   - c) Amit be kellene tenni a zsákba, és **maradt hely** → balról jobbra haladva feltöltjük, többet nem viszünk, és a **felső korlátra figyelünk**
```

---

Would you like me to merge all pages into one complete `.md` file next?


Here is the **Markdown (MD)** version of the final page you uploaded, preserving the **original Hungarian content and the visual layout**:

---

```markdown
## 🧮 FELADAT:

### Adatok 1:

| h   | 30 | 42 | 49 | 38 | 54 | 41 |
|-----|----|----|----|----|----|----|
| s   | 5  | 3  | 2  | 4  | 2  | 3  |
| db  | #5 | 3  | 2  | 4  | 2  | 3  |

📦 `k = 17`  
🔢 haszon: `10 12 9.5 9.5 8.2 9`

---

### Adatok 2:

| h   | 12 | 30 | 19 | 38 | 54 | 41 |
|-----|----|----|----|----|----|----|
| s   | 5  | 1  | 3  | 2  | 4  | 5  |

📦 `k = 17`  
📌 `gap`:
```

153          156         158        161.2
↓             ↑                     ↑
alsó        legjobb                 felső
korlát       megoldás                korlát

```

---

### 🌳 Megoldási fa:

#### ①
\[
x = (1,1,1,1,1,\frac{1}{5}) \quad Z = 153 + 8{,}2 = 161{,}2
\]

---

#### x₆ = 0 →  
\[
x = (1,1,1,1,1,0) \quad Z = 153
\]

#### x₆ = 1 →  
\[
x = (1,1,1,1,1,1) \quad Z = 140 + 18 = 158
\]

---

#### x₅ = 0 →  
\[
x = (1,1,1,0,1,1) \quad Z = 140
\]

#### x₅ = 1 →  
\[
x = (1,1,1,0,1,1) \quad Z = 156
\]

---

### ℹ️ Ugyanez a feladat, de **k = 15**
```

---

Would you like me to now merge all converted pages into one complete `.md` file or export it for you?







