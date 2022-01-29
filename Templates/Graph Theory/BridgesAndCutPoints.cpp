#include <bits/stdc++.h>
using namespace std;

int timer = 1;
vector<int> in, low;
vector<bool> visited;
set<int> cutVertices;
set<pair<int, int>> bridges;

void dfs(const vector<int> adj[], int u, int p = -1) {
    visited[u] = true;
    in[u] = low[u] = timer++;
    int children = 0;
    for (const auto &v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], in[v]);
        } else {
            dfs(adj, v, u);
            if (low[v] > in[u]) {
                bridges.insert(make_pair(u, v));
            }
            low[u] = min(low[u], low[v]);
            if (low[v] >= in[u] and p != -1) {
                cutVertices.insert(u);
            }
            ++children;
        }
    }
    if (p == -1 and children > 1) {
        cutVertices.insert(u);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.resize(n, false);
    in.resize(n, 0);
    low.resize(n, 0);
    dfs(adj, 0);
    cout << cutVertices.size() << "\n";
    for (const auto &ele : cutVertices) cout << ele << " ";
    cout << "\n";
    cout << bridges.size() << "\n";
    for (const auto &ele : bridges) cout << ele.first << " " << ele.second << "\n";
    return 0;
}