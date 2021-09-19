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
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >>a[i];
        for(int i = 0; i < n; i++)
            cin >>b[i];
        for(int i = 0; i < n; i++)
            b[i] -= a[i];
        int i = 0, j = n - 1;
        set<int> temp;
        for(auto x : b)
            temp.insert(x);
        if(temp.size() == 1 && b[0] == 0){
            cout <<"YES\n";
            continue;
        }
        while(i < n && b[i] == 0)
            i++;
        while(j >= 0 && b[j] == 0)
            j--;
        set<int> st;
        for(int k = i; k <= j; k++)
            st.insert(b[k]);
        if(st.size() == 1 && b[i] >= 0)
            cout <<"YES\n";
        else 
            cout <<"NO\n";
    }
    return 0;
}
