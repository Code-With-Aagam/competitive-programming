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
    long long t, a, b;
    cin >>t;
    while(t--){
        cin >>a >>b;
        if(a == b){
            cout <<"0\n";
        }
        else if(a > b){
            if(a % 2 != b % 2){
                cout <<"2\n";
            }
            else {
                cout <<"1\n";
            }
        }
        else {
            if (a % 2 != b % 2){
                cout <<"1\n";
            }
            else {
                cout <<"2\n";
            }
        }
    }
    return 0;
}