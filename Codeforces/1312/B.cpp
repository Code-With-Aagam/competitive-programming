/**
 *	Author    :    Sanjeev Sharma                   
 *	Email     :    thedevelopersanjeev@gmail.com  
**/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define deb(x) cout << #x << " is " << x << "\n";
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >>t;
    while(t--) {
    	cin >>n;
    	vector<int> arr(n);
    	for(int i = 0; i < n; i++)
    		cin >>arr[i];
    	sort(arr.begin(), arr.end());
    	reverse(arr.begin(), arr.end());
    	for(auto ele : arr)
    		cout <<ele <<" ";
    	cout <<"\n";
    }
    return 0; 
}
