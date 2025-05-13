Ez egy **szállítási feladat** (transportation problem), ahol célunk: az árukészletet a raktárakból a boltokba úgy eljuttatni, hogy az **igények és készletek teljesüljenek**, és **az összköltség minimális** legyen.

A táblázat így néz ki:

### Költségtábla és igények/készletek:

|       | B1 | B2 | B3 | B4 | Készlet |
| ----- | -- | -- | -- | -- | ------- |
| R1    | 8  | 7  | 3  | 2  | 15      |
| R2    | 1  | 4  | 2  | 5  | 43      |
| R3    | 2  | 3  | 4  | 7  | 28      |
| R4    | 1  | 1  | 4  | 4  | 19      |
| Igény | 18 | 32 | 35 | 20 |         |

A raktárak (R1-R4) készletei: `15, 43, 28, 19`
A boltok (B1-B4) igényei: `18, 32, 35, 20`
A szállítási költségek az egyes cellákban vannak.

### Megoldási módszerek, amelyeket a PDF is részletez:

1. **Észak-Nyugati sarok módszer (É-Ny)**
2. **Tábla-minimum (TM) módszer**
3. **Vogel-Korda (VK) módszer**

Ezek közül:

* Az **É-Ny-i módszer** egy egyszerű kezdeti megoldást ad.
* A **TM módszer** már figyelembe veszi a legkisebb költségeket.
* A **VK módszer** még kifinomultabb, "mohósági különbségek" alapján dönt.

### Példa alsó korlátra:

A soronként legkisebb költségek szorzata a készlettel:

* R1: 2×15 = 30
* R2: 1×43 = 43
* R3: 2×28 = 56
* R4: 1×19 = 19

Összesen: **148** — ez az **alsó korlát** az optimális költségre.

Szeretnéd valamelyik módszert konkrétan kiszámolni lépésről lépésre (pl. É-Ny-i, TM vagy VK)?




Köszönöm a pontos képet! Az adatokból most már világosan látszik, hogy ez a **szállítási feladat** a következő formában áll rendelkezésünkre:

---

### 📦 Szállítási költségek táblázata (egységköltségek)

Sorok = Raktárak (R1–R4)
Oszlopok = Boltok (B1–B4)

|        | B1            | B2     | B3     | B4     | **Készlet** |
| ------ | ------------- | ------ | ------ | ------ | ----------- |
| **R1** | 8             | 7      | 3      | 2      | **15**      |
| **R2** | 1             | 4      | 2      | 5      | **43**      |
| **R3** | 2             | 3      | 4      | 7      | **28**      |
| **R4** | 1             | 1      | 4      | 4      | **19**      |
|        | **18**        | **32** | **35** | **20** |             |
|        | ⬅ **Igény** ➡ |        |        |        |             |

---

* A cellák bal felső sarkában az értékek az **egységköltségek** (pl. 1 egység szállításának költsége).
* A sorok végén található számok a **raktárak készleteit** jelentik.
* Az oszlopok alján található számok a **boltok igényeit** mutatják.

---

### Feladat:

Osszuk el az árukészletet a raktárakból a boltokba úgy, hogy

1. minden bolt igénye kielégüljön,
2. egyik raktár se lépje túl készletét,
3. az **összköltség minimális legyen**.

---

Szeretnéd, hogy az **Észak-Nyugati sarok módszer** vagy a **Tábla-Minimum módszer** alapján kiszámítsuk az első megengedett megoldást lépésenként?


A 3/16-os dián szereplő teljes szöveg a következő:

---

### **A szállítási feladat**

**A sorok végén levő szám a raktárkészletet jelenti. Az oszlop alatti szám a bolt igényét. Feltesszük hogy ezek összege megegyezik.**

Tehát például az első bolt igénye 18 egység valamilyen áruból,
és például a harmadik raktár készlete 28, ugyanebből az áruból.
A cellák bal felső sarkaiban levő számok azt jelentik,
hogy a megfelelő viszonylatban 1 egység szállítása mennyibe kerül.

---

Szeretnéd, hogy ezt is markdown táblázattal másolható formában megkapd?







Íme a 4/16-os dia teljes szövege:

---

### **A szállítási feladat**

**A feladat:**
Szállítsuk el az összes árut az adott készletek és igények figyelembe vételével, **minimális összköltséggel**.

---

**Az összes költség** a következőképpen számolandó:
Ha például az első raktárból az első boltba **3 egységet szállítok**,
az **3-szor 8** egységbe kerül.
Ha **5-öt szállítok**, az **5-ször 8** pénzegységbe kerül.

---

Szeretnéd, hogy ebből is készítsek egy gépileg másolható Markdown táblázatot vagy példaszámítást?




A 5/16-os dián látható teljes szöveg a következő:

---

### **Az É-NY-i módszer**

**A feladatot kétfázisú módszerrel oldjuk meg. Első fázisban egy megengedett bázismegoldást állítunk elő.**

---

**Az egyik legegyszerűbb módszer egy megengedett bázismegoldás előállítására az úgynevezett Észak-Nyugat-i módszer.**
A tábla É-Ny-i sarka a bal felső sarok. Itt elszállítunk annyit, amennyit csak lehetséges.
Ez nem lehet több mint **15**, és nem lehet több mint **18**.
Akkor ezek minimuma, azaz **15 egységet szállítunk itt**.

---

A piros **15** a bal felső cellában azt jelzi, hogy onnan történik a szállítás.

Szeretnéd a teljes É-NY-i megoldást lépésről lépésre végigszámolva is látni?



Itt van a szállítási feladat kiinduló állapotának **Markdown táblázata**, az É-NY-i módszer első lépésével (15 egység szállítás R1 ➝ B1):

```markdown
|        | B1  | B2 | B3 | B4 | Készlet |
|--------|-----|----|----|----|---------|
| **R1** | 8 *(15)* | 7  | 3  | 2  | 15 → 0 |
| **R2** | 1   | 4  | 2  | 5  | 43      |
| **R3** | 2   | 3  | 4  | 7  | 28      |
| **R4** | 1   | 1  | 4  | 4  | 19      |
|        | 18 → 3 | 32 | 35 | 20 |       |
```

📝 **Jelmagyarázat**:

* *8 (15)* azt jelenti, hogy a szállítási költség 8, és 15 egységet szállítottunk ide.
* A nyilak jelzik a **készlet** és **igény** frissített értékét.

Szeretnéd, hogy folytassam a teljes É-NY-i módszerrel, lépésenként?



Igen! Itt van a teljes **szöveg** a diáról (6/16. dia – Az É-NY-i módszer):

---

### **Az É-NY-i módszer**

**A szállított mennyiséget „nagy” piros számmal jelöljük, a cella „közepén”.**

---

**Ezzel az első raktár készletét kimerítettük, és az első bolt igényéből is kielégítettünk 15-öt.**
Ezeket a számokat levonjuk az első raktár készletéből és az első bolt igényéből,
a módosult táblázatot mellékeljük itt balra.

Ezek után redukáljuk a táblázatot:
az első sorral már nem kell hogy foglalkozzunk.

**Most a második sor első oszlopa lett az É-Ny-i sarok!**

---

Szeretnéd, hogy folytassam a következő lépés táblázatával és szövegével?


Itt van a dián látható frissített állapot **Markdown táblázatként**, miután az első lépést végrehajtottuk az Észak-Nyugati sarok módszerrel:

```markdown
|        | B1       | B2 | B3 | B4 | Készlet |
|--------|----------|----|----|----|---------|
| **R1** | 8 *(15)* | 7  | 3  | 2  | **0**   |
| **R2** | 1        | 4  | 2  | 5  | **43**  |
| **R3** | 2        | 3  | 4  | 7  | **28**  |
| **R4** | 1        | 1  | 4  | 4  | **19**  |
|        | **3**    | 32 | 35 | 20 |         |
```

📝 **Változások**:

* R1 készlete: `15 → 0`
* B1 igénye: `18 → 3`
* A `15` egység szállítás megtörtént R1 → B1 (költség 15×8)

Szeretnéd, hogy folytassam a következő lépéssel (R2 → B1)?




Természetesen! Itt van a 7/16-os dia teljes szövege és a hozzá tartozó megoldás **Markdown táblázat** formájában:

---

### 📘 **Az É-NY-i módszer**

**Az előbbi módszert ismételgetve (iterálva), megkapjuk az alábbi megoldást.**

**Mint látjuk**, a kapott megoldás nem túl bonyolult.
Mindazáltal, ha a szállítási egységköltségek nagyjából egyenlők lennének (most nem ez a helyzet),
vagy „szerencsés” módon helyezkednének el — tehát éppen olcsó helyeken sikerülne szállítani (most ez sem igaz) —
akkor az É-Ny-i módszer is képes **meglehetősen jó megoldást generálni**.

---

### ✅ Végső megengedett bázismegoldás (É-NY-i módszer):

```markdown
|        | B1       | B2       | B3       | B4       | Készlet |
|--------|----------|----------|----------|----------|---------|
| **R1** | 8 *(15)* | 7        | 3        | 2        | 0       |
| **R2** | 1 *(3)*  | 4 *(32)* | 2 *(8)*  | 5        | 0       |
| **R3** | 2        | 3        | 4 *(27)* | 7 *(1)*  | 0       |
| **R4** | 1        | 1        | 4        | 4 *(19)* | 0       |
|        | 0        | 0        | 0        | 0        |         |
```

📝 **Szállított mennyiségek piros számmal (cellák közepe), költségek feketén (sarokban)**.
Ez 7 darab foglalást jelent (m + n – 1 = 4 + 4 – 1 = **7 bázisváltozó**), tehát megengedett bázismegoldás.

Szeretnéd, hogy most kiszámoljuk az összesített szállítási költséget is?




Íme a 8/16-os dián található teljes szöveg:

---

### **Az É-NY-i módszer**

**Figyeljük meg, hogy pontosan 7 helyen történik szállítás**,
ami a sorok száma plusz oszlopok száma -1.

---

**A kapott megoldás értékét** a következőképpen kapjuk:
8-szor 15, plusz 1-szer 3, stb.

---

### **A kapott érték: 458.**

**Vajon sok ez vagy kevés?**

---

Szeretnéd, hogy most kiszámoljuk az alsó korlátot is az összehasonlításhoz, ahogy a következő diá(k) mutatják?






Itt a 9/16-os dia teljes szövege:

---

### **Az É-NY-i módszer**

#### Egyszerű alsó korlát számolása:

---

Könnyű úgynevezett „alsó korlátot” generálni arra vonatkozólag, hogy **legalább mekkora lesz a minimális költség**.

Erre egy egyszerű módszer a következő:

* Az első sorban a legkisebb egységköltség: **2**
  → minimum fizetendő: `2 × 15`
* A második sorban a legkisebb egységköltség: **1**
  → minimum fizetendő: `1 × 43`
* A harmadik sorban a legkisebb egységköltség: **2**
  → minimum fizetendő: `2 × 28`
* A negyedik sorban a legkisebb egységköltség: **1**
  → minimum fizetendő: `1 × 19`

---

### Alsó korlát = `2×15 + 1×43 + 2×28 + 1×19 = 148`

---

Ez alapján tehát bármely megoldás költsége **nem lehet kisebb 148-nál**.

Szeretnéd most megnézni a Tábla-Minimum módszerrel kapott javított megoldást is?

Íme a 10/16-os dia teljes szövege:

---

### **Az É-NY-i módszer**

**Láttuk, az összes költség, tetszőleges megengedett megoldás esetén legalább 148. Az É-Ny-i módszer által kapott megoldás értéke 458.**

---

**Az előbbinél „jobb” alsó korlátot is megpróbálhatunk meghatározni.**
Ehelyett inkább mutatunk egy **másik módszert**, amely az É-Ny-i módszernél
az esetek többségében **lényegesen hatékonyabb**.

Nevezzük **Tábla-Minimum módszernek**, röviden legyen ez a **TM módszer**.

---

Szeretnéd, hogy most bemutassam a TM módszer szerinti első lépést és a teljes megoldást is táblázatban?

Itt van a 11/16-os dia teljes **szövege** és a hozzá tartozó **Markdown táblázat** a Tábla-Minimum módszer első lépéséről:

---

### **A Tábla-Minimum módszer**

**Kezdjük újra, egy megengedett bázismegoldást állítunk megint elő.**

---

Válasszunk ki egy olyan cellát, ahol a szállítási (egység)költség **minimális**.
Több helyen van **1-es költség**, válasszuk például a második sor első celláját.
Szállítsunk el itt **amennyit csak lehet**, ez **18 egység**.

Utána **redukáljuk a táblázatot**: az oszlop kiesik, a sorban a raktárkészlet **18-cal csökken**.

---

### 🧮 Táblázat (első lépés, TM módszer):

```markdown
|        | B1       | B2 | B3 | B4 | Készlet |
|--------|----------|----|----|----|---------|
| **R1** | 8        | 7  | 3  | 2  | 15      |
| **R2** | 1 *(18)* | 4  | 2  | 5  | 25  (43-18) |
| **R3** | 2        | 3  | 4  | 7  | 28      |
| **R4** | 1        | 1  | 4  | 4  | 19      |
|        | 0 (18-18) | 32 | 35 | 20 |         |
```

🟥 A piros **18** a második sor első cellájában jelzi a szállított mennyiséget (`költség: 1 × 18`).

Szeretnéd a TM módszer következő lépését is látni?







Itt van a 12/16-os dia teljes szövege és a végleges megengedett megoldás **Markdown táblázatként** a **Tábla-Minimum módszerrel**:

---

### **A Tábla-Minimum módszer**

**Folytatva (iterálva) az előző lépést, a következő táblázatot (megengedett bázismegoldást) kapjuk:**

---

**Jegyezzük meg**, hogy ha több cellának van ugyanakkora (és minimális) költsége,
akkor ezek közül **tetszőlegesen választhatunk**.

**A kapott megoldáshoz tartozó célfüggvényérték: 256**,
ami **lényegesen jobb**, mint amit az É-Ny-i módszerrel kaptunk,
és **az alsó korlátunkhoz is közelebb van** (ami 148 volt).

---

### 📊 Megoldás (Tábla-Minimum módszer):

```markdown
|        | B1       | B2       | B3       | B4       | Készlet |
|--------|----------|----------|----------|----------|---------|
| **R1** | 8        | 7        | 3        | 2 *(15)* | 0       |
| **R2** | 1 *(18)* | 4        | 2 *(25)* | 5 *(5)*  | 0       |
| **R3** | 2        | 3 *(13)* | 4 *(10)* | 7 *(5)*  | 0       |
| **R4** | 1        | 1 *(19)* | 4        | 4        | 0       |
|        | 0        | 0        | 0        | 0        |         |
```

📌 **Szállított mennyiségek** pirossal (a cella belsejében), **szállítási költségek** feketén (sarokban).
A teljes költség:

```
1×18 + 2×25 + 5×5 + 3×13 + 4×10 + 7×5 + 1×19 = 256
```

Szeretnéd, hogy összehasonlítsuk ezt a Vogel-módszer (VK) alapján kapott megoldással is?




Íme a teljes szöveg, amely a képen (13/16-os dia) szerepel:

---

### **A Tábla-Minimum módszer**

**Jelenleg azt tudjuk, hogy az optimumérték 148 és 256 között van.**

---

Szállítási költségtábla:

```
8   7   3   2  
1   4   2   5  
2   3   4   7  
1   1   4   4  
```

---

**Még azt is vegyük észre**, hogy mindkét módszer (Észak-Nyugati módszer és TM módszer)
a következő lépések ismétléséből áll:

1. kiválasztunk egy cellát
2. ott a lehető legtöbbet szállítjuk
3. a táblát redukáljuk

---

**Csak az 1. lépésben különböznek.**

Mindkét módszer esetén az igénybe vett cellák száma **7**
(azaz: *sorok száma + oszlopok száma – 1*).

---

Ha kéred, át tudom írni ezt Markdown formába is jegyzetként vagy tananyagként. Szeretnéd?


```
8   7   3   2  
1   4   2   5  
2   3   4   7  
1   1   4   4  
```

Kiváló! Itt van a 14/16-os dia teljes tartalma szépen szerkesztve, ahogy kérted:

---

### **A Vogel-Korda módszer**

Bemutatunk egy **harmadik módszert** is.
Ez is az előbbi 3 lépést iterálja,
és **itt is csak az 1. lépés különbözik** az előzőekhez képest.

---

### 📊 Költségtábla:

```
8   7   3   2  
1   4   2   5  
2   3   4   7  
1   1   4   4  
```

---

**Mindhárom módszer mohó**, vagyis lokálisan a legjobb döntéseket próbálják meghozni.

Ez a harmadik módszer (a **Vogel-Korda**) azonban egy **kicsit kevésbé mohó**, mint az első kettő (É-NY-i és TM).

---

### ❓ Hogyan válasszuk ki az első cellát, ahová szállítani fogunk?

Ehhez **segédváltozókat** (penalty values) definiálunk,
amelyek segítenek meghatározni, **melyik sor vagy oszlop** a "legígéretesebb" a következő lépéshez.

---

Szeretnéd, hogy most kiszámoljam a Vogel-Korda első lépését, beleértve a segédváltozókat is?





Kiváló! Itt van a 15/16-os dia **teljes szövege** és az első lépéshez tartozó **táblázat a segédváltozókkal** (penalty values) a **Vogel-Korda módszer** szerint.

---

### **A Vogel-Korda módszer**

#### Költségtábla:

```plaintext
    B1  B2  B3  B4     Készlet  penalty
R1   8   7   3   2     15		1
R2   1   4   2   5     43		1
R3   2   3   4   7     28		1
R4   1   1   4   4     19		0
     ↓   ↓   ↓   ↓
    18  32  35  20     (Boltigények)
	 0   2   1   2		penalty
```

---

### 📌 Szöveg a diáról:

**Számoljuk ki soronként és oszloponként a két legkisebb szállítási költség különbségét.**
Ezeket a számokat **zölddel adtuk meg**.

Például:

* Az első sorban a legkisebb költségek: 2 és 3 → különbség: **1**
* Az utolsó (4.) oszlopban a két legkisebb költség: 2 és 4 → különbség: **2**

---

### 🧮 Segédváltozók (penalty values):

```plaintext
Sorpenalty:     1     1     1     0  
                ↑     ↑     ↑     ↑
               R1    R2    R3    R4

Oszlpenalty:    0     2     1     2  
                ↑     ↑     ↑     ↑
               B1    B2    B3    B4
```

---

A következő lépésben ebből a 7 segédértékből kiválasztjuk a **legnagyobbat (max. penalty)**, majd a hozzátartozó sor/oszlop **legolcsóbb cellájába** szállítunk, amennyit lehet.

Szeretnéd, hogy most folytassuk a konkrét szállítási lépésekkel a Vogel-módszer szerint?




Itt van a **16/16-os dia** teljes tartalma, beleértve a **magyarázó szöveget** és a **táblázatot segédváltozókkal és kiválasztott lépéssel**:

---

### 🟩 **A Vogel-Korda módszer – 1. lépés**

#### 📊 Költségtábla az igényekkel és készletekkel:

|        | B1 | B2 | B3 | B4 | Készlet |  penalty |
| ------ | -- | -- | -- | -- | ------- | ------- |
| **R1** | 8  | 7     | 3    | 2  | 15   | 1 |
| **R2** | 1  | 4     | 2    | 5  | 43   | 1 |
| **R3** | 2  | 3     | 4    | 7  | 28   | 1 |
| **R4** | 1  | 1 **19** | 4 | 4  | 19   | 0 |
|        | 18 | 32    | 35   | 20 |      |   |
| penalty | 0 | 2     | 1    | 2  |      |   |

#### ✅ Segédváltozók (penalty values):

* **Sorpenalty** (sorok mentén a 2 legkisebb költség különbségei):
  `R1: 1`, `R2: 1`, `R3: 1`, `R4: 0`

* **Oszlpenalty** (oszlopok mentén a 2 legkisebb költség különbségei):
  `B1: 0`, `B2: 2`, `B3: 1`, `B4: 2`

---

### 📝 Szöveg a diáról:

Most vegyünk ezek közül egy **maximális számot**.
Ez valamelyik **2-es érték**.
Legyen például a **második oszlop alatti 2**.

Akkor ebből az **oszlopból** válasszunk **minimális költségű cellát**.
Ez az **utolsó sorban** van (R4–B2, költség = 1).

Itt fogunk **maximális lehetséges mennyiséget szállítani**,
ami **19 egység**.

---

### 🔁 Következő lépés:

* Szállítunk **19 egységet** R4 → B2 (költség = 1)
* B2 igénye csökken: 32 → 13
* R4 készlete: 19 → 0 (kimerült)

A táblázatot redukáljuk: R4 kiesik, B2 csökkent.

---

Szeretnéd, hogy folytassam a Vogel-Korda módszer következő lépésével is?




