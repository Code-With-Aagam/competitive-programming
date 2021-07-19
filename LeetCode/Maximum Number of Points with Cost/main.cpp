class Solution {
   public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> dp(points[0].size(), 0LL);
        for (const auto& row : points) {
            for (int i = 1; i < row.size(); ++i) {
                dp[i] = max(dp[i], dp[i - 1] - 1);
                dp[row.size() - i - 1] = max(dp[row.size() - i - 1], dp[row.size() - i] - 1);
            }
            for (int i = 0; i < row.size(); ++i) {
                dp[i] += row[i];
            }
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};