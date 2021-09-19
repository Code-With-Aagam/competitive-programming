/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
 
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, n, s;
    cin >>t;
    while(t--){
    	cin >>a >>b >>n >>s;
    	int temp = s / n;
    	if(temp <= a)
    		s -= n*temp;
    	else
    		s -= n*a;
    	if(s <= b)
    		cout <<"YES\n";
    	else 
    		cout <<"NO\n";
    }
    return 0;
}
