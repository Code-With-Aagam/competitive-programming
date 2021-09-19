/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

long long findX(long long n){
	if(n <= 10)
		return n;
	long long mod = n % 10;
	return n - mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, n;
    cin >>t;
    while(t--){
    	cin >>n;
    	long long ans = 0;
    	while(n > 0){
    		long long x = findX(n);
    		n -= x;
    		ans += x;
    		n += floor(x/10);
    		
    	}
    	cout <<ans <<"\n";
    }
    return 0;
}
