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

template <typename T>
class SegmentTree {
    int size;
    vector<T> tree;

    void build(const vector<T> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size()) tree[x] = arr[lx];
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = lx + (rx - lx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int right = query(l, r, 2 * x + 2, m, rx);
        return merge(left, right);
    }

    T merge(T left, T right) {
        return __gcd(left, right);
    }

   public:
    SegmentTree(const vector<T> &arr) {
        int n = (int)arr.size();
        size = 1;
        while (size <= n) size *= 2;
        tree.resize(2 * size);
        build(arr, 0, 0, size);
    }

    void set(int i, T v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void solve() {
    int n;
    read(n);
    vector<int> a(n);
    readContainer(a);
    if (n == 1) {
        write(1, "\n");
        return;
    }
    vector<int> diff;
    for (int i = 1; i < n; ++i) {
        diff.push_back(abs(a[i] - a[i - 1]));
    }
    SegmentTree<int> tree(diff);
    int lo = 0, hi = 0, ans = 1;
    n = diff.size();
    while (lo < n and hi < n) {
        if (tree.query(lo, hi + 1) > 1) {
            ++hi;
            ans = max(ans, hi - lo + 1);
        } else {
            ++lo;
            if (lo > hi) hi = lo;
        }
    }
    write(ans, "\n");
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