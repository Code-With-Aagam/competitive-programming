class Solution {
private:
    const vector<int> dx = {0, 0, 1, -1};
    const vector<int> dy = {1, -1, 0, 0};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid.size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        queue<vector<int>> q;
        int steps = 0;

        visited[0][0] = 0;
        q.push({0, 0, 0});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();
                if (curr[0] == n - 1 && curr[1] == m - 1) return steps;
                for (int dir = 0; dir < 4; ++dir) {
                    int ni = curr[0] + dx[dir], nj = curr[1] + dy[dir];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                        int count = curr[2] + grid[ni][nj];
                        if (count >= visited[ni][nj] || count > k) continue;
                        visited[ni][nj] = count;
                        q.push({ni, nj, count});
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};