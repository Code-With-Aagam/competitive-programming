class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, int n, int k) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j <= n; ++j) {
            curr.push_back(j);
            dfs(j + 1, n, k - 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        curr.clear();
        dfs(1, n, k);
        return ans;
    }
};