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

const int N = 50005;
vector<int> treeee(4 * N);
vector<int> A;

void buildTree(int v, int left, int right) {
	if (left == right)
		treeee[v] = A[left];
	else {
		int mid = left + (right - left) / 2;
		buildTree(v * 2, left, mid);
		buildTree(v * 2 + 1, mid + 1, right);
		treeee[v] = treeee[v * 2] + treeee[v * 2 + 1];
	}
}

int query(int v, int left, int right, int li, int ri) {
	if (li > ri)
		return 0;
	if (left == li && right == ri)
		return treeee[v];
	int mid = left + (right - left) / 2;
	return query(v * 2, left, mid, li, min(ri, mid)) + query(v * 2 + 1, mid + 1, right, max(li, mid + 1), ri);
}

void solve() {
	int t, a, b, q, li, ri;
	cin >> t;
	while (t--) {
		A.clear();
		treeee.clear();
		cin >> a >> b >> q;
		int m = (a * b) / __gcd(a, b);
		A.resize(m, 0);
		for (int i = 0; i < m; i++)
			if ((i % a) % b != (i % b) % a)
				A[i] = 1;
		buildTree(1, 0, m - 1);
		while (q--) {
			cin >> li >> ri;
			cout << query(1, 0, m - 1, li % m, m - 1) + query(1, 0, m - 1, 0, ri % m) + ((ri - li - ri % m + li % m - m) / m) * query(1, 0, m - 1, 0, m - 1) << " ";
		}
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
