# Technical Documentation: Cheapest Flights Within K Stops

## 1. Algorithm Specification: Layered Bellman-Ford

The problem is solved using a variation of the Bellman-Ford algorithm. Standard shortest-path algorithms like Dijkstra naturally prioritize the lowest total cost regardless of the number of nodes visited. To strictly respect the limit of **k stops**, we implement a layered relaxation approach.

### Logic Flow

```text
Initial State: dist[src] = 0, others = inf

Start Loop: i = 0 to k
    Create 'temp' as a copy of 'dist'

    For each flight (u, v, price):
        If dist[u] != inf:
            temp[v] = min(temp[v], dist[u] + price)

    Update dist = temp (move to next layer)

Return dist[dst]
```

### Core Principles

1. **State Definition**  
   An array `dist` stores the minimum cost to reach each city.  
   `dist[u]` represents the cheapest price to reach city `u` using a limited number of edges.

2. **The Layering Constraint**  
   To ensure we do not exceed `k` stops, we perform exactly `k + 1` iterations.  
   - Iteration 1 → Paths using 1 flight (0 stops)  
   - Iteration 2 → Paths using 2 flights (1 stop)

3. **Prevention of Intra-layer Updates**  
   A `temp` array is used to store updates within a single pass. This ensures that a flight starting from a city reached in the *current* pass cannot be reused immediately, preventing multiple edges from being counted in a single layer.

---

## 2. Complexity Analysis

### Time Complexity: O(k * E)

The complexity is derived from the nested loop structure:

- **Outer Loop**: Runs `k + 1` times  
- **Inner Loop**: Iterates over all edges `E` each time  

**Calculation:**

```
Total Operations = (k + 1) * E
```

**Final Complexity:** `O(k * E)`

### Space Complexity: O(n)

Memory usage depends on number of cities `n`:

- `dist` array → size `n`
- `temp` array → size `n`

**Calculation:**

```
Total Space = n + n = 2n
```

**Final Complexity:** `O(n)`

---
