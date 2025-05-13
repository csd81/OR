Here is the full **Markdown version** of your handwritten solution from all 3 pages, preserving the **original Hungarian text** and structure:

---

## **Modell:**

```plaintext
0x₁ + 2x₂ + 4x₃ + 7x₄ ≤ 35  
3x₁ + 7x₂ + 2x₃ + 2x₄ ≥ 65  
7x₁ + 7x₂ + 0x₃ + 7x₄ = 32  
x ≥ 0  
z = 10x₁ + 15x₂ + 12x₃ + 11x₄ → max
```

---

## **Standard alak:**

```plaintext
0x₁ + 2x₂ + 4x₃ + 7x₄ + 7x₅         = 35  
3x₁ + 7x₂ + 2x₃ + 2x₄ – x₆ + y₁     = 65  
7x₁ + 7x₂ + 0x₃ + 7x₄        + y₂   = 32  
x ≥ 0  
z = 10x₁ + 15x₂ + 12x₃ + 11x₄ → max
```

---

## **I. fázis feladata:**

```plaintext
z* = –y₁ – y₂ → max  
x ≥ 0, y ≥ 0
```

**A mátrix:**

```
[ 0 2 4 7 1 0 0 ]  
[ 3 7 2 2 0 –1 1 ]  
[ 7 7 0 7 0 0 1 ]
```

---

## **I. fázis I. simplex táblája:**

| B   | x\_B | a₁ | a₂ | a₃ | a₄ | a₅ | a₆ | y₁ | y₂ |
| --- | ---- | -- | -- | -- | -- | -- | -- | -- | -- |
| a₅  | 35   | 0  | 2  | 4  | 7  | 1  | 0  | 0  | 0  |
| a₆  | 65   | 3  | 7  | 2  | 2  | 0  | –1 | 1  | 0  |
| y₂  | 32   | 7  | 7  | 0  | 7  | 0  | 0  | 0  | 1  |
| z\* | –97  | –4 | –2 | –2 | –3 | 0  | 1  | 0  | 0  |

---

## **További táblák és pivotlépések** (részletek számsorokkal, például):

```plaintext
λ = min { 35/2, 65/7, 32/7 } = 32/7  
λ = min { 35/2, 65/7, 32/2 } = 16  
λ = min { 31/1, 20/1, 15/1 } = 15  
...
```

---

## **Optimális megoldás:**

**Utolsó simplex tábla:**

| B  | x\_B | a₁ | a₂ | a₃ | a₄ | a₅  | a₆   |
| -- | ---- | -- | -- | -- | -- | --- | ---- |
| a₃ | 46   | 0  | 0  | 1  | 0  | 7/6 | –1/6 |
| a₁ | 32   | 1  | 0  | 0  | 0  | 2/3 | –1/3 |
| a₆ | 45   | 0  | 0  | 0  | 1  | 2/3 | 1/3  |
| z  | 427  | 0  | 0  | 0  | 0  | 3/2 | 0    |

---

### **Egyedüli optimális megoldás:**

$$
z_{\text{max}} = 427  
x_{\text{opt}} = \left( 32,\ 0,\ 46,\ 0,\ 0,\ \frac{97}{2} \right)
$$

---

### **Válasz: Az optimális megoldás:**

* **Összes haszon: 427**
* Az **1. termékből 32-t** gyártunk.
* A **2. termékből nem gyártunk semmit**.
* A **3. termékből 46-ot** gyártunk.
* Az **1. erőforrást teljesen** felhasználjuk.
* A **2. erőforrást pontosan fel lehet használni**.
* Nincs alternatív optimum: **elérhetetlen**.

---

Let me know if you’d like this exported as `.md`, `.pdf`, or `.tex` format!


---

## I. fázis – I. Simplex-tábla:

| B   | x_B | a₁ | a₂ | a₃ | a₄ | a₅ | a₆ | y₁ | y₂ |
|-----|-----|----|----|----|----|----|----|----|----|
| a₅  | 35  | 0  | 2  | 4  | 7  | 1  | 0  | 0  | 0  |
| a₆  | 65  | 3  | 7  | 2  | 2  | 0  | –1 | 1  | 0  |
| y₂  | 32  | 7  | 7  | 0  | 7  | 0  | 0  | 0  | 1  |
| z*  | –97 | –4 | –2 | –2 | –3 | 0  | 1  | 0  | 0  |

---

## Pivotlépések:

### Következő tábla:

| B   | x_B | a₁ | a₂ | a₃ | a₄ | a₅ | a₆ | y₁ | y₂ |
|-----|-----|----|----|----|----|----|----|----|----|
| a₅  | 3   | 0  | 1  | 2  | 2  | 1  | 0  | 0  | 0  |
| a₆  | 31  | 1  | 0  | 0  | 1  | 0  | 1  | 0  | 0  |
| y₂  | 31  | 1  | 0  | 0  | 1  | 0  | 0  | 0  | 1  |
| z*  | –3  | –1 | –1 | –2 | 0  | 0  | 0  | 0  | 0  |

---

## II. fázis kezdete:

### Célfüggvény:
