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
    auto gcdInRange = [&](int l, int r) {
        int g = diff[l];
        for (int i = l + 1; i <= r; ++i) {
            g = __gcd(g, diff[i]);
        }
        return g;
    };
    int lo = 0, hi = 0, ans = 0;
    n = diff.size();
    while (lo < n and hi < n) {
        if (gcdInRange(lo, hi) > 1) {
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