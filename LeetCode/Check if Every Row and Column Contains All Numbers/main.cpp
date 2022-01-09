class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        set<int> st;
        for (int i = 1; i <= n; ++i) st.insert(i);
        for (const auto &row : matrix) {
            set<int> curr(begin(row), end(row));
            if (curr != st) return false;
        }
        for (int j = 0; j < n; ++j) {
            set<int> curr;
            for (int i = 0; i < n; ++i) curr.insert(matrix[i][j]);
            if (curr != st) return false;
        }
        return true;
    }
};