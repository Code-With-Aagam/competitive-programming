#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
// #define int long long

constexpr int mod = 1e9 + 7;
// constexpr int infinity = 1e18;
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

constexpr int N = 1e5 + 1;
int n, m, ans = 0;
vector<int> cats;
vector<int> adj[N];

void dfs(int u, int p, vector<int> &path) {
	path.push_back(cats[u]);
	int cnt = 0;
	for (const auto &v : adj[u]) {
		if (v != p) {
			++cnt;
			dfs(v, u, path);
		}
	}
	if (cnt == 0) {
		vector<int> arr = path;
		for (int i = 1; i < arr.size(); ++i) {
			if (arr[i] == 1) {
				arr[i] += arr[i - 1];
			}
		}
		bool good = true;
		for (const auto &ele : arr) {
			if (ele > m) {
				good = false;
				break;
			}
		}
		if (good) ++ans;
	}
	path.pop_back();
}

void solve() {
	int u, v;
	read(n, m);
	cats.resize(n);
	readContainer(cats);
	for (int i = 1; i < n; ++i) {
		read(u, v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	vector<int> path;
	dfs(0, -1, path);
	write(ans);
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