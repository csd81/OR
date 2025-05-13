 
# SZÁLLÍTÁSI FELADAT

 


|       | b₁=10 | b₂=11 | b₃=13 | b₄=18 | b₅=15 | Supply (aᵢ) |
|-------|-------|-------|-------|-------|-------|----------|
| a₁=15 | x₁₁=1 | x₁₂=3 | x₁₃=2 | x₁₄=5 | x₁₅=4 | 15            |
| a₂=17 | x₂₁=3 | x₂₂=8 | x₂₃=2 | x₂₄=1 | x₂₅=3 | 17            |
| a₃=23 | x₃₁=1 | x₃₂=4 | x₃₃=2 | x₃₄=5 | x₃₅=1 | 23            |
| a₄=12 | x₄₁=3 | x₄₂=5 | x₄₃=1 | x₄₄=8 | x₄₅=7 | 12            |
|       |  10  | 11   | 13   | 18   |  15  | **Total: 67**|

 

---

1. Egyféle árut szállítunk  
2. Minden sor megfelel egy raktárnak  
3. Minden oszlop megfelel egy boltnak  
4. A raktárkészlet megegyezik a bolt összes igényével

---

## FELADAT:
Döntsük el, hogy melyik raktárból melyik boltba mennyit szállítsunk úgy, hogy:
- a raktárkészletet nem léphetjük túl  
- minden bolt kapja meg, amit igényelt  
- az összes költség minimális legyen
 
 
 
 
 
# 1) A feladat modellje:

\[
\begin{cases}
\sum_j x_{ij} = a_i \quad (\forall i) \\
\sum_i x_{ij} = b_j \quad (\forall j) \\
x \geq 0 \\
\sum_{ij} c_{ij} x_{ij} \rightarrow \min
\end{cases}
\]

### Szimplex tábla (2. fázisban):

A táblázat dimenziója: (4 x 5=20) változó
             
    Ax = b   
    x ≥ 0    
 z = cᵀx → min 


---

Állítás: Ez egy **L.P.** (lineáris programozási feladat)

Állítás: Az együttható mátrix rangja: **n + m - 1**

---

# 2) Kétfázisú módszerrel oldjuk meg a feladatot:

- **1. fázis:** megengedett bázismegoldás előállítása  
- **2. fázis:** báziscserékkel optimális megoldás megadása

### Az első fázis algoritmusa:

- **É–NY-i módszer** ← *most ezt használjuk*
- **Sor-minimum módszer**
- **Tábla-minimum módszer**
- **Vogel–Korda**



 
 3

Here is a **Markdown transcription** of the image showing the **1. fázis** (initial feasible solution) and **2. fázis** (optimization via Stepping Stone or MODI):

---

## 1. fázis

Initial solution (É–NY-i módszer – Northwest Corner Method):

|       | **1**  | **3**  | **2**  | **5**  | **4**  | **Supply** |
| ----- | ------ | ------ | ------ | ------ | ------ | ---------- |
| **1** | 10     | 5      |        |        |        | 15 5   |
| **3** |        | 6      | 11     |        |        | 17 11   |
| **1** |        |        | 2      | 18     | 3      | 23 21 3   |
| **3** |        |        |        |        | 12     | 12         |
|       | **10** | **11** | **13** | **18** | **15** | **Σ = 67** |
|       |       |  6      |  2      |       | 12      |            |

---

## 2. fázis

Testing optimality via a closed loop adjustment (Stepping Stone):

|       | **1** | **3** | **2** | **5** | **4** |
| ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | 10    | 5     |       |       |       |
| **3** |       | 6     | 11    | x     |       |
| **1** |       |       | 2     | 18    | 3     |
| **3** |       |       |       |       | 12    |

**Cycle**:

* Start at (2,4) = x
* -1 → (2,3) = 11
* +1 → (3,3) = 2
* -1 → (3,4) = 18

**Net cost change**:

$$
1 - 5 + 2 - 2 = -4 < 0 \Rightarrow \text{jó csere}
$$

This means the solution can be improved by pushing flow along this loop.

Here is a clean and complete **Markdown OCR transcription** of the provided handwritten page (Stepping Stone method with explanation and failed improvement):

---

## Stepping Stone Method – 2. Fázis folytatás

### Matrix with cycle (closed path):

|       | **1** | **3** | **2** | **5** | **4** |
| ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | 10    |   5+  | -- x  |       |       |
| **3** |       |   6+  | --+-- | --+11 |       |
| **1** |       |       |   13--| --+7  |  3    |
| **3** |       |       |       |       | 12    |

Cycle cost calculation (Stepping Stone test):

$$
2 - 2 + 5 - 1 + 8 - 3 = 9 > 0 \Rightarrow \text{nem jó csere 
$$

---

## Elméleti háttér:

**Báziscella (kő)**: ahol szállítunk valamit
**Algoritmus neve**: *Stepping Stone*

### Kör (cycle):

* nem körből indulunk
* felváltva lépünk függőlegesen és vízszintesen
* csak kövekre szabad lépni
* visszaérünk oda, ahonnan indultunk

---

### Állítások:

* Tetszőleges nem kőből indulva pontosan **1 kör** van.
* Ha nincs javító csere, akkor **optimális a megoldás**.

---

### Segéd algoritmus: segít megtalálni a javítócserét

* minden sorhoz: $u_i$
* minden oszlophoz: $v_j$
* Egyenlet:

  $$
  u_i + v_j = c_{ij} \quad \forall (i, j) \in B
  $$
* Az egyenletrendszernek mindig van megoldása és **a szabadságfoka 1**.

 
 
 Here is a structured **Markdown transcription** of the handwritten MODI method tableau and evaluations shown in the image.

---

## MODI method tableau (potential values and reduced cost calculations)

### Step 1: Matrix of allocations (from previous feasible solution)

|        | **v₁** | **v₂** | **v₃** | **v₄** | **v₅** |
| ------ | ------ | ------ | ------ | ------ | ------ |
| **u₁** | 10     | 5      |        |        |        |
| **u₂** |        | 6      |        | 11     |        |
| **u₃** |        |        | 13     | 7      | 3      |
| **u₄** |        |        |        |        | 12     |

---

### Step 2: Potentials

$$
v₁ = 1, \quad v₂ = 3, \quad v₃ = -7, \quad v₄ = -4, \quad v₅ = -8
$$

$$
u₁ = 0, \quad u₂ = 5, \quad u₃ = 9, \quad u₄ = 15
$$

---

### Step 3: Reduced cost evaluation (cᵢⱼ - uᵢ - vⱼ)

|        | 1  | 3  | 2  | 5  | 4  |
| ------ | -- | -  | -- | -- | -- |
| **0**  | X  | X  | +  | +  | +  |
| **5**  | 18/-3 | X  | +  | X  | +  |
| **9**  | 54/-9 | 48/-8 | X | X  | X  |
| **15** | 78/-13 | 78/-13 | 84/-7 | 27/-3 | X |

### Evaluations:

Right side:

1.sor 
* `2 - (-7) - 0 = 9` → ✅
* `5 - (-4) - 0 = 9` → ✅
* `4 - (-8) - 0 = 12` → ✅

2.sor 
* `3 - 1 - 5 = -3` → ❌
* `2 - (-7) - 5 = 4` → ✅
* `3 - (-8) - 5 = 7` → ✅
* `1 - 1 - 9 = -9` → ❌
* `4 - 3 - 9 = -8` → ❌

3.sor 
* `3 - 1 - 15 = -13` → ❌
* `5 - 3 - 15 = -13` → ❌

4.sor 
* `8 - (-4) - 15 = -3` → ❌
* `8 - (-4) - 15 = -3` → ❌

---

### Step 4: Cell costs (cᵢⱼ)

From bottom-left:

```
3 × 6 = 18  
6 × 9 = 54  
8 × 6 = 48  
13 × 6 = 78  
7 × 12 = 84  
3 × 7 = 21  
```

These are probably actual cost contributions of filled cells for computing total cost.

---

Let me know if you want the **next step of the optimization**, like applying the best improvement or computing the **total transportation cost** from this tableau.


Here is a clean **Markdown transcription** of the provided image that walks through the **Vogel–Korda (VAM)** method for finding an initial feasible solution to the transportation problem:

---

## Állítás:

A redukált költség számolása:

$$
c_{ij}' = c_{ij} - (u_i + v_j)
$$

---

## Vogel–Korda módszer lépései:

### Kiindulási táblázat:



   | 1 / 4 | 3 / 11| 2     | 5     | 4      | 15 | 2-1=1
   | 3     | 8     | 2     | 1 / 17| 3      | 17 | 2-1=1
   | 1 / 6 | 4     | 2 / 1 | 5 / 1 | 1 / 15 | 23 | 1-1=0
   | 3     | 5     | 1 / 12| 8     | 7      | 12 | 3-1=2
   | 10    | 11    | 13    | 18    | 15     | Σ = 67 |
   |1-1=0 | 4-3=1  |2-1=1  | 5-4=1 | 3-2=1  |
---

### Különbségek:

We compute the penalty (difference between two lowest costs) for each row and column:

* Rows:

  * Row 1: 4 - 3 = 1
  * Row 2: 2 - 1 = 1
  * Row 3: 1 - 1 = 0
  * Row 4: 1 - 3 = 2 ← largest (③)

* Columns:

  * Col 1: 3 - 1 = 2
  * Col 2: 4 - 3 = 1
  * Col 3: 2 - 1 = 1
  * Col 4: 5 - 4 = 1
  * Col 5: 3 - 2 = 1

---

### Algoritmus lépései:

1. **Felírjuk** soronként és oszloponként a 2 legkisebb költség különbségét
2. **Kiválasztjuk** a legnagyobbat
3. A **legolcsóbb cellát megkeressük**
4. **Elvisszük annyit, amennyit lehet**

---

### Megjegyzés:

> **Nem képes mindig optimális megoldást találni.**

---


Here's a complete and accurate **Markdown transcription** of the final solution matrix and its evaluation:

---

## Optimal Solution (Final Tableau)

### Allocation Table:

|        | **1** | **3** | **2** | **5** | **1** |
| ------ | ----- | ----- | ----- | ----- | ----- |
| **0**  | 4     | 11    |     .  |   .    |  +    |
| **–4** | +     |  +     |  +     | 17    | +      |
| **0**  | 6     |  +     | 1     | 1     | 15    |
| **–1** |  +     |  +     | 12    | +      |  +     |

---

### Evaluation:

This is both a **valid basic feasible solution** and also an **optimal solution**.

### Objective function calculation:

$$
z = 1 \cdot 4 + 3 \cdot 11 + 1 \cdot 17 + 2 \cdot 1 + 5 \cdot 1 + 1 \cdot 15 + 1 \cdot 12 = \boxed{88}
$$

---

**Note**: The coefficients used in the cost function match the original cost matrix values from the Vogel-Korda method.

Let me know if you want to visualize this in C++ or simulate the full Vogel + MODI algorithm step-by-step.
