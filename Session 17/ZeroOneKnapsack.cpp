class Solution {
public:
    // --- 1. Top Down (Recursion + Memoization) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(N * W) + O(N)
    int solve(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (dp[i][W] != -1) return dp[i][W];

        int notPick = solve(i - 1, W, val, wt, dp);
        int pick = 0;
        if (wt[i] <= W) {
            pick = val[i] + solve(i - 1, W - wt[i], val, wt, dp);
        }
        return dp[i][W] = max(pick, notPick);
    }

    // --- 2. Bottom Up (2D Tabulation - Your current code) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(N * W)
    int knapSack2D(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }

    // --- 3. Bottom Up (1D Space Optimized - Your prev/current idea) ---
    // Time Complexity: O(N * W)
    // Space Complexity: O(W)
    int knapSack1D(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0);
        
        for (int i = 0; i < n; i++) {
            vector<int> current(W + 1, 0);
            for (int w = 0; w <= W; w++) {
                if (wt[i] <= w) {
                    current[w] = max(prev[w], val[i] + prev[w - wt[i]]);
                } else {
                    current[w] = prev[w];
                }
            }
            prev = current; 
        }
        return prev[W];
    }
};