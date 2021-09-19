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

const int LOG = 20;
int up[100005][LOG];
int depth[100005];

void dfs(vector<int> adj[], int u, int par) {
    if (par != -1) depth[u] = depth[par] + 1;
    for (const auto &v : adj[u]) {
        if (v != par) {
            up[v][0] = u;
            for (int j = 1; j < LOG; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            dfs(adj, v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; --i) {
        if (k & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve(int tc) {
    int n, q, u, v;
    read(n, q);
    vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i) {
        read(u, v);
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, 0, -1);
    while (q--) {
        read(u, v);
        --u;
        --v;
        int w = lca(u, v);
        int len = depth[u] + depth[v] - 2 * depth[w];
        if (len % 2 == 1) {
            write("Road\n");
        } else {
            write("Town\n");
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
}