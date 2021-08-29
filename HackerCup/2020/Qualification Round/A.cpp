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
    string a, b;
    cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> n >> a >> b;
        cout << "Case #" << cnt << ":\n";
        cnt++;
        vector<vector<char>> ans(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    ans[i][j] = 'Y';
                    continue;
                }
                if (abs(i - j) == 1) {
                    if (a[j] == 'Y' && b[i] == 'Y') {
                        ans[i][j] = 'Y';
                    } else {
                        ans[i][j] = 'N';
                    }
                    continue;
                }
                ans[i][j] = 'N';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - j) > 1) {
                    if (i > j) {
                        bool flag = true;
                        for (int k = i; k > j; k--) {
                            if (ans[k][k - 1] == 'N') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag == true) {
                            ans[i][j] = 'Y';
                        } else {
                            ans[i][j] = 'N';
                        }
                    } else {
                        bool flag = true;
                        for (int k = i; k < j; k++) {
                            if (ans[k][k + 1] == 'N') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag == true) {
                            ans[i][j] = 'Y';
                        } else {
                            ans[i][j] = 'N';
                        }
                    }
                }
            }
        }
        for (const auto &row : ans) {
            for (const auto &ele : row)
                cout << ele;
            cout << "\n";
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
