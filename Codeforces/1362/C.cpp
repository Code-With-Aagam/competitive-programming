/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
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

template<class... Args>
auto create(size_t n, Args&&... args) {
	if constexpr(sizeof...(args) == 1)
		return vector(n, args...);
	else
		return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args), ...);
}

void solve() {
	// int t, n;
	// read(t);
	// while (t--) {
	// 	read(n);
	// 	vector<int> arr(n);
	// 	for (int i = 0; i < n; i++)
	// 		read(arr[i]);
	// 	sort(arr.begin(), arr.end());
	// 	int ans = -1;
	// 	for (int i = 1; i <= 1024; i++) {
	// 		vector<int> temp;
	// 		for (auto ele : arr) {
	// 			temp.push_back(ele ^ i);
	// 		}
	// 		sort(temp.begin(), temp.end());
	// 		if (arr == temp) {
	// 			ans = i;
	// 			break;
	// 		}
	// 	}
	// 	write(ans);
	// 	write("\n");
	// }
	int t, n;
	read(t);
	while (t--) {
		read(n);
		int p = 1, ans = 0;
		while (n != 0) {
			ans += (p * ((n / 2) + (n % 2)));
			p++;
			n /= 2;
		}
		write(ans);
		write("\n");
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
