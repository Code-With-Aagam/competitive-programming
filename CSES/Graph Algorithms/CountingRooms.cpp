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

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void dfs(vector<string> &grid, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '.') {
        return;
    }
    grid[i][j] = '$';
    for (int k = 0; k < 4; ++k) {
        dfs(grid, i + dx[k], j + dy[k], n, m);
    }
}

void solve() {
    int n, m;
    read(n, m);
    vector<string> grid(n);
    for (auto &ele : grid) read(ele);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                dfs(grid, i, j, n, m);
                ++ans;
            }
        }
    }
    write(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // read(T);
    for (int t = 1; t <= T; ++t) {
        solve();
    }
}