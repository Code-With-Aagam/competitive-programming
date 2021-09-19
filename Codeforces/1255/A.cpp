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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b;
    cin >>t;
    while(t--){
        cin >>a >>b;
        int s = abs(a-b);
        int ans = 0;
        if(s%5 == 0){
            cout <<s/5 <<"\n";
            continue;
        }
        else{
            ans += (s/5);
            s -= (ans*5);
        }
        if(s%2 == 0){
            cout <<ans + (s/2) <<"\n";
            continue;
        }
        else{
            ans += (s/2);
            s -= (ans*2);
        }
        cout <<ans + 1 <<"\n";
    }
    return 0;
}
