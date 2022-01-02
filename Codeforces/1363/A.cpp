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

void solve() {
	int n, x;
	read(n, x);
	vector<int> arr(n);
	readContainer(arr);
	int odd = 0, even = 0;
	for (const auto &ele : arr) {
		if (ele % 2 == 0) ++even;
		else ++odd;
	}
	if (x % 2 == 0) {
		if (odd % 2 == 0) {
			if (odd > 0 and even > 0 and odd + even - 1 >= x) {
				write("Yes\n");
			} else {
				write("No\n");
			}
		} else {
			if (odd > 0 and even > 0 and odd + even >= x) {
				write("Yes\n");
			} else {
				write("No\n");
			}
		}
	} else {
		if (odd % 2 == 0) {
			if (odd > 0 and odd + even - 1 >= x) {
				write("Yes\n");
			} else {
				write("No\n");
			}
		} else {
			write("Yes\n");
		}
	}
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}