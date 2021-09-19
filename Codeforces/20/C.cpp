#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define inf 0x7fffffff
#define maxx 100009
priority_queue<pii, vector<pii>, greater<pii> >q;
vector<pii>G[maxx];
int d[maxx];
bool f[maxx];
int prevv[maxx];
int n, m;
void printpath(int src)
{
	if (prevv[src] != -1)
		printpath(prevv[src]);
	cout << src << " ";
}
void dijktras(int src)
{
	for (int i = 0; i <= n; i++)
	{
		d[i] = inf;
		f[i] = false;
		prevv[i] = -1;
	}
	d[src] = 0;
	q.push(pii(0, src));
	while (!q.empty())
	{
		int s = q.top().second;
		q.pop();
		for (int i = 0; i < G[s].size(); i++)
		{
			int v = G[s][i].second;
			int w = G[s][i].first;
			if (!f[v] && d[s] + w < d[v])
			{
				d[v] = d[s] + w;
				q.push(pii(d[v], v));
				prevv[v] = s;
			}
		}
		f[s] = true;
	}
}
int main() {
	// your code goes here
	memset(prevv, -1, sizeof prevv);
	cin >> n >> m;
	while (m--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		G[a].pb(pii(w, b));
		G[b].pb(pii(w, a));
	}
	dijktras(1);
	if (d[n] == inf)
	{
		cout << "-1" << endl;
	}
	else
		printpath(n);
	return 0;
}