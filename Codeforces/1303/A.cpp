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
    int t;
    string s;
    cin >>t;
    while(t--){
        cin >>s;
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < n && s[i] != '1')
            i++;
        while(j >= 0 && s[j] != '1')
            j--;
        if(i >= j){
            cout <<"0\n";
        }
        else{
            int ans = 0;
            for(int k = i; k <= j; k++)
                if(s[k] == '0')
                    ans++;
            cout <<ans <<"\n";
        }
    }
    return 0;
}
