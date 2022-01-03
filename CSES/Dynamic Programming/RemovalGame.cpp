#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18;
constexpr long double eps = 1e-9;

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

/**
 * Recursive -> TLE
 * */
int findMaxScore(const vector<int> &arr, int i, int j) {
	if (i > j) return 0;
	int left = min(findMaxScore(arr, i + 2, j), findMaxScore(arr, i + 1, j - 1));
	int right = min(findMaxScore(arr, i + 1, j - 1), findMaxScore(arr, i, j - 2));
	return max(arr[i] + left, arr[j] + right);
}

void solve() {
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	vector<vector<int>> score(n, vector<int>(n, 0));
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len - 1;
			int left = inf, right = inf;
			if (i + 2 < n) {
				left = min(left, score[i + 2][j]);
			}
			if (i + 1 < n and j - 1 >= 0) {
				left = min(left, score[i + 1][j - 1]);
				right = min(right, score[i + 1][j - 1]);
			}
			if (j - 2 >= 0) {
				right = min(right, score[i][j - 2]);
			}
			if (left == inf) left = 0;
			if (right == inf) right = 0;
			score[i][j] = max(arr[i] + left, arr[j] + right);
		}
	}
	write(score[0][n - 1]);
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