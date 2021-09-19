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
    long long t, n, m;
    cin >>t;
    while(t--){
    	cin >>n >>m;
    	vector<long long> arr(n);
    	for(long long i = 0; i < n; i++)
    		cin >>arr[i];
    	if(n == 1){
    		cout <<arr[0] <<"\n";
    		continue;
    	}
    	long long inc = m - arr[0];
    	long long extra = accumulate(arr.begin(), arr.end(), 0L);
    	extra -= arr[0];
    	if(extra >= inc){
    		cout <<m <<"\n";
    	}
    	else {
    		cout <<extra + arr[0] <<"\n";
    	}
    }
    return 0; 
}
