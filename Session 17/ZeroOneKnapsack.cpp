class Solution {
public:
    // --- 1. Top Down (Recursion + Memoization) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(N * W) + O(N) auxiliary stack space
    int solveTopDown(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (i < 0 || W == 0) return 0;
        if (dp[i][W] != -1) return dp[i][W];

        int notPick = solveTopDown(i - 1, W, val, wt, dp);
        int pick = 0;
        if (wt[i] <= W) {
            pick = val[i] + solveTopDown(i - 1, W - wt[i], val, wt, dp);
        }
        return dp[i][W] = max(pick, notPick);
    }

    // --- 2. Bottom Up (Tabulation) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(N * W)
    int knapSackBottomUp(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }

    // --- 3. Space Optimized (1D Array) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(W)
    int knapSackOptimized(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = W; j >= wt[i]; j--) {
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
        return dp[W];
    }
};