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