/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
 
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout <<#x <<" " <<x <<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double h, l;
    cin >>h >>l;
    double ans = (((l*l) - (h*h)) / (2*h));
    cout <<fixed <<setprecision(13) <<ans <<"\n";
    return 0;
}
