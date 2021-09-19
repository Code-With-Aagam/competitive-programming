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
	string s;
	cin >> s;
	int n = s.size();
	int curr = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			curr++;
		} else if (curr != 0){
			ans.push_back(curr);
			curr = 0;
		}
	}
	if(s[n - 1] == '1')
		ans.push_back(curr);
	sort(ans.begin(), ans.end());
	int cnt = 0;
	if(!ans.empty()) {
		for(int i = ans.size() - 1; i >= 0; i -= 2) {
			cnt += ans[i];
		}
	}
	cout << cnt << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc = 1;
	cin >> tc;
	while(tc--) {
	    solve();
	}
	return 0;
}
