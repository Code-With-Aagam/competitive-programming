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

long double f(pair<long double, long double> x, pair<long double, long double> y) {
	return sqrt((pow(y.first - x.first, 2) + pow(y.second - x.second, 2)) * 1.0);
}

void solve() {
	int n;
	read(n);
	vector<pair<long double, long double>> arr(n);
	for (auto &ele : arr) read(ele.first, ele.second);
	long double ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = max(ans, f(arr[i], arr[j]));
		}
	}
	write(fixed, setprecision(16), ans);
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