#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

void solve() {
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	i--;
	j--;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<pair<int, int>> ans;
	while(i >= 0) {
		visited[i][j] = true;
		ans.push_back({i + 1, j + 1});
		i--;
	}
	i++;
	while(j >= 0) {
		if(!visited[i][j]) {
			visited[i][j] = true;
			ans.push_back({i + 1, j + 1});
			j--;
		} else {
			j--;
		}
	}
	j++;
	bool left = true;
	while(i < n) {
		int ci = i;
		if(left) {
			for(int cj = 0; cj < m; cj++) {
				if(!visited[ci][cj]) {
					visited[ci][cj] = true;
					ans.push_back({ci + 1, cj + 1});
				}
			}
		} else {
			for(int cj = m - 1; cj >= 0; cj--) {
				if(!visited[ci][cj]) {
					visited[ci][cj] = true;
					ans.push_back({ci + 1, cj + 1});
				}
			}
		}
		left = !left;
		i++;
	}
	for(const auto &ele : ans)
		cout << ele.first << " " << ele.second << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc = 1;
	// cin >> tc;
	while(tc--) {
	    solve();
	}
	return 0;
}
