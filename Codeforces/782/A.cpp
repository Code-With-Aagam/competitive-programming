/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, ele;
    cin >>n;
    n *= 2;
    unordered_map<long long, long long> mp;
    long long ans = 0, cnt = 0;
    for(long long i = 0; i < n; i++){
        cin >>ele;
        mp[ele]++;
        if(mp[ele] == 2){
            cnt--;
        }   
        else{
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout <<ans <<"\n";
    return 0; 
}
