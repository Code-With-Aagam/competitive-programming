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
	vector<int> arr(n);
	readContainer(arr);
	vector<int> freq(n + 1, 0), ans(n + 1, -1);
	for (const auto &ele : arr) freq[ele]++;
	stack<int> extra;
	int cnt = 0, move = 0;
	for (int mex = 0; mex <= n; ++mex) {
		if (cnt >= mex) {
			ans[mex] = move + freq[mex];
		}
		cnt += freq[mex];
		if (freq[mex] == 0) {
			while (not extra.empty() and freq[extra.top()] < 2) {
				extra.pop();
			}
			if (extra.empty()) break;
			int take = extra.top();
			freq[take]--;
			freq[mex]++;
			move += mex - take;
		} else if (freq[mex] >= 2) {
			extra.push(mex);
		}
	}
	writeContainer(ans);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
}