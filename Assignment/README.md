# 📘 DAA Assignment Report

## 👨‍💻 Problems Implemented
1. N-Queens Problem (Backtracking + Hashing Optimization)
2. Hamiltonian Cycle Problem (Backtracking using Adjacency Matrix)

---

# 🧩 1. N-Queens Problem

## 📖 Problem Statement
Place N queens on an N × N chessboard such that no two queens attack each other.

Queens attack:
- Same row
- Same column
- Both diagonals

---

## ⚙️ Algorithm (Backtracking with Optimization)

### Idea:
Place queens row by row and ensure safety using:
- Column tracking
- Diagonal tracking

### Steps:
1. Start from row 0.
2. Try placing a queen in each column.
3. Check:
   - Column is free
   - Left diagonal is free
   - Right diagonal is free
4. If safe → place queen and move to next row.
5. Else → backtrack.
6. Repeat until all rows are filled.

---

## 🔑 Optimizations Used
Instead of scanning board every time:
- `cols[]` → column usage
- `diag1[]` → (row - col + n - 1)
- `diag2[]` → (row + col)

✔ Reduces checking time to O(1)

---

## 🧪 Dry Run (N = 4)

Initial board:
```
. . . .
. . . .
. . . .
. . . .
```

### Step 1:
Place queen at (0,1)
```
. Q . .
. . . .
. . . .
. . . .
```

### Step 2:
Place queen at (1,3)
```
. Q . .
. . . Q
. . . .
. . . .
```

### Step 3:
Place queen at (2,0)
```
. Q . .
. . . Q
Q . . .
. . . .
```

### Step 4:
Place queen at (3,2)
```
. Q . .
. . . Q
Q . . .
. . Q .
```

✔ Solution Found

---

## ⏱ Time Complexity
- Worst case: **O(N!)**
- Due to pruning using hashing

## 📦 Space Complexity
- O(N) recursion stack
- O(N) hashing arrays

---

# 🧩 2. Hamiltonian Cycle Problem

## 📖 Problem Statement
Find a cycle that visits every vertex exactly once and returns to starting point.

---

## ⚙️ Algorithm

### Steps:
1. Start from vertex 0.
2. Add next vertex if:
   - Adjacent to previous vertex
   - Not already visited
3. Recurse until all vertices are included.
4. Check if last connects to first.
5. If yes → cycle found, else backtrack.

---

## 🧪 Dry Run Example

Adjacency Matrix:
```
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

### Step-by-step:

Start:
```
[0, _, _, _]
```

Move:
```
[0, 1, _, _]
[0, 1, 2, _]
[0, 1, 2, 3]
```

Check:
```
3 → 0 exists ✔
```

✔ Hamiltonian Cycle:
```
0 → 1 → 2 → 3 → 0
```

---

## ⏱ Time Complexity
- Worst case: **O(N!)**

## 📦 Space Complexity
- O(N) recursion stack
- O(N) path array

---

# 📊 Comparison

| Feature | N-Queens | Hamiltonian Cycle |
|--------|----------|------------------|
| Approach | Backtracking | Backtracking |
| Optimization | Hashing arrays | Adjacency matrix |
| Complexity | O(N!) | O(N!) |
| Output | All solutions | One cycle |

---

# 🚀 How to Run

## Compile
```bash
g++ n_queens.cpp -o nqueens
g++ hamiltonian_cycle.cpp -o hamiltonian
```

## Run
```bash
./nqueens
./hamiltonian
```

---

