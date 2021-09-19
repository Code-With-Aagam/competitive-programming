/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int f(int a, int b, int c){
    if(a >= b && a >= c)
        return a;
    if(b >= a && b >= c)
        return b;
    if(c >= a && c >= b)
        return c;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, c, n;
    cin >>t;
    while(t--){
        cin >>a >>b >>c >>n;
        int m = f(a, b, c);
        a = m - a;
        b = m - b;
        c = m - c;
        if((a + b + c) > n){
            cout <<"NO\n";
            continue;
        }
        n = n - (a + b + c);
        if(n % 3 == 0){
            cout <<"YES\n";
        }
        else{
            cout <<"NO\n";
        }
    }
    return 0;
}
