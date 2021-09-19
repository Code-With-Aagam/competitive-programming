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
	// int t, n, m;
	// read(t);
	// while (t--) {
	// 	read(n, m);
	// 	vector<vector<int>> arr(n, vector<int>(m));
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			read(arr[i][j]);
	// 		}
	// 	}
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			if (arr[i][j] == 1) {
	// 				int x = i - 1;
	// 				while (x >= 0) {
	// 					arr[x][j] = 1;
	// 					x--;
	// 				}
	// 				x = i + 1;
	// 				while (x < n) {
	// 					arr[x][j] = 1;
	// 					x++;
	// 				}
	// 				int y = j - 1;
	// 				while (y >= 0) {
	// 					arr[i][y] = 1;
	// 					y--;
	// 				}
	// 				y = j + 1;
	// 				while (y < m) {
	// 					arr[i][y] = 1;
	// 					y++;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	int cnt = 0;
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			if (arr[i][j] == 0) {
	// 				cnt++;
	// 				arr[i][j] = 1;
	// 				int x = i - 1;
	// 				while (x >= 0) {
	// 					arr[x][j] = 1;
	// 					x--;
	// 				}
	// 				x = i + 1;
	// 				while (x < n) {
	// 					arr[x][j] = 1;
	// 					x++;
	// 				}
	// 				int y = j - 1;
	// 				while (y >= 0) {
	// 					arr[i][y] = 1;
	// 					y--;
	// 				}
	// 				y = j + 1;
	// 				while (y < m) {
	// 					arr[i][y] = 1;
	// 					y++;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	if (cnt % 2 == 1) {
	// 		write("Ashish\n");
	// 	} else {
	// 		write("Vivek\n");
	// 	}
	// }
	int t, n;
	read(t);
	while (t--) {
		read(n);
		vector<int> a(n);
		int ones = 0, zeros = 0, ele;
		for (int i = 0; i < n; i++)
			read(a[i]);
		for (int i = 0; i < n; i++) {
			read(ele);
			if (ele == 0)
				zeros++;
			else
				ones++;
		}
		if ((ones > 0 && zeros > 0) || is_sorted(a.begin(), a.end())) {
			write("Yes\n");
		} else {
			write("No\n");
		}
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
