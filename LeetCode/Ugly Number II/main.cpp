class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int x = 0, y = 0, z = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min({2 * dp[x], 3 * dp[y], 5 * dp[z]});
            if (dp[i] == 2 * dp[x]) x++;
            if (dp[i] == 3 * dp[y]) y++;
            if (dp[i] == 5 * dp[z]) z++;
        }
        return dp.back();
    }
};