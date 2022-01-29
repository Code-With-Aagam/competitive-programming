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

void dfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> path, vector<vector<int>> &allPaths) {
    visited[u] = true;
    path.push_back(u);
    bool seen = false;
    for (const auto &v : adj[u]) {
        if (visited[v] == false) {
            seen = true;
            dfs(adj, v, visited, path, allPaths);
        }
    }
    if (seen == false) {
        allPaths.push_back(path);
    }
}

void solve(int tc) {
    int n, u, v;
    read(n);
    vector<int> c(n);
    readContainer(c);
    vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i) {
        read(u, v);
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> allPaths;
    vector<int> path;
    vector<bool> visited(n, false);
    dfs(adj, 0, visited, path, allPaths);
    int ans = 0;
    for (int i = 0; i < (int)allPaths.size(); ++i) {
        for (int j = 0; j < (int)allPaths.size(); ++j) {
            if (i != j) {
                vector<int> pathOne = allPaths[i];
                vector<int> pathTwo = allPaths[j];
                if (pathOne.size() > 1 && pathTwo.size() > 1 && pathOne[1] != pathTwo[1]) {
                    int currentSum = c[pathOne[0]];
                    for (int k = 1; k < (int)pathOne.size(); ++k) {
                        currentSum += c[pathOne[k]];
                    }
                    for (int k = 1; k < (int)pathTwo.size(); ++k) {
                        currentSum += c[pathTwo[k]];
                    }
                    ans = max(ans, currentSum);
                }
            }
        }
    }
    if (ans == 0) {
        for (const auto &eachPath : allPaths) {
            int currentSum = 0;
            for (const auto &eachNode : eachPath) {
                currentSum += c[eachNode];
            }
            ans = max(ans, currentSum);
        }
    }
    write("Case #", tc, ": ", ans, "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    read(T);
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
}