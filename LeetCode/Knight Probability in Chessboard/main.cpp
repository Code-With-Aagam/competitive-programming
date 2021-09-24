class Solution {
private:
    const vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    const vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};
    double dp[26][26][101];
public:
    double knightProbability(int n, int k, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) return 0.0;
        if (k == 0) return 1.0;
        auto &ans = dp[x][y][k];
        if (ans != 0) return ans;
        for (int i = 0; i < 8; ++i) {
            ans += knightProbability(n, k - 1, x + dx[i], y + dy[i]);
        }
        ans *= 0.125;
        return ans;
    }
};