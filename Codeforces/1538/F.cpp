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

int c(int a, int b) {
	string x = to_string(a), y = to_string(b);
	int ans = y.size() - x.size();
	int i = 0, j = 0;
	if (ans == 1) j = 1;
	while (i < x.size() && j < y.size()) {
		if (x[i] != y[j]) ++ans;
		++i;
		++j;
	}
	return ans;
}

vector<int> dig = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

int oneToN(int n) {
	string s = to_string(n);
	int ans = 0, curr = 1;
	for (int i = s.size() - 1; i >= 0; --i) {
		int d = s[i] - '0';
		ans += d * dig[curr];
		++curr;
	}
	return ans;
}

void solve(int tc) {
	int l, r, ans = 0;
	// write(oneToN(9), "\n");
	// for (int i = 0; i < 9; ++i) {
	// 	ans += c(i, i + 1);
	// }
	// write(ans, "\n\n");
	// ans = 0;
	// write(oneToN(1000000000), "\n");
	// for (int i = 0; i < 1000000000; ++i) {
	// 	ans += c(i, i + 1);
	// }
	// write(ans, "\n\n");
	// ans = 0;
	// write(oneToN(234), "\n");
	// for (int i = 0; i < 234; ++i) {
	// 	ans += c(i, i + 1);
	// }
	// write(ans, "\n\n");
	read(l, r);
	ans = oneToN(r) - oneToN(l);
	write(ans, "\n");
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