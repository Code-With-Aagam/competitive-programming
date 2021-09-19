/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
vector<vector<int>> nCr(1001, vector<int>(1001));
vector<int> pw(1001);

void preprocessing(int n) {
	for(int i = 0; i <= n; i++)	{
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i) {
				nCr[i][j] = 1;
			}
			else {
				nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % mod;
			}
		}
	}
	pw[0] = 1;
	pw[1] = 1;
	for(int i = 2; i <= n; i++) {
		pw[i] = (pw[i-1] * 2) % mod;
	}
}

int solve(int n, vector<int> &vis){
	int m = vis.size();
	preprocessing(n);
	sort(vis.begin(), vis.end());
	long long temp;
	long long ans = 1;
	long long cnt = 0;
	for(int i = 0; i < m; i++) {
		if(i == 0) {
			temp = vis[i] - 1;
		}
		else {
			temp = vis[i] - vis[i-1] - 1;
			ans = (ans * pw[temp]) % mod;
		}
		cnt += temp;
		ans = (ans * nCr[cnt][temp]) % mod;
	}
	cnt += (n - vis[m-1]);
	ans = (ans * nCr[cnt][n - vis[m-1]]) % mod;
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >>n >>m;
	vector<int> arr(m);
	for(int i = 0; i < m; i++)
		cin >>arr[i];
	cout <<solve(n, arr);
	return 0;
}
