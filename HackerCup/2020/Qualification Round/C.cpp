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
    int t, n, pi, hi;
    cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> pi >> hi;
            arr[i] = make_pair(pi, hi);
        }
        sort(arr.begin(), arr.end());
        map<int, int> x, y;
        for (int i = 0; i < n; i++) {
            int s = arr[i].first;
            int e = arr[i].first + arr[i].second;
            x[e] = max(x[e], x[s] + arr[i].second);
        }
        for (int i = n - 1; i >= 0; i--) {
            int s = arr[i].first;
            int e = arr[i].first - arr[i].second;
            y[e] = max(y[e], y[s] + arr[i].second);
        }
        int ans = 0;
        for (const auto &it : x)
            ans = max(ans, x[it.first] + y[it.first]);
        for (const auto &it : y)
            ans = max(ans, x[it.first] + y[it.first]);
        cout << "Case #" << cnt << ": " << ans << "\n";
        cnt++;
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
