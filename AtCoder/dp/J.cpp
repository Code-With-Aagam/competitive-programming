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
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	vector<vector<vector<long double>>> operations(n + 1, vector<vector<long double>>(n + 1, vector<long double>(n + 1, 0)));
	for (int three = 0; three <= n; ++three) {
		for (int two = 0; two <= n; ++two) {
			for (int one = 0; one <= n; ++one) {
				if (one + two + three > n or one + two + three == 0) continue;
				int zero = n - (one + two + three);
				long double p0 = zero * 1.0 / n;
				long double p1 = one * 1.0 / n;
				long double p2 = two * 1.0 / n;
				long double p3 = three * 1.0 / n;
				operations[three][two][one] += 1.0;
				if (one - 1 >= 0)
					operations[three][two][one] += p1 * operations[three][two][one - 1];
				if (two - 1 >= 0 and one + 1 <= n)
					operations[three][two][one] += p2 * operations[three][two - 1][one + 1];
				if (three - 1 >= 0 and two + 1 <= n)
					operations[three][two][one] += p3 * operations[three - 1][two + 1][one];
				if (1 - p0 != 0)
					operations[three][two][one] /= (1 - p0);
			}
		}
	}
	int three = count(all(arr), 3);
	int two = count(all(arr), 2);
	int one = count(all(arr), 1);
	write(fixed, setprecision(9), operations[three][two][one], "\n");
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