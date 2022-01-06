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

int n, W, V = 0;
vector<pair<int, int>> items;	// <wi, vi>
/**
 * Recursive -> TLE
 * */
int findMinimumWeight(int index, int currValue) {
	if (index == n) {
		return currValue == 0 ? 0 : inf;
	}
	int including = inf;
	if (currValue - items[index].second >= 0) {
		including = items[index].first + findMinimumWeight(index + 1, currValue - items[index].second);
	}
	int excluding = findMinimumWeight(index + 1, currValue);
	return min(including, excluding);
}

void solve() {
	read(n, W);
	items.resize(n);
	for (int i = 0; i < n; ++i) {
		read(items[i].first, items[i].second);
		V += items[i].second;
	}
	vector<vector<int>> minWeight(n, vector<int>(V + 1, inf));
	minWeight[0][0] = 0;
	minWeight[0][items[0].second] = items[0].first;
	for (int i = 1; i < n; ++i) {
		for (int val = 0; val <= V; ++val) {
			minWeight[i][val] = minWeight[i - 1][val];
			if (val - items[i].second >= 0) {
				minWeight[i][val] = min(minWeight[i][val], items[i].first + minWeight[i - 1][val - items[i].second]);
			}
		}
	}
	for (int val = V; val >= 0; --val) {
		if (minWeight[n - 1][val] <= W) {
			write(val);
			break;
		}
	}
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