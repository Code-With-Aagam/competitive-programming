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
    vector<string> arr(2);
    read(arr[0], arr[1]);
    int ans = 0, i = 0;
    while (i < n) {
        int curr = (arr[0][i] - '0') + (arr[1][i] - '0');
        if (curr == 1) {
            ans += 2;
            ++i;
            continue;
        }
        if (curr == 0) {
            if (i + 1 < n && (arr[0][i + 1] - '0') + (arr[1][i + 1] - '0') == 2) {
                ans += 2;
                i += 2;
            } else {
                ++ans;
                ++i;
            }
            continue;
        }
        if (i + 1 < n) {
            int next = (arr[0][i + 1] - '0') + (arr[1][i + 1] - '0');
            if (next <= 1) {
                ans += 2;
                i += 2;
            } else {
                ++i;
            }
        } else {
            ++i;
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
        solve(t);
    }
}