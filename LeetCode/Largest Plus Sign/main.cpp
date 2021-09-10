class Solution {
   public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (const auto &ele : mines) {
            dp[ele[0]][ele[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int l = 0, r = 0, t = 0, b = 0;
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], (l = dp[i][j] ? l + 1 : 0));
                dp[i][n - j - 1] = min(dp[i][n - j - 1], (r = dp[i][n - j - 1] ? r + 1 : 0));
                dp[j][i] = min(dp[j][i], (t = dp[j][i] ? t + 1 : 0));
                dp[n - j - 1][i] = min(dp[n - j - 1][i], (b = dp[n - j - 1][i] ? b + 1 : 0));
            }
        }
        int ans = 0;
        for (const auto &ele : dp) {
            ans = max(ans, *max_element(cbegin(ele), cend(ele)));
        }
        return ans;
    }
};