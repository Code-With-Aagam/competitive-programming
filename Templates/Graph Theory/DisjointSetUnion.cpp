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

int main() {
    int n, m, u, v;
    cin >> n >> m;
    DSU* dsu = new DSU(n);
    while (m--) {
        cin >> u >> v;
        dsu -> merge(u - 1, v - 1);
        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[dsu -> parent(i)]++;
        }
        vector<int> curr;
        for (const auto &ele : freq) {
            curr.push_back(ele.second);
        }
        sort(begin(curr), end(curr));
        cout << curr.size() << "\n";
        for (const auto &ele : curr) cout << ele << " ";
        cout << "\n";
    }
    return 0;
}