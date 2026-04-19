# 1. Why is Binary Search efficient?

Binary Search works in O(log n) time. It repeatedly divides the search space into half, reducing work drastically.

Example:
1 million elements → ~20 steps only

Hence, it scales extremely well.

---

# 2. Subset Sum: Hard to Solve, Easy to Verify

Solving:
Requires checking all subsets → O(2^n)

Verifying:
Just sum given subset → O(n)

Thus, solving is exponential but verification is fast.

---

# 3. TSP Infeasibility

TSP has O(n!) complexity.

At ~15 cities:
Number of routes becomes extremely large → computation exceeds time limit.

Hence becomes infeasible.

---

# 4. Solving vs Verifying

Solving:
Finding answer from scratch  
Example: Solving Sudoku  

Verifying:
Checking given answer  
Example: Checking completed Sudoku  

Verification is always faster.

---

# 5. Why NP-Complete is hardest?

- All NP problems reduce to NP-Complete problems  
- If one NP-Complete problem is solved efficiently → all NP become easy  

Thus they represent the hardest problems in NP.