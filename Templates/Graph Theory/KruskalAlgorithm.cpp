#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> id, rank;

public:
    DSU(int n) {
        id.resize(n, 0);
        rank.resize(n, 1);
        iota(begin(id), end(id), 0);
    }

    int parent(int u) {
        while (u != id[u]) {
            id[u] = id[id[u]];
            u = id[u];
        }
        return u;
    }

    void merge(int u, int v) {
        u = parent(u);
        v = parent(v);
        if (rank[u] < rank[v]) {
            id[u] = v;
            rank[v] += rank[u];
        } else {
            id[v] = u;
            rank[u] += rank[v];
        }
    }
};

class Edge {
public:
    int u, v, w;
};

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    vector<Edge*> edges(m, nullptr);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        Edge* edge = new Edge();
        edge -> u = u;
        edge -> v = v;
        edge -> w = w;
        edges[i] = edge;
    }
    sort(begin(edges), end(edges), [&](const Edge* x, const Edge* y) {
        return x -> w < y -> w;
    });
    DSU* dsu = new DSU(n);
    int ans = 0;
    for (const auto &edge : edges) {
        u = edge -> u;
        v = edge -> v;
        w = edge -> w;
        u = dsu -> parent(u);
        v = dsu -> parent(v);
        if (u != v) {
            dsu -> merge(u, v);
            ans += w;
        }
    }
    cout << ans << "\n";
    return 0;
}