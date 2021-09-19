/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class... Args>
auto create(size_t n, Args&&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
    ((cout << args), ...);
}

string solveUtil(string s) {
    long double sum1 = 0.0, sum2 = 0.0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            if (i < n / 2) {
                sum1 += (long double)(s[i] - '0');
            } else {
                sum2 += (long double)(s[i] - '0');
            }
        } else {
            if (i < n / 2) {
                sum1 += (long double)4.5;
            } else {
                sum2 += (long double)4.5;   
            }
        }
    }
    if (fabsl(sum1 - sum2) < 1e-9) {
        return "Bicarp";
    } else {
        return "Monocarp";
    }
}


void solve() {
    int n;
    string s;
    read(n, s);
    write(solveUtil(s));
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
