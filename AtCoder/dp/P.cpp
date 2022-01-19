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

void dfs(vector<int> adj[], vector<vector<int>> &ways, int u, int p) {
	ways[u][0] = ways[u][1] = 1;
	for (const auto &v : adj[u]) {
		if (v != p) {
			dfs(adj, ways, v, u);
			ways[u][0] *= (ways[v][0] + ways[v][1]);
			ways[u][0] %= mod;
		}
	}
	for (const auto &v : adj[u]) {
		if (v != p) {
			ways[u][1] *= ways[v][0];
			ways[u][1] %= mod;
		}
	}
}

void solve() {
	int n, x, y;
	read(n);
	vector<int> adj[n + 1];
	for (int i = 0; i < n - 1; ++i) {
		read(x, y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<vector<int>> ways(n + 1, vector<int>(2));
	dfs(adj, ways, 1, -1);
	write((ways[1][0] + ways[1][1]) % mod);
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