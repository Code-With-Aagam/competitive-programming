#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &visited, int u, stack<int> &st) {
	visited[u] = true;
	for (const auto &v : adj[u]) {
		if (not visited[v]) {
			dfs(adj, visited, v, st);
		}
	}
	st.push(u);
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n + 1];
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
    for (int i = 1; i <= n; ++i) sort(begin(adj[i]), end(adj[i]), greater<int>());
	vector<bool> visited(n + 1, false);
	stack<int> st;
	for (int i = n; i >= 1; --i) {
        if (not visited[i]) {
            dfs(adj, visited, i, st);
        }
    }
	while (not st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}