#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007LL
#define PI acosl(-1)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<char>> arr(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		int ans = 0;
		for (int j = 0; j < m; j++) {
			if (!visited[n - 1][j]) {
				visited[n - 1][j] = true;
				if (arr[n - 1][j] == 'D')
					ans++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i][m - 1]) {
				visited[i][m - 1] = true;
				if (arr[i][m - 1] == 'R')
					ans++;
			}
		}
		cout << ans << "\n";
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}