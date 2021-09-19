#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

int dp[105][105];

bool solve(int i, int j, int n, int m, int curr) {
    if (i <= 0 || j <= 0 || i > n || j > m) return false;
    if (i == n && j == m) return curr == 0;
    if (dp[i][j] != -1) return dp[i][j] == 0 ? false : true;
    if (solve(i + 1, j, n, m, curr - j)) {
        dp[i][j] = 1;
        return true;
    }
    if (solve(i, j + 1, n, m, curr - i)) {
        dp[i][j] = 1;
        return true;
    }
    dp[i][j] = 0;
    return false;
}

void solve(int tc) {
    int n, m, k;
    read(n, m, k);
    memset(dp, -1, sizeof(dp));
    bool good = solve(1, 1, n, m, k);
    write((good ? "YES\n" : "NO\n"));
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}