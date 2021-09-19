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
    long long n, k;
    string s;
    char c;
    cin >>n >>k;
    cin >>s;
    unordered_map<char, int> mp;
    for(long long i = 0; i < k; i++){
        cin >>c;
        mp[c] = 1;
    }
    vector<bool> flag(n, false);
    for(long long i = 0; i < n; i++){
        if(mp[s[i]] == 1)
            flag[i] = true;
    }
    long long ans = 0, temp = 0;
    for(auto f : flag){
        if(f == false){
            ans += (temp * (temp + 1)) / 2;
            temp = 0;
        }
        else 
            temp++;
    }
    if(flag[n-1] == true)
        ans += (temp * (temp + 1)) / 2;    
    cout <<ans <<"\n";
    return 0;
}
