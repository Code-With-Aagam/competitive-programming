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
	// int a, b, x, y, n;
	// cin >> a >> b >> x >> y >> n;
	// if(a < b) {
	// 	// a-- && a >= x
	// 	// if(required < available)
	// 	if(a - x < n) {
	// 		int used = a - x;
	// 		a = x;
	// 		int available = n - used;
	// 		if(available >= b - y) {
	// 			b = y;
	// 		} else {
	// 			b -= available;
	// 		}
	// 		cout << a * b << "\n";
	// 	} else {
	// 		a -= n;
	// 		cout << a * b << "\n";
	// 	}
	// } else {
	// 	// b-- && b >= y
	// 	if(b - y < n) {
	// 		int used = b - y;
	// 		b = y;
	// 		int available = n - used;
	// 		if(available >= a - x) {
	// 			a = x;
	// 		} else {
	// 			a -= available;
	// 		}
	// 		cout << a * b << "\n";
	// 	} else {
	// 		b -= n;
	// 		cout << a * b << "\n";
	// 	}
	// }
	long double a, b;
	cin >> a >> b;
	cout << (int) ceil(abs(a - b) / 10) << "\n";
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
