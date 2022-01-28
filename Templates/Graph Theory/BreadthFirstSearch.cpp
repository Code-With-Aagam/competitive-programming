#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, u, v, x;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> x;
    vector<int> level(n + 1, 0);
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while (not q.empty()) {
        u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (level[v] == 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    cout << count(cbegin(level), cend(level), x) << "\n";
    return 0;
}