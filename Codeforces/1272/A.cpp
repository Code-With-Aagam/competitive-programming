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
    long long t, a, b, c;
    cin >>t;
    while(t--){
        cin >>a >>b >>c;
        vector<long long> temp = {a, b, c};
        sort(temp.begin(), temp.end());
        a = temp[0];
        b = temp[1];
        c = temp[2];
        bool flag = false;
        if(a == b && b == c){
            flag = true;
        }
        else if(a == b && b != c){
            c--;
            if(b != c){
                a++;
                b++;
            }
        }
        else if(a != b && b == c){
            a++;
            if(a != b){
                b--;
                c--;
            }
        }
        else{
            a++;
            c--;
        }
        //cout <<"a : " <<a <<"\n";
        //cout <<"b : " <<b <<"\n";
        //cout <<"c : " <<c <<"\n";
        if(flag)
            cout <<"0\n";
        else     
            cout <<abs(a - b) + abs(b - c) + abs(a - c) <<"\n";
    }
    return 0;
}
