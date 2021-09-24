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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(auto &ele : arr)
		cin >> ele;
	if(n == 1) {
		cout << "0\n";
		return;
	}
	if(k % 2 == 1) {
		// ek baar
		int mx = *max_element(arr.begin(), arr.end());
		for(auto &ele : arr) {
			ele = mx - ele;
		}
	} else {
		// do baar
		int mx = *max_element(arr.begin(), arr.end());
		for(auto &ele : arr) {
			ele = mx - ele;
		}
		mx = *max_element(arr.begin(), arr.end());
		for(auto &ele : arr) {
			ele = mx - ele;
		}
	}
	for(auto &ele : arr)
		cout << ele << " ";
	cout << "\n";
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