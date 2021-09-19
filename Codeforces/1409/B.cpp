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

int f(int a, int b, int x, int y, int n) {
	if(n > (a - x)) {
		n -= (a - x);
		a = x;
		if(n > (b - y)) {
			b = y;
		} else {
			b -= n;
		}
	} else {
		a -= n;
	}
	return a * b;
}

int g(int a, int b, int x, int y, int n) {
	if(n > (b - y)) {
		n -= (b - y);
		b = y;
		if(n > (a - x)) {
			a = x;
		} else {
			a -= n;
		}
	} else {
		b -= n;
	}
	return a * b;
}

void solve() {
	int a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	cout << min(f(a, b, x, y, n), g(a, b, x, y, n)) << "\n";
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
