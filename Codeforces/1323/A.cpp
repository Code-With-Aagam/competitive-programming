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
    int t, n;
    cin >>t;
    while(t--){
    	cin >>n;
    	vector<int> arr(n);
    	for(int i = 0; i < n; i++)
    		cin >>arr[i];
    	if(n == 1) {
    		if(arr[0] % 2 == 1){
    			cout <<"-1\n";
    		}
    		else {
    			cout <<"1\n1\n";
    		}
    	}
    	else {
    		bool flag = false;
    		for(int i = 0; i < n; i++){
    			if(arr[i] % 2 == 0){
    				cout <<"1\n" <<i + 1 <<"\n";
    				flag = true;
    				break;
    			}
    		}
    		if(!flag){
    			cout <<"2\n1 2\n";
    		}
    	}
    }
    return 0; 
}
