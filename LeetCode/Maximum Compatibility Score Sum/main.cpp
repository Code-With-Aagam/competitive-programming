class Solution {
   public:
    vector<vector<int>> students, mentors;
    int dp[257] = {-1};

    int solve(int i, int mask) {
        if (i == students.size()) return 0;
        if (dp[mask] != -1) return dp[mask];
        int ans = 0;
        for (int j = 0; j < students.size(); ++j) {
            if ((mask & (1 << j)) == 0) {
                int curr = 0;
                for (int k = 0; k < students[0].size(); ++k) {
                    if (students[i][k] == mentors[j][k]) ++curr;
                }
                ans = max(ans, curr + solve(i + 1, mask | (1 << j)));
            }
        }
        return dp[mask] = ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        students = s;
        mentors = m;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};