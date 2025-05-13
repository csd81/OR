Here is the **Markdown version** of your image content, preserving the original Hungarian text and layout:

---

## **2. (5 pont)**

Az alábbi táblázatot valamely lineáris programozási feladat szimplex módszerrel történő megoldása során kaptuk. Értékelje a táblázatot!
(Melyik fázisról van szó? Töltse ki a legalsó sort a definíció szerint. Mit lehet mondani a táblázat adatai alapján arról, hogy

a) van-e megengedett megoldása a feladatnak,
b) van-e optimális megoldása a feladatnak, ha igen, akkor
c) egy vagy több optimális megoldás van-e?)

**Indokolja a válaszokat!**

---

### **Simplex tábla:**

| B     | $x_B$ | $a_1$ | $a_2$ | $a_3$ | $a_4$ | $a_5$ | $a_6$ | $a_7$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $a_1$ | 11    | 1     | 0     | 1     | 0     | 0     | –3    | 2     |
| $a_2$ | 5     | 0     | 1     | 2     | 0     | 1     | –1    | 0     |
| $a_4$ | 1     | 0     | 0     | –2    | 1     | –1    | 4     | 1     |
| $z$   | 294   | 0     | 0     | –2    | 0     | –6    | 15    | 57    |

---

### **Kitöltött értékelő tábla (kézírással):**

| B     | $x_B$ | $a_1$ | $a_2$ | $a_3$ | $a_4$ | $a_5$ | $a_6$ | $a_7$ |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| $a_1$ | 11    |       |       |       |       |       |       |       |
| $a_5$ | 5     |       |       |       |       |       |       |       |
| $a_4$ | 6     |       |       |       |       |       |       |       |
|       | 324   | 0     | 6     | 10    | 0     | 0     | 9     | 57    |

**egyetlen optimális megoldás**

---

Let me know if you'd like this exported as `.md`, `.pdf`, or if you need an analysis of the simplex tableau.


Here's the **Markdown version** of your latest image, keeping the **original Hungarian text** and structure:

---

## **Simplex táblák és számítások – Megoldásmenet**

---

### **Simplex-tábla részletek:**

| B  | x\_B | a₁ | a₂ | a₃ | a₄ | a₅ | a₆ | q₁ |
| -- | ---- | -- | -- | -- | -- | -- | -- | -- |
| q₁ | 40   | 1  | 0  | 1  | 0  | 0  | 0  | 0  |
| q₄ | 45   | 0  | 1  | 2  | 1  | 0  | 0  | 0  |
| q₆ | 26   | 1  | 0  | 1  | 0  | 1  | 0  | 0  |
| z  | –40  | –1 | –2 | –2 | 0  | 0  | 0  | 0  |

---

### **Későbbi lépés:**

| B  | x\_B | a₁ | a₂  | a₃ | a₄ | a₅   | a₆ | q₁ |
| -- | ---- | -- | --- | -- | -- | ---- | -- | -- |
| q₂ | 20   | 0  | 1/2 | 0  | 0  | 0    | 0  | 0  |
| q₄ | 5    | 0  | 0   | 1  | 1  | 0    | 0  | 0  |
| q₆ | 3/2  | 1  | 0   | –1 | 0  | 1/2  | 0  | 0  |
| z  | 395  | 0  | 0   | –1 | 0  | 11/2 | 0  | 0  |

---

## **Optimális megoldás:**

```
xₒₚₜ = (0, 0, 20, 26, 42, 0)  
zₘₐₓ = 426
```

---

## **Tovább finomított simplex-tábla:**

| B  | x\_B | a₁  | a₂ | a₃ | a₄ | a₅ | a₆ |
| -- | ---- | --- | -- | -- | -- | -- | -- |
| a₃ | 20   | 1/2 | 1  | 0  | 0  | 0  | 0  |
| a₂ | 64/5 | 1   | 0  | 0  | 0  | 0  | 0  |
| a₁ | 84/5 | 0   | 0  | 0  | 0  | 0  | 0  |
| z  | 606  | 0   | 10 | 0  | 0  | 0  | 11 |

---

## **Átlagolt optimális megoldás:**

```
xₒₚₜ² = (84/5, 0, 58/5, 46/5, 0, 10)
```

Számítás:

```
(19·84 + 58·16 + 46·11) / 5 = 1596 + 928 + 506 = 3030  
zₘₐₓ = 606
```

---

Let me know if you'd like this saved as `.md`, `.tex`, or `.pdf`.
