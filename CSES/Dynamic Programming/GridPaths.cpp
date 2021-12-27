#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007;
const int inf = 1e18;
const long double pi = acos(-1);

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
	((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
	for (auto &e : t) {
		read(e);
	}
}

template <typename T>
void writeContainer(T &t) {
	for (const auto &e : t) {
		write(e, " ");
	}
	write("\n");
}

int findNumberOfPaths(const vector<vector<char>> &grid, int row, int col) {
	if (row >= grid.size() or col >= grid[0].size() or grid[row][col] == '*') {
		return 0;
	} else if (row == grid.size() - 1 and col == grid[0].size() - 1) {
		return 1;
	} else {
		int right = findNumberOfPaths(grid, row, col + 1);
		int bottom = findNumberOfPaths(grid, row + 1, col);
		return (right + bottom) % mod;
	}
}

void solve() {
	int n;
	read(n);
	vector<vector<char>> grid(n, vector<char>(n));
	for (auto &row : grid) readContainer(row);
	vector<vector<int>> paths(n, vector<int>(n, 0));
	paths[0][0] = (grid[0][0] == '.' ? 1 : 0);
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			if (grid[row][col] == '*') continue;
			if (row - 1 >= 0) {
				paths[row][col] += paths[row - 1][col];
				paths[row][col] %= mod;
			}
			if (col - 1 >= 0) {
				paths[row][col] += paths[row][col - 1];
				paths[row][col] %= mod;
			}
		}
	}
	write(paths.back().back());
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}