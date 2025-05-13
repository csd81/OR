The Cutting Stock Problem involves minimizing the number of raw materials (lumber in this case) required to fulfill a demand for various sizes of items. The problem is typically solved using integer programming, but for large instances, approaches like the Gomory-Gilmore algorithm are used.

The Gomory-Gilmore approach involves:

1. **Linear Relaxation**: First, solve the relaxed linear programming (LP) model where all variables are allowed to be non-integral. This step helps identify the optimal solution without worrying about integer constraints.
2. **Column Generation**: Since listing all possible patterns (combinations of cuts from the lumber) is computationally infeasible, column generation is used. In this process, a knapsack problem is solved repeatedly to generate new patterns that can improve the solution.
3. **Revised Simplex**: The revised simplex method is employed to efficiently handle the LP and update the solution iteratively.

### Key Steps:

1. **Initial Pattern Setup**: You start with a set of initial patterns, which represent different ways of cutting the lumber to satisfy the demand. Each pattern is a vector representing how many pieces of each item can be cut from one unit of lumber.
2. **Solve the Relaxed Problem**: Solve the relaxed LP problem (ignoring the integer constraints) to get an initial feasible solution. If the solution contains non-integer values, round them to integers.
3. **Column Generation (Knapsack Problem)**: Generate new patterns that may improve the solution. This is done by solving a knapsack problem, which looks for patterns that can cut the lumber efficiently to minimize waste.
4. **Simplex Algorithm**: Use the simplex method to optimize the objective function, updating the solution as you add or remove patterns from the basis.
5. **Rounding**: Finally, round the non-integer solutions to the nearest integers to get a feasible, although suboptimal, solution.

Would you like to dive deeper into any specific part of the algorithm, or would you prefer to work on implementing it in code?

 
# The Cutting Stock Problem, and solving it by the Gomory-Gilmore algorithm

Given the next data: C = 16, and

| size | #   |
|------|-----|
| 3    | 20  |
| 4    | 50  |
| 5    | 40  |

The meaning of the data is as follows: We have a small workshop where we do some carpentry work. More exactly, we have lumber with a length of C = 16 feet. Also, we have a demand for items with the sizes given in the table above, with the given cardinality. That is, we must produce 20 items (or pieces) of length 3; 50 items of length 4; and 40 items of length 5. We will produce them so that the stock material will be cut into pieces. For example, a lumber can be cut into 4 pieces of small items, each of length 4. We need to provide all items that are ordered, but we want to use as few lumber pieces as possible. This is the so-called Cutting Stock Problem.

Let us try to find all “patterns” that are of sense:

|   | 1 | 2 | 3a | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|---|---|---|----|---|---|---|---|---|---|---|----|----|
| 3 | 5 | 4 | 3  | 3 | 2 | 2 | 2 | 1 | 1 | 0  | 0  | 0  |
| 4 | 0 | 1 | 1  | 0 | 2 | 1 | 0 | 3 | 2 | 4  | 1  | 0  |
| 5 | 0 | 0 | 0  | 1 | 0 | 1 | 2 | 0 | 1 | 0  | 2  | 3  |

(Possibly) these are all patterns of interest.

For example, pattern 3a will not be needed, as pattern 3 dominates it!

So, we can list all non-dominated patterns, that can be used, if we are “lucky”.

For example, if we use pattern 2, then from some raw material unit we will gain 4 pieces of size 3 and one piece of size 4. If we cut, e.g., two such lumber stock using this pattern 2, we will gain 2 * 4 = 8 pieces of size 3 and 2 * 1 = 2 pieces of size 4, and so on.

Let us write up the model of the problem (for the above input, supposing that these are the patterns of interest). Let $x_i$ be the number of stocks that are cut according to pattern $i$. We gain the next model:

$$
5x_1 + 4x_2 + 3x_3 + 2x_4 + 2x_5 + 2x_6 + x_7 + x_8 \geq 20
$$

$$
x_2 + 2x_4 + x_5 + 3x_7 + 2x_8 + 4x_9 + x_{10} \geq 50
$$

$$
x_3 + x_5 + 2x_6 + x_8 + 2x_{10} + 3x_{11} \geq 40
$$

$$
x_i \geq 0, \text{ integer, for all } 1 \leq i \leq 11
$$

$$
z = x_1 + x_2 + x_3 + x_4 + x_5 + x_6 + x_7 + x_8 + x_9 + x_{10} + x_{11} \to \text{min}
$$

Are we done? Can we solve it?
 







 
One problem is, that the variables are integers. So not a simple LP, but an integer model that we should solve. This is not a big issue, as we can solve the relaxation (ignoring the integrality constraints), and after getting the optimal solution for the LP, all variables that are not integer in the optimal solution will be rounded up. Since there are only a few constraints (i.e., 3 constraints), we lose not too much from the optimality. (That is, suppose we need to cut 1500.8 stocks in the relaxed optimal solution, but in this relaxed optimal solution there are 3 variables, all are fractional numbers. Like $x_i = 500.1$, $x_j = 300.2$; $x_k = 700.5$. We round all up, getting a new solution $x_i' = 501$, $x_j' = 301$; $x_k' = 701$. Then we lose not more than 3, the optimal solution is not less than 1501 (as it must be integer), and our solution is 1503, the “gap” is only 2. Not too big loss in practical problems (if the number of different types is relatively small).

But the main problem is something other:

But the main problem is, that if there are more different sizes (types), then the number of appropriate patterns grows exponentially. The problem is treated and solved in these publications:

- Gilmore P. C., R. E. Gomory (1961). A linear programming approach to the cutting-stock problem. Operations Research 9: 849-859
- Gilmore P. C., R. E. Gomory (1963). A linear programming approach to the cutting-stock problem - Part II. Operations Research 11: 863-888

The authors say, that if there are e.g., 40 item types (40 different sizes), then the number of patterns that should be considered may be about 100 million! We are not able to list them all! (Recall that in 1961, the case was much harder, in the sense of computability.)

The proposed solution (by Gomory-Gilmore) is:
- (we take $ \geq $ instead of $ \leq $, usually this also works)
- (we solve the relaxation, and the optimal relaxed solution is rounded up)
- Column generation (solving a slave problem which is a knapsack problem to find a good pattern, which will enter the basis)
- Revised simplex

The combination of the above two things makes it possible to solve a considerably large problem also. We will demonstrate the solution for the above input.



# Phase 0

We start with the next patterns (columns):

$$
B = \{ a^1, a^2, a^3 \}
$$

$$
\text{a}^1 = 
\begin{bmatrix}
5 \\
0 \\
0
\end{bmatrix},
\quad
\text{a}^2 = 
\begin{bmatrix}
0 \\
4 \\
0
\end{bmatrix},
\quad
\text{a}^3 = 
\begin{bmatrix}
0 \\
0 \\
3
\end{bmatrix}
$$

Then it is easy to see that $ B^{-1} $ is:

$$
B^{-1} = 
\begin{bmatrix}
1/5 & 0 & 0 \\
0 & 1/4 & 0 \\
0 & 0 & 1/3
\end{bmatrix}
$$

The pricing vector is $ \pi = c_B \cdot B^{-1} = [1, 1, 1] \cdot B^{-1} = [1/5, 1/4, 1/3] $.

We look for a good column (that can enter the basis).

Generally, it looks like $ a(a^1, a^2, a^3) $. For example, $ a^1(5, 0, 0) $, $ a^2(0, 4, 0) $, these are at the moment in the basis. Some others can be like $ a(3, 1, 0) $ (see the initial table of possible patterns), or $ a(2, 2, 0) $, and so on. But usually, we are not able to list all needed columns. So we take it generally: $ a(a^1, a^2, a^3) $, where $ a^1, a^2 $, and $ a^3 $ mean, respectively, how many are cut from the size of 3, from the size of 4, and from the size of 5. This is the general sub-problem for the choice of an appropriate column (of the unknown simplex tableau):

$$
\pi a^{-1} \to \max
$$
subject to:

$$
3a_1 + 4a_2 + 5a_3 \leq 16
$$

$$
a_1, a_2, a_3 \geq 0, \text{ integer}
$$

Here, the constraint $ 3a_1 + 4a_2 + 5a_3 \leq 16 $ means that it is possible to gain so many pieces from the stock material. Naturally, $ a_1, a_2, a_3 $ are all non-negative integers. 

Finally, recall that the reduced cost can be calculated as the vector $ a(a_1, a_2, a_3) $ multiplied by the pricing vector, and the cost function coefficient is subtracted, i.e. $ z_k - c_k = \pi a_k - c_k $ (where $ a_k $ is the $ k $-th column vector in the coefficient matrix $ A $).

Now, our column vector is denoted above in the general model of the slave problem as $ a = a(a_1, a_2, a_3) $.

Now, all coefficients in the $ c $-vector are 1. So the reduced cost is $ \pi a - 1 $. If this is positive, it is advantageous if the $ a $-vector in consideration enters the basis. This is why we maximize $ \pi a - 1 $. In fact, if we find any $ a $-vector for which this objective is positive, it still applies.



So, now, our slave problem looks as follows:

$$
\frac{1}{5} a_1 + \frac{1}{4} a_2 + \frac{1}{3} a_3 - 1 \to \max
$$

subject to:

$$
3a_1 + 4a_2 + 5a_3 \leq 16
$$

$$
a_1, a_2, a_3 \geq 0, \text{ integer}.
$$

We realize that this is an upper bounded knapsack problem.

Let us calculate the gain/weight ratios:

$$
\frac{1}{5} a_1 + \frac{1}{4} a_2 + \frac{1}{3} a_3 - 1 \to \max
$$

subject to:

$$
3a_1 + 4a_2 + 5a_3 \leq 16
$$

$$
a_1, a_2, a_3 \geq 0, \text{ integer}.
$$

Gain/Weight ratios: $ \frac{1}{15}, \frac{1}{16}, \frac{1}{15} $.

That is, the optimal cost will be given if the knapsack is completely full, and we pack only from the first type and third type!

That is, $ a^4(2, 0, 2) $ is an optimal solution.

Let us calculate the corresponding objective value: 

$$
z = 2 \times \frac{1}{5} + 0 \times \frac{1}{4} + 2 \times \frac{1}{3} - 1 = \frac{2}{5} + \frac{2}{3} - 1 > 0
$$

So, it is advantageous to take this new vector $ a^4 $ into the basis.

At the moment, we know that $ a^4 $ enters $ B \to ? $.

But, what vector will leave the basis?

We need to calculate the transformed form of $ a^4 $ (let us denote it by $ y $), and the basis solution, usually denoted by $ x_B $. Recall that $ x_B = B^{-1} \cdot b $ and $ y = B^{-1} \cdot a^4 $. (Recall also that $ b(20, 50, 40) $ is the b vector, and the basis inverse is:

$$
B^{-1} =
\begin{bmatrix}
\frac{1}{5} & 0 & 0 \\
0 & \frac{1}{4} & 0 \\
0 & 0 & \frac{1}{3}
\end{bmatrix}
$$

After making the calculation we get:

$$
x_B = \left( 4, \frac{25}{2}, \frac{40}{3} \right)
$$
and
$$
y = \left( \frac{2}{5}, 0, \frac{2}{3} \right)
$$

Now we apply the minimum rule to decide what vector leaves the basis.

$$
\min \left\{ \frac{4}{\frac{2}{5}}; \frac{\frac{40}{3}}{\frac{2}{3}} \right\} = \frac{4}{\frac{2}{5}}.
$$

The corresponding number is chosen to the pivot value in the $ y $ vector, that is: $ y \left( \frac{2}{5}; 0; \frac{2}{3} \right) $. That is, the first row is chosen in the column vector $ y $. This means that the vector will leave the basis, which is in the first position. The current basis is $ B = \{ a^1, a^2, a^3 \} $, so the first vector in the basis is $ a^1 $.

So we know that:

$$
a^4 \to B \to a^1
$$

Comes Phase 1.



# Phase 1

Now $ B = \{ a^4, a^2, a^3 \} $ where the already considered columns are:

$$
a^1 = \begin{bmatrix} 5 \\ 0 \\ 0 \end{bmatrix}, 
a^2 = \begin{bmatrix} 0 \\ 4 \\ 0 \end{bmatrix}, 
a^3 = \begin{bmatrix} 0 \\ 0 \\ 3 \end{bmatrix}, 
a^4 = \begin{bmatrix} 2 \\ 0 \\ 2 \end{bmatrix}
$$

Recall that $ y $ is as follows: $ y(2/5; 0; 2/3) $, where the first value is the pivot. It means that the basis transformation should be made so that:
- The first row is divided by 2/5
- The second row remains as here we already do have a 0
- We subtract $ (5/3) $-times of the first row from the third row (to eliminate the 2/3 by the 2/5)

But, we make the transformation only on the basis inverse.

The old basis inverse is:

$$
B^{-1} = 
\begin{bmatrix}
\frac{1}{5} & 0 & 0 \\
0 & \frac{1}{4} & 0 \\
0 & 0 & \frac{1}{3}
\end{bmatrix}
$$

The new basis inverse will be:

$$
B^{-1} = 
\begin{bmatrix}
\frac{1}{2} & 0 & 0 \\
0 & \frac{1}{4} & 0 \\
-\frac{1}{3} & 0 & \frac{1}{3}
\end{bmatrix}
$$

Applying this new basis inverse, the new pricing vector is (the numbers in the matrix are added in each column to get): $ \pi = \left(\frac{1}{6}, \frac{1}{4}, \frac{1}{3}\right) $.

With this new pricing vector, the new slave problem looks like:

$$
\frac{1}{6} a_1 + \frac{1}{4} a_2 + \frac{1}{3} a_3 - 1 \to \max
$$

subject to:

$$
3a_1 + 4a_2 + 5a_3 \leq 16
$$

$$
a_1, a_2, a_3 \geq 0, \text{ integer}.
$$

Gain/Weight ratios: $ \frac{1}{18}, \frac{1}{16}, \frac{1}{15} $.

Now, by some calculation (B&B or Dynamic Programming, or elementary calculation or Brute Force), we can confirm that the maximum of $ z $ is 0. It means that we already arrived at an optimal solution of the relaxed model. Still, we need to calculate the optimal solution. We get it as $ x_B = B^{-1} \cdot b $. After making the calculation, we get:

$$
x_B = (10, 12.5, 6.66)
$$

The optimum value (of the relaxed problem) is 29.16.


Since the optimum value of the cutting stock problem is some integer number (the number of stock material that is cut), we know that the optimal solution of the cutting stock problem is at least 30 (29.16 is rounded up).

Let us try to round up also the components of the $ x_B $ vector. We get a new vector as $ x(10; 13; 7) $.

Since the current basis is $ B = \{ a^4, a^2, a^3 \} $, this means that so many stocks are cut from the patterns: We cut 10 stocks according to column 4, we cut 13 according to pattern 2, we cut 7 according to pattern 3.

“We are lucky” in the sense, that the sum of the components is just 30, which means that we do have a “proven” optimal solution of the cutting stock problem. Let us summarize finally what patterns are used, and how many pieces are cut.

| size | $ a^1 $ | $ a^2 $ | $ a^3 $ | $ a^4 $ | Produced |
|------|-----------|-----------|-----------|-----------|----------|
| 3    | 5         | 0         | 0         | 2         | 20       |
| 4    | 0         | 4         | 0         | 0         | 52       |
| 5    | 0         | 0         | 3         | 2         | 41       |
| #    | -         | 13        | 7         | 10        |          |

We conclude that all demand is produced (and a bit more).




