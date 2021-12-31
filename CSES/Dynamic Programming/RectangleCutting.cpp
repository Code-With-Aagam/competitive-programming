#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int inf = 9e18;
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
int minCuts(int n, int m) {
	if (n == m) return 0;
	int ans = inf;
	for (int i = 1; i < n; ++i) {
		ans = min(ans, 1 + minCuts(i, m) + minCuts(n - i, m));
	}
	for (int j = 1; j < m; ++j) {
		ans = min(ans, 1 + minCuts(n, j) + minCuts(n, m - j));
	}
	return ans;
}

void solve() {
	int n, m;
	read(n, m);
	vector<vector<int>> cuts(n + 1, vector<int>(m + 1, inf));
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= m; ++b) {
			if (a == b) {
				cuts[a][b] = 0;
				continue;
			}
			for (int k = 1; k < a; ++k) {
				cuts[a][b] = min(cuts[a][b], 1 + cuts[a - k][b] + cuts[k][b]);
			}
			for (int k = 1; k < b; ++k) {
				cuts[a][b] = min(cuts[a][b], 1 + cuts[a][b - k] + cuts[a][k]);
			}
		}
	}
	write(cuts.back().back());
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