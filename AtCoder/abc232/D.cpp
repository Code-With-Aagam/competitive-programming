#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007LL;
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

int dp[101][101];

int dfs(const vector<vector<char>> &board, int i, int j) {
	int n = board.size(), m = board[0].size();
	if (i < 0 or j < 0 or i >= n or j >= m or board[i][j] == '#') return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 1 + max(dfs(board, i + 1, j), dfs(board, i, j + 1));
	return dp[i][j];
}

void solve(int tc) {
	int n, m;
	read(n, m);
	memset(dp, -1, sizeof(dp));
	vector<vector<char>> board(n, vector<char>(m));
	for (auto &row : board) readContainer(row);
	int ans = dfs(board, 0, 0);
	write(ans);
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}