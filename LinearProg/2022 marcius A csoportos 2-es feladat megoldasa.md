Here is the **Markdown version** of the content from the image you provided:

---

## **2. (20 pont)**

Egy üzemben háromféle erőforrás (I.–III.) segítségével négyféle termék (a, b, c, d) gyártható a táblázat adatainak megfelelően.

* Az első erőforrásból **legfeljebb 34 egység** használható fel.
* A második erőforrást **teljesen fel kell használni**.
* A harmadik erőforrásból **legalább 26 egységet** fel kell használni.

A cél az összes haszon maximalizálása.
**Oldja meg a feladatot!**
Mi az optimális megoldás? Van-e alternatív optimum? Mennyi marad az I. erőforrás készletéből? Mennyivel többet használunk fel a III. erőforrás készletéből?

---

### **Adatok táblázata:**

| **Erőforrás** | a | b  | c  | d  | **Készlet** |
| ------------- | - | -- | -- | -- | ----------- |
| I             | 0 | 2  | 4  | 1  | 34          |
| II            | 1 | 2  | 1  | 2  | 50          |
| III           | 1 | 1  | 0  | 1  | 26          |
| **Haszon**    | 9 | 12 | 15 | 11 |             |

---

## **1) Modell:**

Formális matematikai modell:

```
2x₂ + 4x₃ + x₄         ≤ 34  
x₁ + 2x₂ + x₃ + 2x₄    = 50  
x₁ + x₂       + x₄     ≥ 26  
xᵢ ≥ 0
```

Célfüggvény:

```
z = 9x₁ + 12x₂ + 15x₃ + 11x₄ → max
```

---

## **2) Standard alak:**

Hozzáadott változók:

* $x_5$: maradékváltozó az első egyenlőtlenséghez
* $x_6$: többletváltozó a harmadikhoz

Átalakított rendszer:

```
2x₂ + 4x₃ + x₄ + x₅         = 34  
x₁ + 2x₂ + x₃ + 2x₄         = 50  
x₁ + x₂       + x₄ - x₆     = 26  
xᵢ ≥ 0
```

Célfüggvény (kiterjesztve):

```
z = 9x₁ + 12x₂ + 15x₃ + 11x₄ + 0x₅ - 0x₆ → max
```

---

Let me know if you'd like this turned into a PDF, LaTeX version, or included in a study set.


Here is the **Markdown version** of the content from the image (step 3 and 4 of the simplex method):

---

## **3) Az első fázis feladata**

Formulázzuk a problémát mesterséges változókkal:

```plaintext
x₁ + 2x₂ + 4x₃         + x₅            = 35  
x₁ + 2x₂ + x₃ + 2x₄    + y₁            = 40  
x₁ + x₂       + x₄  - x₆ + y₂          = 22  

xᵢ ≥ 0,    yᵢ ≥ 0

Célfüggvény az első fázisban:
z* = –y₁ – y₂ → max
```

Eredeti célfüggvény egyelőre félretéve:

```plaintext
z = 8x₁ + 12x₂ + 15x₃ + 10x₄ + 0x₅ + 0x₆ → max
```

---

## **4) Az első fázis első Simplex-táblája**

| B   | x\_B | q₁ | q₂ | q₃ | q₄ | q₅ | q₆ | qᵧ₁ | qᵧ₂ |
| --- | ---- | -- | -- | -- | -- | -- | -- | --- | --- |
| q₅  | 35   | 1  | 2  | 4  | 1  | 1  | 0  | 0   | 0   |
| qᵧ₁ | 40   | 1  | 2  | 1  | 2  | 0  | 0  | 1   | 0   |
| qᵧ₂ | 22   | 1  | 1  | 0  | 1  | 0  | -1 | 0   | 1   |
| z\* | –62  | –2 | –3 | –1 | –3 | 0  | 1  | 0   | 0   |

---

### Pivotválasztás:

* Választott belépő változó: **q₂** (legnegatívabb érték: –3)
* Kilépő változó meghatározása (minimumhányados):

$$
\min \left\{ \frac{35}{2}, \frac{40}{2}, \frac{22}{1} \right\} = \frac{40}{2} = 20 \Rightarrow \text{qᵧ₁ kilép}
$$

---

### Új tábla pivot után:

| B   | x\_B | q₁   | q₂ | q₃   | q₄ | q₅ | q₆ | qᵧ₁ | qᵧ₂ |
| --- | ---- | ---- | -- | ---- | -- | -- | -- | --- | --- |
| q₅  | 35   | 1    | 2  | 4    | 1  | 1  | 0  | 0   | 0   |
| q₂  | 20   | 1/2  | 1  | 1/2  | 1  | 0  | 0  | 1   | 0   |
| qᵧ₂ | 2    | 1/2  | 0  | –1/2 | 0  | 0  | –1 | –1  | 1   |
| z\* | –2   | –1/2 | 0  | 1/2  | 0  | 0  | 1  | 0   | 0   |

---

### Következő pivot választása:

Hányados számítás:

* $\lambda_1 = \frac{35}{1} = 35$
* $\lambda_2 = \frac{20}{1/2} = 40$
* $\lambda_3 = \frac{2}{1/2} = 4$

→ **qᵧ₂ kilép**, **q₁** lép be

---

Let me know if you'd like to continue with step 5 or convert the entire solution into LaTeX or PDF format.

Here is the **Markdown version** of the final part of your simplex solution (first phase conclusion and second phase):

---

## **Az első fázis vége**

A következő állapotban vagyunk:

| B     | $x_B$ | $q_1$ | $q_2$ | $q_3$ | $q_4$ | $q_5$ | $q_6$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $q_5$ | 31    | 0     | 2     | 5     | 0     | 1     | 2     |
| $q_4$ | 18    | 0     | 1     | 1     | 1     | 0     | 1     |
| $q_1$ | 4     | 1     | 0     | –1    | 0     | 0     | –2    |
|       |       |       |       |       |       |       |       |

**Következtetések:**

1. Van egy bázisunk.
2. Ismerjük a hozzátartozó bázistáblát.
3. A bázismegoldás megengedett.

➡️ Az **eredeti feladatnak van megengedett megoldása.**

---

## **5) A második fázis**

Célfüggvény:

$$
z = 8x_1 + 12x_2 + 15x_3 + 10x_4
$$

### Simplex-tábla (második fázis elején):

| B     | $x_B$ | $q_1$ | $q_2$ | $q_3$ | $q_4$ | $q_5$ | $q_6$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $q_5$ | 31    | 0     | 2     | 5     | 0     | 1     | 2     |
| $q_4$ | 18    | 0     | 1     | 1     | 1     | 0     | 1     |
| $q_1$ | 4     | 1     | 0     | –1    | 0     | 0     | –2    |
| z     | 305   | 0     | –2    | –13   | 0     | 0     | –6    |

### Pivot választás:

* A legalacsonyabb érték a célfüggvény sorban: **–13** → $q_3$ lép be
* Minimumhányadosok:

$$
\min \left\{ \frac{31}{5}, \frac{18}{1}, \frac{4}{1} \right\} = \frac{2}{1/2} = 4
$$

→ Pivot sor: $q_4$

---

### Utolsó Simplex-tábla (optimum elérve):

| B     | $x_B$          | $q_1$ | $q_2$ | $q_3$ | $q_4$ | $q_5$ | $q_6$ |
| ----- | -------------- | ----- | ----- | ----- | ----- | ----- | ----- |
| $q_6$ | $\frac{31}{2}$ | 0     | 0     | 0     | 0     | 0     | 1     |
| $q_4$ | $\frac{5}{2}$  | 0     | 1     | 0     | 1     | 0     | 0     |
| $q_1$ | 35             | 1     | 0     | 0     | 0     | 0     | 0     |
| z     | 305            | 0     | 4     | 2     | 0     | 3     | 0     |

---

## ✅ **Egyedüli optimális megoldás:**

$$
x_{\text{opt}} = (35,\ 0,\ 0,\ \frac{5}{2}),\quad z_{\max} = 305
$$

---

Let me know if you'd like this entire solution as a PDF, `.md`, or LaTeX version!







Here is the clean and complete **Markdown version** of the final part of the simplex solution from the image you uploaded:

---

## **5) A második fázis**

**Célfüggvény:**

$$
z = 9x_1 + 12x_2 + 15x_3 + 11x_4
$$

---

### **Kezdő Simplex-tábla:**

| B     | $x_B$ | $q_1$ | $q_2$ | $q_3$ | $q_4$ | $q_5$ | $q_6$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $q_5$ | 10    | 0     | 1     | 3     | 0     | 1     | –2    |
| $q_4$ | 24    | 0     | 1     | 1     | 1     | 0     | 1     |
| $q_1$ | 2     | 1     | 0     | –1    | 0     | 0     | –2    |

**Z sor (célfüggvény):**

$$
z = 282,\quad \Delta = [0,\ -1,\ -13,\ 0,\ 0,\ -7]
$$

---

### **Pivotválasztás:**

* Belép: $q_3$ (legnegatívabb reduced cost: –13)
* Hányadosok:

$$
\min\left\{ \frac{10}{3},\ \frac{24}{1},\ \frac{2}{-1} \right\} = \frac{10}{3} ≈ 3.33
\Rightarrow \text{Pivot sor: } q_5
$$

---

### **Következő tábla pivot után:**

| B     | $x_B$ | $q_1$ | $q_2$ | $q_3$ | $q_4$ | $q_5$ | $q_6$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $q_3$ | 34    | 0     | 2     | 1     | 1     | 0     | 0     |
| $q_6$ | 24    | 0     | 1     | 1     | 1     | 0     | 1     |
| $q_1$ | 50    | 1     | 2     | 1     | 2     | 0     | 0     |
| $z$   | 450   | 0     | 6     | –6    | 7     | 0     | 0     |

---

### **Utolsó Simplex-tábla (optimális):**

| B     | $x_B$          | $q_1$ | $q_2$ | $q_3$ | $q_4$          | $q_5$         | $q_6$ |
| ----- | -------------- | ----- | ----- | ----- | -------------- | ------------- | ----- |
| $q_3$ | $\frac{17}{2}$ | 0     | 0     | 1     | 0              | 0             | 0     |
| $q_6$ | $\frac{31}{2}$ | 0     | 1     | 0     | 1              | 0             | 1     |
| $q_1$ | 83             | 1     | 0     | 0     | 3              | 0             | 0     |
| $z$   | 501            | 0     | 9     | 0     | $\frac{17}{2}$ | $\frac{3}{2}$ | 0     |

---

## ✅ **Optimális megoldás:**

$$
x_{\text{opt}} = (83, 0, \frac{17}{2}, 0),\quad z_{\max} = 501
$$

* Az 1. termékből: 83 egység
* A 3. termékből: $\frac{17}{2}$ egység
* Más termékből: 0 egység

**Az I. erőforrást teljesen felhasználjuk**,
**A III. erőforrásból 5 egységgel többet használunk, mint a minimálisan előírt 26**.

---

Let me know if you want this exported to a `.md`, `.tex`, or `.pdf` format!



Here is the **Markdown version** of the solution summary from the image:

---

## **Egyedüli optimális megoldás**

$$
x_{\text{opt}} = \left( \frac{83}{2},\ 0,\ \frac{17}{2},\ 0\ \big|\ 0,\ \frac{31}{2} \right)
$$

$$
z_{\max} = 501
$$

---

### **Értelmezés:**

* A maximális haszon **501**.
* Az **1. termékből** $\frac{83}{2}$ egységet, a **3. termékből** $\frac{17}{2}$ egységet termelünk, a többiből semmit.
* Az **I. erőforrás készletét teljesen** felhasználjuk (0 egység marad belőle).
* A **III. erőforrásból** $\frac{31}{2}$ egységgel többet használunk a minimálisnál.

---

Let me know if you'd like this turned into a full `.md` file or added to a printable document.
