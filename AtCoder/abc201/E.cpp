#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define fr(x,in,n,r) for(ll x=in;x<n;x+=r)
#define ifr(x,n) for(ll x=0;x<n;x++)
#define dfr(x,n) for(ll x=n-1;x>=0;x--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pof(a) pop_front(a)
#define pob(a) pop_back(a)
#define eb(a) emplace_back(a)
#define ef(a) emplace_front(a)
#define fstm(m,n,r) m.reserve(n);m.max_load_factor(r)
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef map<ll, ll> mll;
typedef map<string, ll> msll;
typedef unordered_map<ll, ll> umap;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mod 1000000007
#define N 200005

vector<pll> v[N]; ll a[N];
bool vis[N];

void dfs(ll u) {
	vis[u] = 1;
	ifr(i, v[u].size()) {
		if (!vis[v[u][i].ff]) {
			a[v[u][i].ff] = a[u] ^ v[u][i].ss;
			dfs(v[u][i].ff);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// #ifndef ONLINE_JUDGE
	//  freopen("input.txt", "r", stdin);
	//  freopen("output.txt", "w", stdout);
	// #endif
	ll t = 1;
	// cin >> t;

	while (t--) {
		ll n, x, y, w;
		cin >> n;
		ifr(i, n - 1) {
			cin >> x >> y >> w;
			v[x].pb(pll(y, w));
			v[y].pb(pll(x, w));
		}
		a[1] = 0;
		dfs(1);
		ll ans = 0;
		ifr(i, 60) {
			ll cnt = 0, c = 0, r = 1ll << i;
			fr(j, 1, n + 1, 1) {
				if (r & (a[j]))cnt++;
				else c++;
			}
			ans = (ans + ((r) % mod * (cnt * c) % mod) % mod ) % mod;
		}
		cout << ans << endl;
	}

	return 0;
}