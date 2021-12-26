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

/**
 * Recursive Approach -> TLE
 */
int countNumberOfWays(int N) {
	if (N < 0) {
		return 0;
	} else if (N == 0) {
		return 1;
	} else {
		int ways = 0;
		for (int x = 1; x <= 6; ++x) {
			ways += countNumberOfWays(N - x);
		}
		return ways;
	}
}

void solve() {
	int N;
	read(N);
	vector<int> ways(N + 1, 0);
	ways[0] = 1;
	for (int n = 1; n <= N; ++n) {
		for (int x = 1; x <= 6; ++x) {
			if (n - x >= 0) {
				ways[n] += ways[n - x];
				ways[n] %= mod;
			}
		}
	}
	write(ways.back(), "\n");
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