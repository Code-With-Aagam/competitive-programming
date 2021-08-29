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

bool bfs(vector<int> adj[], vector<vector<int>> &dist, vector<int> &path, int source, int destination) {
    if (source == destination) return true;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (path[v] == 0) {
                path[v] = path[u] + 1;
                q.push(v);
            }
            if (v == destination) {
                dist[source][destination] = path[destination];
                return true;
            }
        }
    }
    return false;
}

void solve(int tc) {
    string s;
    int k, ans = -1;
    read(s, k);
    vector<int> adj[26];
    vector<int> path(26);
    vector<vector<int>> dist(26, vector<int>(26, 0));
    while (k--) {
        char u, v;
        read(u, v);
        adj[u - 'A'].push_back(v - 'A');
    }
    for (int destination = 0; destination < 26; destination++) {
        bool good = true;
        int curr = 0;
        for (const auto &source : s) {
            for (auto &ele : path) ele = 0;
            if (bfs(adj, dist, path, source - 'A', destination) == false) {
                good = false;
                break;
            } else {
                curr += dist[source - 'A'][destination];
            }
        }
        if (good == false) continue;
        if (ans == -1 || curr < ans) {
            ans = curr;
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