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
    vector<pair<int, int>> intervals(n);
    vector<pair<int, int>> intervalPoints;
    for (auto &ele : intervals) {
        read(ele.first, ele.second);
        intervalPoints.push_back({ele.first, 1});
        intervalPoints.push_back({ele.second + 1, -1});
    }
    sort(begin(intervalPoints), end(intervalPoints));
    int ans = 0, curr = 0;
    for (const auto &ele : intervalPoints) {
        curr += ele.second;
        ans = max(ans, curr);
    }
    write(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // read(T);
    for (int t = 1; t <= T; ++t) {
        solve();
    }
}