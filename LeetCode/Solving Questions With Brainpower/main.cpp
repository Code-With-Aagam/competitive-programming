class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            long long a = (long long)questions[i][0], b = 0LL;
            if (i + questions[i][1] + 1 < n) a += (long long)dp[i + questions[i][1] + 1];
            if (i + 1 < n) b += (long long)dp[i + 1];
            dp[i] = max(a, b);
        }
        return dp[0];
    }
};