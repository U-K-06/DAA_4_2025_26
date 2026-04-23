#include <vector>
class Solution {
public:
    int minDifference(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = totalSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        for (int j = totalSum / 2; j >= 0; j--) {
            if (dp[j]) {
                return totalSum - 2 * j;
            }
        }

        return 0;
    }
};