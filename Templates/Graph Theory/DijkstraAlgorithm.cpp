#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        // adj[v].push_back(make_pair(u, w));
    }
    const int inf = 1e9;
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    dist[1] = 0;
    while (not q.empty()) {
        u = q.top().second;
        q.pop();
        for (const auto &node : adj[u]) {
            v = node.first;
            w = node.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 2; i <= n; ++i) cout << dist[i] << " ";
    return 0;
}