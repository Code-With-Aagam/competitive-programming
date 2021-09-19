/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool f(int h, int n, int m) {
	if (h <= 0) {
		return true;
	}
	if (h <= 10 && m > 0) {
		return true;
	}
	if (h <= 10 && m == 0) {
		return false;
	}
	if (n == 0 && m == 0 && h > 0) {
		return false;
	}
	if (n > 0) {
		return f((h / 2) + 10, n - 1, m);
	}
	return f(h - 10, n, m - 1);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, h, n, m;
	cin >> t;
	while (t--) {
		cin >> h >> n >> m;
		cout << (f(h, n, m) ? "YES\n" : "NO\n");
	}
	return 0;
}
