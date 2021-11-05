class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int left = 2; left <= n; ++left) {
            for (int right = 1; right <= left; ++right) {
                dp[left] += dp[right - 1] * dp[left - right];
            }
        }
        return dp[n];
    }
};