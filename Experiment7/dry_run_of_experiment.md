
## 3. Execution Trace: Visual Dry Run

### Input Data

- **Nodes**: 4  
- **Source**: 0  
- **Destination**: 3  
- **Stops (k)**: 1  
- **Flights**:
  - `0 → 1 : 10`
  - `1 → 3 : 20`
  - `0 → 2 : 100`
  - `2 → 3 : 10`

### Initial State

```
dist = [0, inf, inf, inf]
temp = [0, inf, inf, inf]
```

### Pass 1: Max 1 Flight (0 Stops)

1. `0 → 1 (10)` → temp[1] = 10  
2. `0 → 2 (100)` → temp[2] = 100  
3. `1 → 3 (20)` → skipped (dist[1] = inf)  
4. `2 → 3 (10)` → skipped (dist[2] = inf)  

**Result:**

```
dist = [0, 10, 100, inf]
```

### Pass 2: Max 2 Flights (1 Stop)

1. `1 → 3 (20)` → temp[3] = 30  
2. `2 → 3 (10)` → temp[3] remains 30  
3. `0 → 1 (10)` → no change  

**Result:**

```
dist = [0, 10, 100, 30]
```

### Final Result

- **Path**: `0 → 1 → 3`  
- **Cost**: `30`  
- **Stops Used**: `1`  
- **Within Limit**: ✅  

**Output:** `30`