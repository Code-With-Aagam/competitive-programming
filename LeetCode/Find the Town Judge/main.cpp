class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n, 0), outdegree(n, 0);
        for (const auto &ele : trust) {
            indegree[ele[1] - 1] += 1;
            outdegree[ele[0] - 1] += 1;
        }
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == n - 1 and outdegree[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};