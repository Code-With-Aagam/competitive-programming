/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int min22(int a, int b, int c){
    return min(min(a, b), c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d, e, f;
    cin >>a >>b >>c >>d >>e >>f;
    // e = t + j
    // f = s + v + j
    // a, b, c, d
    // t, s, v, j
    int cost = 0;
    if(e > f){
        int mn = min(a, d);
        a -= mn;
        d -= mn;
        cost += (mn * e);
        mn = min22(b, c, d);
        if(mn > 0){
            cost += (mn * f);
        }
    }
    else{
        int mn = min22(b, c, d);
        b -= mn;
        c -= mn;
        d -= mn;
        cost += (mn * f);
        mn = min(a, d);
        if(mn > 0){
            cost += (mn * e);
        }
    }
    cout <<cost <<"\n";
    return 0;
}
