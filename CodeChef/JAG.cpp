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

class DSU {
   private:
    vector<int> parent;
    vector<int> rank;
    vector<int> mx;
    vector<int> mn;

   public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        mx.resize(n);
        mn.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
            mx[i] = i + 1;
            mn[i] = i + 1;
        }
    }

    int findParent(int u) {
        return parent[u] = (u == parent[u] ? u : findParent(parent[u]));
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u != v) {
            if (rank[u] > rank[v]) {
                parent[v] = u;
                rank[u] += rank[v];
                mx[u] = max({mx[u], mx[v], u + 1, v + 1});
                mn[u] = min({mn[u], mn[v], u + 1, v + 1});
            } else {
                parent[u] = v;
                rank[v] += rank[u];
                mx[v] = max({mx[u], mx[v], u + 1, v + 1});
                mn[v] = min({mn[u], mn[v], u + 1, v + 1});
            }
        }
    }

    bool isSameSet(int u, int v) {
        return findParent(u) == findParent(v);
    }

    int getSizeOfSet(int u) {
        u = findParent(u);
        return rank[u];
    }

    int getMaximumInSet(int u) {
        u = findParent(u);
        return mx[u];
    }

    int getMinimumInSet(int u) {
        u = findParent(u);
        return mn[u];
    }
};

void solve() {
    int n, ans = 0;
    read(n);
    vector<int> w(n);
    readContainer(w);
    DSU *dsu = new DSU(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[i - w[i]]++;
        if (mp[i - w[i]] == 1) {
            ++ans;
        }
    }
    // set<int> ans;
    // for (int i = 0; i < n; ++i) {
    //     ans.insert(dsu->findParent(i));
    // }
    write((ans == n ? 1 : n), "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    read(T);
    for (int t = 1; t <= T; ++t) {
        solve();
    }
}