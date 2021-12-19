class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> ans(n, 1LL);
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ans[i] = 1 + ans[i - 1];
            } else {
                ans[i] = 1;
            }
        }
        return accumulate(cbegin(ans), cend(ans), 0LL);
    }
};