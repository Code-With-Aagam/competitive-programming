#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<int> adj[], vector<bool> &visited, int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (const auto &v : adj[u]) {
        dfs(adj, visited, v);
    }
}

int main() {
    int n, m, u, v, x;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> x;
    vector<bool> visited(n + 1, false);
    visited[0] = true;
    dfs(adj, visited, x);
    cout << count(cbegin(visited), cend(visited), false) << "\n";
    return 0;
}