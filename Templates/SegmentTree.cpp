#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
    int _size;
    vector<T> _tree;

    void build(const vector<T> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size()) _tree[x] = arr[lx];
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        _tree[x] = merge(_tree[2 * x + 1], _tree[2 * x + 2]);
    }

    void update(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            _tree[x] = v;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }
        _tree[x] = merge(_tree[2 * x + 1], _tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return _tree[x];
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
        _size = 1;
        while (size <= n) _size *= 2;
        _tree.resize(2 * _size);
        build(arr, 0, 0, _size);
    }

    void update(int i, T v) {
        update(i, v, 0, 0, _size);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, _size);
    }
};