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

void solve() {
	int n, k;
	read(n, k);
	vector<int> arr(n);
	readContainer(arr);
	vector<vector<int>> ways(n, vector<int>(k + 1, 0));
	for (int j = 0; j <= arr[0]; ++j) ways[0][j] = 1;
	for (int i = 0; i < n; ++i) ways[i][0] = 1;
	for (int i = 1; i < n; ++i) {
		vector<int> prefixSum = ways[i - 1];
		for (int j = 1; j <= k; ++j) {
			prefixSum[j] += prefixSum[j - 1];
			prefixSum[j] %= mod;
		}
		for (int j = 1; j <= k; ++j) {
			ways[i][j] = prefixSum[j];
			if (j - arr[i] - 1 >= 0) {
				ways[i][j] -= prefixSum[j - arr[i] - 1];
				ways[i][j] += mod;
				ways[i][j] %= mod;
			}
		}
	}
	write(ways[n - 1][k], "\n");
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