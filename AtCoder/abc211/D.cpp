#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, u, v, mod = 1e9 + 7;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans(n, 0LL), dist(n, INT_MAX);
    vector<bool> visited(n, false);
    queue<int> q;
    dist[0] = 0;
    ans[0] = 1;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto &next : adj[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
            if (dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                ans[next] = ans[curr];
            } else if (dist[next] == dist[curr] + 1) {
                ans[next] = (ans[next] + ans[curr]) % mod;
            }
        }
    }
    cout << ans[n - 1];
    return 0;
}