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

class DSU {
	vector<int> id, rank;

public:
	DSU(int n) {
		id.resize(n, 0);
		rank.resize(n, 1);
		iota(begin(id), end(id), 0);
	}

	int parent(int u) {
		while (u != id[u]) {
			id[u] = id[id[u]];
			u = id[u];
		}
		return u;
	}

	void merge(int u, int v) {
		u = parent(u);
		v = parent(v);
		if (rank[u] < rank[v]) {
			id[u] = v;
			rank[v] += rank[u];
		} else {
			id[v] = u;
			rank[u] += rank[v];
		}
	}
};

void solve() {
	int n, m, u, v;
	read(n, m);
	DSU* dsu = new DSU(n + 1);
	while (m--) {
		read(u, v);
		dsu -> merge(u, v);
	}
	set<int> roads;
	for (int i = 1; i <= n; ++i) {
		u = dsu -> parent(i);
		roads.insert(u);
	}
	write(roads.size() - 1, "\n");
	vector<int> ans(all(roads));
	for (int i = 1; i < ans.size(); ++i) {
		write(ans[i - 1], " ", ans[i], "\n");
	}
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