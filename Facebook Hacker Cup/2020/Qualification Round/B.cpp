#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
inline istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x : a)
        in >> x;
    return in;
}

template <typename T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x : a)
        out << x << " ";
    return out;
}

void solve() {
    int t, n;
    cin >> t;
    int cnt = 1;
    while (t--) {
        string s;
        cin >> n >> s;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
            } else {
                b++;
            }
        }
        cout << "Case #" << cnt << ": ";
        cnt++;
        if (abs(a - b) == 1) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
