#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007;
const int inf = 1e18;
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

const int N = 1e6 + 1;
vector<pair<int, int>> ways(N);

void precomputation() {
	ways[1] = make_pair(1, 1);
	for (int n = 2; n < N; ++n) {
		auto curr = make_pair(0, 0);

		curr.first += ways[n - 1].second;
		curr.first += (2LL * ways[n - 1].first) % mod;
		curr.first %= mod;

		curr.second += ways[n - 1].first;
		curr.second += (4LL * ways[n - 1].second) % mod;
		curr.second %= mod;

		ways[n] = curr;
	}
}

/**
 * Recursive -> TLE
 *
 * n               = Number of Ways to tile from 1 to n
 * belowTilesSplit = Below Tiles are split or joined
 */
int solve(int n, bool belowTilesSplit) {
	if (n == 1) {
		return 1;
	}
	if (belowTilesSplit) {
		int ans = (4LL * solve(n - 1, true)) % mod;
		ans += solve(n - 1, false) % mod;
		ans %= mod;
		return ans;
	} else {
		int ans = solve(n - 1, true);
		ans += (2LL * solve(n - 1, false)) % mod;
		ans %= mod;
		return ans;
	}
}

void solve() {
	int n;
	read(n);
	int ans = ways[n].first;
	ans += ways[n].second;
	ans %= mod;
	write(ans, "\n");
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	precomputation();
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}