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
	string s;
	read(s);
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	vector<int> ans(n + 1);
	for(int len = 1; len <= n; len++) {
		for(int l = 0; l < n - len + 1; l++) {
			int r = l + len;
			if(len == 1) {
				dp[l][r] = 1;
				continue;
			} else if(len == 2) {
				dp[l][r] = (s[l] == s[r - 1] ? 2 : 0);
				continue;
			}
			if (s[l] != s[r - 1] || !dp[l + 1][r - 1]) {
                continue;
            }
            dp[l][r] = 1;
            int m = (l + r) / 2;
            if (len & 1) {
                if (dp[l][m] && dp[m + 1][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            } else {
                if (dp[l][m] && dp[m][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            }
		}
	}
	for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            ans[dp[l][l + len]]++;
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    
    for (int i = 1; i <= n; i++) {
        write(ans[i], " ");
    }
    write("\n");
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
