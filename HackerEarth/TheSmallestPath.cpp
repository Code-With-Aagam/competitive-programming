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

int n, l;
int timer;
vector<int> tin, tout, parent;
vector<vector<int>> up;

void dfs(vector<int> adj[], int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	parent[v] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : adj[v]) {
		if (u != p)
			dfs(adj, u, v);
	}
	tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int findLCA(int u, int v) {
	if (isAncestor(u, v))
		return u;
	if (isAncestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!isAncestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(vector<int> adj[], int root) {
	tin.resize(n);
	tout.resize(n);
	parent.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(adj, root, root);
}

void solve(int tc) {
	int q, u, v, k;
	read(n, q);
	vector<int> adj[n];
	vector<int> arr(n);
	readContainer(arr);
	for (int i = 0; i < n - 1; ++i) {
		read(u, v);
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preprocess(adj, 0);
	while (q--) {
		read(u, v, k);
		--u;
		--v;
		int lca = findLCA(u, v);
		vector<int> ans;
		while (u != lca) {
			ans.push_back(arr[u]);
			u = parent[u];
		}
		ans.push_back(arr[u]);
		while (v != lca) {
			ans.push_back(arr[v]);
			v = parent[v];
		}
		if (ans.size() < k) {
			write("-1 ");
		} else {
			sort(begin(ans), end(ans));
			write(ans[k - 1], " ");
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
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}