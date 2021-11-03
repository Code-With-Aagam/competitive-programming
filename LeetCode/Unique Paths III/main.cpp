class Solution {
	int ans = 0;
	const vector<int> dx = {0, 0, 1, -1};
	const vector<int> dy = {1, -1, 0, 0};

	void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, int empty, int curr) {
		if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == -1) return;
		if (grid[i][j] == 2) {
			ans += curr == empty;
			return;
		}
		grid[i][j] = -1;
		for (int k = 0; k < 4; ++k) {
			dfs(grid, i + dx[k], j + dy[k], n, m, empty, curr + 1);
		}
		grid[i][j] = 0;
	}
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int empty = 0, x = 0, y = 0, n = grid.size(), m = grid[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1) {
					x = i;
					y = j;
				} else if (grid[i][j] != -1) {
					++empty;
				}
			}
		}
		dfs(grid, x, y, n, m, empty, 0);
		return ans;
	}
};