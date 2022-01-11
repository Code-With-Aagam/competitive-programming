#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int infinity = 1e18;
constexpr long double epsilon = 1e-9;

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

// (1 / x) % mod = binpow(x, mod - 2)
int binpow(int x, int y, int mod = mod) {
	x %= mod;
	int res = 1;
	while (y > 0) {
		if (y & 1) res = res * x;
		res %= mod;
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return res;
}
/**
 * Recursive -> TLE
 * */
int findMinCost(const vector<int> &arr, int i, int j) {
	if (i >= j) return 0;
	int ans = infinity;
	for (int k = i; k + 1 <= j; ++k) {
		int curr = 0;
		for (int l = i; l <= j; ++l) curr += arr[l];
		curr += findMinCost(arr, i, k);
		curr += findMinCost(arr, k + 1, j);
		ans = min(ans, curr);
	}
	return ans;
}

void solve() {
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	vector<vector<int>> minCost(n, vector<int>(n, 0));
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len - 1, sum = 0;
			minCost[i][j] = infinity;
			for (int k = i; k <= j; ++k) {
				sum += arr[k];
			}
			for (int k = i; k + 1 <= j; ++k) {
				minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k + 1][j] + sum);
			}
		}
	}
	write(minCost[0][n - 1], "\n");
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
}