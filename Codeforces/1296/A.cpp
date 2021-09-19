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
    int t, n, ele;
    cin >>t;
    while(t--){
    	cin >>n;
    	int oddSum = 0;
    	int oddCount = 0;
    	for(int i = 0; i < n; i++){
    		cin >>ele;
    		if(ele % 2 == 1){
    			oddSum += ele;
    			oddCount++;
    		}
    	}
    	if(oddSum % 2 == 1 || (oddSum > 0 && oddSum % 2 == 0 && oddCount < n)){
    		cout <<"YES\n";
    	}
    	else{
    		cout <<"NO\n";
    	}
    }
    return 0;
}
