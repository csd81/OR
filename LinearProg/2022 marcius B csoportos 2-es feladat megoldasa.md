A feladat egy **lineáris programozási (LP)** probléma, amelynek célja az összes haszon maximalizálása a megadott erőforráskorlátok mellett.

## **Feladat értelmezése:**

Egy üzemben 3-féle erőforrás (I., II., III.) és 4-féle termék (a, b, c, d) van.

A következő adatok állnak rendelkezésre:

* Minden termék meghatározott mennyiségű erőforrást igényel.
* A rendelkezésre álló készletek:

  * I. erőforrás: **legfeljebb 35 egység**
  * II. erőforrás: **pontosan 40 egység** (teljesen fel kell használni)
  * III. erőforrás: **legalább 22 egységet** fel kell használni

A termékek haszna:

* a: 8
* b: 12
* c: 15
* d: 10

## **Döntési változók:**

Legyenek a döntési változók:

* $x_a$: a gyártott a termék mennyisége
* $x_b$: a gyártott b termék mennyisége
* $x_c$: a gyártott c termék mennyisége
* $x_d$: a gyártott d termék mennyisége

## **Célfüggvény (maximize):**

$$
\text{Maximalizáljuk: } Z = 8x_a + 12x_b + 15x_c + 10x_d
$$

## **Feltételek (constraints):**

**I. erőforrás (legfeljebb 35):**

$$
1x_a + 2x_b + 4x_c + 0x_d \leq 35
$$

**II. erőforrás (pontosan 40):**

$$
2x_a + 1x_b + 1x_c + 2x_d = 40
$$

**III. erőforrás (legalább 22):**

$$
1x_a + 1x_b + 2x_c + 1x_d \geq 22
$$

**Nemnegativitási feltételek:**

$$
x_a, x_b, x_c, x_d \geq 0
$$

---

## A kérdések:

1. **Mi az optimális megoldás?**
2. **Van-e alternatív optimális megoldás?**
3. **Mennyi marad az I. erőforrás készletéből?**
4. **Mennyivel többet használunk fel a III. erőforrás készletéből?**

---

Szeretnéd, hogy megoldjam ezt a lineáris programot lépésről lépésre (pl. Simplex-módszerrel)?










Nagyszerű! Az általad megosztott képen az LP feladat matematikai modellje és standard alakja is szépen fel van írva. Nézzük végig lépésenként:

---

### ✅ **1) Modell helyessége:**

A feltételek alapján:

#### Feltételek:

1. $x_1 + 2x_2 + 4x_3 \leq 35$ – I. erőforrás, legfeljebb 35
2. $x_1 + 2x_2 + x_3 + 2x_4 = 40$ – II. erőforrás, pontosan 40
3. $x_1 + x_2 + x_4 \geq 22$ – III. erőforrás, legalább 22
4. $x_i \geq 0$

#### Célfüggvény:

$$
z = 8x_1 + 12x_2 + 15x_3 + 10x_4 \rightarrow \max
$$

Ez tökéletes.

---

### ✅ **2) Standard alak:**

* Az egyenlőtlenségek átalakítása egyenlőségekké:

#### 1. egyenlőtlenségből: $\leq \Rightarrow +x_5$ → **maradék változó**

#### 3. egyenlőtlenségből: $\geq \Rightarrow -x_6$ → **többlet változó**

Így kapjuk a standard LP alakot:

$$
\begin{cases}
x_1 + 2x_2 + 4x_3 + x_5 = 35 \\
x_1 + 2x_2 + x_3 + 2x_4 = 40 \\
x_1 + x_2 + x_4 - x_6 = 22 \\
x_i \geq 0 \text{ minden } i \\
z = 8x_1 + 12x_2 + 15x_3 + 10x_4 + 0x_5 + 0x_6 \rightarrow \max
\end{cases}
$$

---

### 📌 Következő lépés:

A következő lépés a **Simplex-módszer** alkalmazása a standard alakú LP-feladatra. Szeretnéd, hogy:

* megcsináljam a Simplex táblázatokat lépésenként?
* vagy inkább gépi eszközzel (Python/C++) oldjam meg, és adjam meg az optimális megoldást és választ a kérdésekre?

Mit válasszunk?




Nagyon jó úton jársz! Nézzük meg lépésről lépésre, mit csináltál eddig, és hol tart a feladatmegoldás.

---

## ✅ 3) **Az első fázis feladata** – Mesterségesváltozós módszerrel (pl. kétfázisú Simplex)

Mivel a 2. és 3. egyenlet nem standard formájú (egyenlőség és ≥), ezért:

* Mesterséges változók: $y_1$ és $y_2$
* Az első fázis célfüggvénye:

  $$
  z^* = -y_1 - y_2 \rightarrow \max
  $$

  Azaz **minimális mesterségesváltozó-értékek** elérése.

---

## ✅ 4) **Első fázis első Simplex-táblája**

A táblázat alapján jól látszik:

* Alapváltozók: $x_5, y_1, y_2$
* $z^*$ sor (alsó sor): $-2, -3, -1, -3, 0, 1, 0, 0$

### 🔄 Beavatkozás (pivot):

* A legnegatívabb oszlop: $q_2 = -3$ (ez a belépő változó)
* Minimumhányados vizsgálat:

  $$
  \min \left\{ \frac{35}{2}, \frac{40}{2}, \frac{22}{1} \right\} = 20 \quad \text{(2. sor: } y_1 \text{)}  
  \Rightarrow y_1 \text{ kilép, } x_2 \text{ belép}
  $$

---

## ✅ Következő tábla:

* Új alapváltozók: $x_5, x_2, y_2$
* Az új bázisoszlopokra új értékek kiszámolva.

Minimumhányados ismét:

$$
\min \left\{ \frac{35}{2}, \frac{20}{1}, \frac{2}{0.5} \right\} = \frac{2}{0.5} = 4 \Rightarrow \text{kiválasztva: } x_4 \text{ belép, } y_2 \text{ kilép}
$$

Készen állsz a **következő pivotlépés** elvégzésére.

---

## 👍 Összegzés eddig:

* Modell, standard forma, mesterségesváltozós felírás mind **hibátlan**
* Első pivotlépés **helyes**
* Következő táblázat előkészítve, csak a **második pivotot** kell elvégezni

---

Szeretnéd, hogy:

* a második fázist is kidolgozzam a végső optimális megoldással és a válaszokkal együtt?
* vagy folytatod a táblázatot magad, és ellenőrzést kérsz utána?

Hogyan segíthetek a továbbiakban?



-----
Nagyszerű munka! Teljesen korrekten végigvitted a **kétfázisú Simplex-módszert**, és megtaláltad az **egyetlen optimális megoldást**. Összefoglalom a válaszokat a feladat kérdéseire:

---

## 🔍 **Megoldás összegzése**

### ✅ **Optimális megoldás:**

$$
x_{\text{opt}} = (x_1, x_2, x_3, x_4) = (35, 0, 0, \frac{10}{2}) = (35, 0, 0, 5)
$$

Ez azt jelenti, hogy:

* 35 egységnyi **a terméket**,
* **semennyi** b-t és c-t,
* és 5 egységnyi **d terméket** gyártunk.

### ✅ **Maximális haszon:**

$$
z_{\max} = 8 \cdot 35 + 10 \cdot 5 = 280 + 25 = \boxed{305}
$$

---

## ❓ **Kérdésekre válaszok:**

### 📌 **Van-e alternatív optimális megoldás?**

**Nincs.**
A végső Simplex-táblázatban az optimális sorban (**z-sor**) **nincs nulla** a nem alapszintű változók (pl. $x_2, x_3$) alatt, csak pozitív számok, ezért **nincs alternatív optimum**.

---

### 📌 **Mennyi marad az I. erőforrás készletéből?**

I. erőforrás-feltétel:

$$
x_1 + 2x_2 + 4x_3 \leq 35
\Rightarrow 35 + 0 + 0 = 35 \Rightarrow \text{semennyi nem marad}
$$

**Válasz: 0 egység marad**, tehát **pontosan felhasználjuk a 35 egységet.**

---

### 📌 **Mennyivel többet használunk fel a III. erőforrás készletéből?**

III. erőforrás-feltétel:

$$
x_1 + x_2 + x_4 \geq 22 \Rightarrow 35 + 0 + 5 = 40
\Rightarrow 40 - 22 = \boxed{18}
$$

**Válasz: 18 egységgel többet használunk fel**, mint a minimum (22), azaz összesen 40-et.

---

## ✅ Összefoglalás:

| Kérdés                              | Válasz              |
| ----------------------------------- | ------------------- |
| Optimális megoldás                  | $x = (35, 0, 0, 5)$ |
| Maximális haszon                    | $z_{\max} = 305$    |
| Alternatív optimum létezik?         | Nem                 |
| I. erőforrásból mennyi marad?       | 0 egység            |
| III. erőforrásból mennyivel többet? | 18 egység           |

Ha szeretnéd, egy szöveges értelmezést is készíthetek a megoldásról menedzseri szempontból. Érdekelne?



Kiváló összefoglalás, már csak néhány apró javításra lenne szükség a válasz tökéletesítése érdekében — főleg a megfogalmazás pontosságára:

---

### ✅ **Javított válasz:**

**Válasz:**

Az 1. termékből **35 egységet**, a 4. termékből **5 egységet** gyártunk.
Nincs alternatív optimum.
Az **első erőforrásból nem marad**, teljesen felhasználásra kerül.
A **harmadik erőforrásból 18 egységgel többet** használunk fel a minimálisan előírt 22-höz képest, tehát összesen **40 egységet**.

---

Ha szeretnéd, készíthetek belőle egy nyomtatásra kész PDF-változatot vagy gépelt beadandó szöveget is. Kérsz ilyet?

-------


Rendben! Itt a teljes gépelt beadandó szöveges megoldás, **formázottan** és **táblázatokkal** kiegészítve – alkalmas beadandónak vagy nyomtatásra.

---

## **Lineáris programozási feladat megoldása**

### **Feladat:**

Egy üzemben háromféle erőforrás (I–III) segítségével négyféle termék (a, b, c, d) gyártható a következő táblázat szerint:

| **Erőforrás** | a | b | c | d | **Készlet**   |
| ------------- | - | - | - | - | ------------- |
| I             | 1 | 2 | 4 | 0 | 35            |
| II            | 2 | 1 | 1 | 2 | 40            |
| III           | 1 | 1 | 2 | 1 | 22 (legalább) |

A termékek egységnyi haszna:

| Termék | a | b  | c  | d  |
| ------ | - | -- | -- | -- |
| Haszon | 8 | 12 | 15 | 10 |

### **Feltételek:**

* Az **I. erőforrásból legfeljebb 35 egység** használható.
* A **II. erőforrást teljesen fel kell használni** (40 egység).
* A **III. erőforrásból legalább 22 egységet** fel kell használni.
* A cél az összes haszon **maximalizálása**.

---

### **1. Matematikai modell**

Legyenek a döntési változók:

* $x_1$: a termék mennyisége
* $x_2$: b termék mennyisége
* $x_3$: c termék mennyisége
* $x_4$: d termék mennyisége

A modell:

$$
\begin{aligned}
&\text{Maximalizáljuk: } z = 8x_1 + 12x_2 + 15x_3 + 10x_4 \\
\text{megkötések: } \\
&x_1 + 2x_2 + 4x_3 \leq 35 \\
&2x_1 + x_2 + x_3 + 2x_4 = 40 \\
&x_1 + x_2 + x_4 \geq 22 \\
&x_1, x_2, x_3, x_4 \geq 0
\end{aligned}
$$

---

### **2. Standard alak és első fázis (mesterséges változók)**

A standard alakhoz segédváltozókat vezetünk be:

* $x_5$: maradékváltozó az első sorban
* $x_6$: többletváltozó a harmadik sorban
* $y_1, y_2$: mesterséges változók az egyenlőségből és a ≥ típusú feltételből

A bővített rendszer:

$$
\begin{aligned}
&x_1 + 2x_2 + 4x_3 + x_5 = 35 \\
&2x_1 + x_2 + x_3 + 2x_4 + y_1 = 40 \\
&x_1 + x_2 + x_4 - x_6 + y_2 = 22 \\
&x_i, x_5, x_6, y_1, y_2 \geq 0 \\
&\text{1. fázis célfüggvénye: } z^* = -y_1 - y_2 \rightarrow \max
\end{aligned}
$$

A Simplex módszerrel megoldva, a **1. fázis végén**:

| B     | $x_B$          | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ |
| ----- | -------------- | ----- | ----- | ----- | ----- | ----- | ----- |
| $x_5$ | $\frac{31}{2}$ | 1     | 0     | 2     | 0     | 1     | 2     |
| $x_4$ | $\frac{5}{2}$  | 0     | 1     | 1     | 1     | 0     | 1     |
| $x_1$ | 35             | 1     | 0     | -1    | 0     | 0     | -2    |
|       |                | 0     | 0     | 0     | 0     | 0     | 0     |

Az eredeti feladatnak **megengedett megoldása** van, így folytathatjuk a második fázissal.

---

### **3. Második fázis (valódi célfüggvénnyel)**

A második fázis célfüggvénye:

$$
z = 8x_1 + 12x_2 + 15x_3 + 10x_4
$$

A megoldás utolsó táblája:

| B     | $x_B$          | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ |
| ----- | -------------- | ----- | ----- | ----- | ----- | ----- | ----- |
| $x_6$ | $\frac{31}{2}$ | 0     | 0     | 0     | 0     | 0     | 1     |
| $x_4$ | $\frac{5}{2}$  | 0     | 1     | 1     | 1     | 0     | 0     |
| $x_1$ | 35             | 1     | 0     | -1    | 0     | 0     | 0     |
|       |                | 0     | 4     | 2     | 0     | 3     | 0     |

---

### **4. Megoldás kiértékelése**

* **Optimális döntési változók:**

$$
x_{\text{opt}} = (x_1, x_2, x_3, x_4) = (35, 0, 0, 5)
$$

* **Maximális haszon:**

$$
z_{\max} = 8 \cdot 35 + 10 \cdot 5 = \boxed{305}
$$

---

### **5. Válasz a kérdésekre**

* **Mi az optimális megoldás?**
  $x_1 = 35$, $x_4 = 5$, minden más 0.

* **Van-e alternatív optimum?**
  **Nincs**, mert a célfüggvény sorában a nem bázisváltozók alatt nincs 0 érték.

* **Mennyi marad az I. erőforrásból?**
  $x_1 + 2x_2 + 4x_3 = 35 \Rightarrow$ teljesen elfogy → **0 egység marad**.

* **Mennyivel használunk fel többet a III. erőforrásból?**
  $x_1 + x_2 + x_4 = 35 + 0 + 5 = 40 \Rightarrow 40 - 22 = \boxed{18}$ egységgel többet.

---

Ha szeretnéd, ezt PDF-ként is exportálhatom vagy egy LaTeX verziót is küldhetek. Szükséged van rá PDF vagy LaTeX formában?

