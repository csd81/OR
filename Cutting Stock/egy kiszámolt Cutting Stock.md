It looks like you have a visual solution to the Cutting Stock Problem using the Gomory-Gilmore algorithm. From the provided image, the steps of the solution have been performed using the column generation method, where new columns (patterns) are iteratively added to the basis.

### Key steps in the image:

1. **Phase 0:**

   * The initial basis $B = \{ a^1, a^2, a^3 \}$ is used.
   * The pricing vector $\pi$ is calculated.
   * A sub-problem is formulated, which is a knapsack problem, and an optimal column (pattern) is added to the basis.
   * The first iteration gives us a new vector $a^4(2, 0, 2)$, indicating that 2 items of size 3 and 2 items of size 5 are cut.

2. **Phase 1:**

   * The basis is updated to $B = \{ a^1, a^2, a^4 \}$.
   * The new pricing vector is calculated.
   * A sub-problem is solved, and a new pattern is added to the basis.
   * The iteration proceeds until a solution is found, and the final optimal solution is obtained.

3. **Optimal Solution:**

   * After performing the necessary calculations and transformations, the optimal solution is achieved.
   * The values $z = 33\frac{1}{8}$ represent the total number of lumbers required.

### Solution Summary:

* The optimal cutting patterns are identified as:

  * Cut 10 lumbers with pattern $a^4$ (producing 2 pieces of size 3 and 2 pieces of size 5).
  * Cut 13 lumbers with pattern $a^2$ (producing 4 pieces of size 4).
  * Cut 7 lumbers with pattern $a^3$ (producing 3 pieces of size 5).

This results in the total demand being satisfied, with a small surplus of materials (and the total cost is minimal).

Let me know if you would like any further explanation or if you'd like me to provide more details!


