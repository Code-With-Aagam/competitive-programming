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
    int x = 0;
    int y = 0;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            int ele;
            cin >>ele;
            if(ele == 1){
                x = i;
                y = j;
            }
        }
    }
    cout <<abs(3-x) + abs(3-y);
    return 0;
}