#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr)
        cin >> ele;
    sort(arr.begin(), arr.end());
    for (const auto &ele : arr)
        cout << ele << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
