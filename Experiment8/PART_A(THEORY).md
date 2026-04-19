# Step 2: Measure Metrics

## Metrics Used

1. Execution Time  
Measured in milliseconds using high resolution clock.

2. Operations Count  
Counts core operations inside loops/recursion.

3. Feasibility Status  
- Completed → Finished within 2 seconds  
- Timeout → Exceeded 2 seconds  

---

## Environment

Hardware: 8GB RAM, Intel i5  
Compiler: GCC  

---

## Execution Log

| Algorithm | Complexity | Input Size | Operations | Time (ms) | Status |
|----------|------------|------------|------------|-----------|--------|
| Binary Search | O(log n) | 1,000,000 | ~20 | 0.001 | Completed |
| Subset Sum (Verification) | O(n) | 4 | 4 | 0.0003 | Completed |
| Subset Sum (Decision) | O(2^n) | 4 | 16 | 0.01 | Completed |
| Subset Sum (Decision) | O(2^n) | 40 | >1M | >2000 | Timeout |
| TSP | O(n!) | 4 | 24 | 0.005 | Completed |
| TSP | O(n!) | 14 | >10M | >2000 | Timeout |