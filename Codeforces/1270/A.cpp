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
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k1, k2, ele;
    cin >>t;
    while(t--){
        cin >>n >>k1 >>k2;
        priority_queue<int> a, b;
        for(int i = 0; i < k1; i++){
            cin >>ele;
            a.push(ele);
        }
        for(int i = 0; i < k2; i++){
            cin >>ele;
            b.push(ele);
        }
        while(!a.empty() && !b.empty()){
            int x = a.top();
            int y = b.top();
            a.pop();
            b.pop();
            if(x > y){
                a.push(x);
                a.push(y);
            }
            else{
                b.push(x);
                b.push(y);
            }
        }
        if(a.empty())
            cout <<"NO\n";
        else 
            cout <<"YES\n";
    }
    return 0;
}
