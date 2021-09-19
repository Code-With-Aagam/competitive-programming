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

void solve(int tc) {
    int n, m;
    read(n, m);
    vector<vector<int>> ans(n, vector<int>(m, 0));
    auto safe = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int j = 0; j < m; j += 2) ans[0][j] = 1;
    for (int i = 2; i < n; i += 2) ans[i][0] = 1;
    for (int j = 1; j < m; ++j) {
        /// ans[n - 1][j]
        bool good = true;
        for (int k = 0; k < 8; ++k) {
            int nx = n - 1 + dx[k];
            int ny = j + dy[k];
            if (safe(nx, ny) && ans[nx][ny] == 1) good = false;
        }
        if (good) ans[n - 1][j] = 1;
    }
    for (int i = 1; i < n; ++i) {
        /// ans[i][m - 1]
        bool good = true;
        for (int k = 0; k < 8; ++k) {
            int nx = i + dx[k];
            int ny = m - 1 + dy[k];
            if (safe(nx, ny) && ans[nx][ny] == 1) good = false;
        }
        if (good) ans[i][m - 1] = 1;
    }
    for (const auto &row : ans) {
        for (const auto &e : row) write(e);
        write("\n");
    }
    write("\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
}