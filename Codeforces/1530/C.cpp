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

void solve(int tc) {
    int n;
    read(n);
    vector<int> a(n), b(n);
    readContainer(a);
    readContainer(b);
    sort(begin(a), end(a), greater<int>());
    sort(begin(b), end(b), greater<int>());
    auto good = [&](int extra) {
        int contests = n + extra;
        contests = contests - (contests / 4);
        int me = 0, opp = 0, myScore = 0, oppScore = 0;
        for (int i = 0; i < extra; ++i) {
            if (me < contests) {
                myScore += 100;
                me++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (me < contests) {
                me++;
                myScore += a[i];
            }
            if (opp < contests) {
                opp++;
                oppScore += b[i];
            }
        }
        return myScore >= oppScore;
    };
    int lo = 0, hi = 5e5, ans = 5e5;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (good(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    write(ans, "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
}