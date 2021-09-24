#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

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

void solve(int tc) {
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	int mx = *max_element(cbegin(arr), cend(arr));
	int mn = *min_element(cbegin(arr), cend(arr));
	int idxMin = 0, idxMax = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == mn) {
			idxMin = i;
		} else if (arr[i] == mx) {
			idxMax = i;
		}
	}
	write(min({max(idxMin + 1, idxMax + 1), max(n - idxMin, n - idxMax), min(idxMin + 1 + n - idxMax, idxMax + 1 + n - idxMin)}), "\n");
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 1;
	read(tc);
	for (int curr = 1; curr <= tc; ++curr) {
		solve(curr);
	}
	return 0;
}