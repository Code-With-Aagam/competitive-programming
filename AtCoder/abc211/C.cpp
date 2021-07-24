#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t = "chokudai";
    cin >> s;
    int n = s.size(), mod = 1e9 + 7, m = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; ++j) dp[0][j] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (t[i - 1] != s[j - 1]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
            }
        }
    }
    cout << dp[m][n];
    return 0;
}