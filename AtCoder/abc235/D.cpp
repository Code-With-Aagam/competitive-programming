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
	int a, N;
	read(a, N);
	queue<pair<int, int>> Q;
	Q.push(make_pair(1, 0));
	while (not Q.empty()) {
		auto curr = Q.front();
		Q.pop();
		int x = curr.first, ops = curr.second;
		if (x == N) {
			write(ops);
			return;
		}
		if (x * a <= N) Q.push(make_pair(x * a, ops + 1));
		if (x >= 10 and x % 10 != 0) {
			string s = to_string(x);
			rotate(begin(s), begin(s) + s.size() - 1, end(s));
			int y = stoi(s);
			if (x != y and y <= N) Q.push(make_pair(y, ops + 1));
		}
	}
	write(-1);
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