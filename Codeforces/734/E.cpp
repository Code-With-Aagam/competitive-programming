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

int ans = 0, source = 0;

void dfs(vector<int> adj[], const vector<int> &color, int u, int par, int dist) {
    if (dist > ans) {
        source = u;
        ans = dist;
    }
    for (const auto &v : adj[u]) {
        if (v != par) {
            dfs(adj, color, v, u, dist + (color[u] ^ color[v]));
        }
    }
}

void solve(int tc) {
    int n, u, v;
    read(n);
    vector<int> color(n);
    readContainer(color);
    vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i) {
        read(u, v);
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Compression
    source = 0;
    dfs(adj, color, source, source, 0);
    // Merging
    dfs(adj, color, source, source, 0);
    write((ans + 1) >> 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}