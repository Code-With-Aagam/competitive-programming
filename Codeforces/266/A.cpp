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
    int n;
    string s;
    cin >>n >>s;
    int i = 0, ans = 0;
    while(i < n - 1){
        if(s[i] != s[i+1]){
            i++;
            continue;
        }
        else{
            ans++;
            i++;
        }
    }
    cout <<ans <<"\n";
    return 0;
}