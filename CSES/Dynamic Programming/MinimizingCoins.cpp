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

const int INF = 1e18;
/**
 * Recursive -> TLE
 * */
int findMinimumCoins(const vector<int> &coins, int x) {
	if (x < 0) {
		return INF;
	} else if (x == 0) {
		return 0;
	} else {
		int ans = INF;
		for (const auto &coin : coins) {
			ans = min(ans, 1 + findMinimumCoins(coins, x - coin));
		}
		return ans;
	}
}

void solve() {
	int n, X;
	read(n, X);
	vector<int> coins(n);
	readContainer(coins);
	vector<int> minCoins(X + 1, INF);
	minCoins[0] = 0;
	for (int x = 1; x <= X; ++x) {
		for (const auto &coin : coins) {
			if (x - coin >= 0) {
				minCoins[x] = min(minCoins[x], 1 + minCoins[x - coin]);
			}
		}
	}
	if (minCoins.back() == INF) minCoins.back() = -1;
	write(minCoins.back(), "\n");
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