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

bool good(const pair<int, int> &x, const pair<int, int> &y) {
    return max(x.first, y.first) <= min(x.second, y.second);
}

void solve(int tc) {
    int n, a, b, c;
    read(n);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        read(a, b, c);
        b *= 2;
        c *= 2;
        if (a == 1) {
            arr[i] = make_pair(b, c);
        } else if (a == 2) {
            arr[i] = make_pair(b, c - 1);
        } else if (a == 3) {
            arr[i] = make_pair(b + 1, c);
        } else {
            arr[i] = make_pair(b + 1, c - 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (good(arr[i], arr[j])) ++ans;
        }
    }
    write(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}