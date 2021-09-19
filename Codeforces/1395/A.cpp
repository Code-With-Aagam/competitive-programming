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
	int r, g, b, w;
	cin >> r >> g >> b >> w;
	if(r == 0 || g == 0 || b == 0) {
		r %= 2;
		g %= 2;
		b %= 2;
		w %= 2;
		cout << ((r + g + b + w) <= 1 ? "Yes\n" : "No\n");
		return;
	}

	int cr = r, cg = g, cb = b, cw = w;
	cr--;
	cg--;
	cb--;
	cw += 3;
	cr %= 2;
	cg %= 2;
	cb %= 2;
	cw %= 2;
	r %= 2;
	g %= 2;
	b %= 2;
	w %= 2;
	cout << (((r + g + b + w) <= 1 || (cr + cg + cb + cw) <= 1) ? "Yes\n" : "No\n");
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
