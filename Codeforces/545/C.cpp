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

void solve() {
	int n;
	read(n);
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = make_pair(0, 0);
		read(arr[i].first, arr[i].second);
	}
	vector<vector<int>> dp(n + 1, vector<int>(2));
	for (int i = n - 1; i >= 0; --i) {
		if (i == 0 or arr[i].first - arr[i - 1].first > arr[i].second) {
			dp[i][0] = 1 + dp[i + 1][0];
		} else {
			dp[i][0] = dp[i + 1][0];
			if (i == n - 1 or arr[i + 1].first - arr[i].first > arr[i].second) {
				dp[i][0] = max(dp[i][0], 1 + dp[i + 1][1]);
			}
		}
		if (i == 0 or arr[i].first - arr[i - 1].first > arr[i].second + arr[i - 1].second) {
			dp[i][1] = 1 + dp[i + 1][0];
		} else {
			dp[i][1] = dp[i + 1][0];
			if (i == n - 1 or arr[i + 1].first - arr[i].first > arr[i].second) {
				dp[i][1] = max(dp[i][1], 1 + dp[i + 1][1]);
			}
		}
	}
	write(dp[0][0], "\n");
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