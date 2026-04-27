#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1 << 12][12];

int tsp(int mask, int u, vector<vector<int>>& cost) {
    if (mask == (1 << n) - 1) return cost[u][0];
    if (dp[mask][u] != -1) return dp[mask][u];

    int res = 1e9;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) { // If city v is not visited
            res = min(res, cost[u][v] + tsp(mask | (1 << v), v, cost));
        }
    }
    return dp[mask][u] = res;
}