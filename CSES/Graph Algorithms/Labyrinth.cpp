#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int infinity = 1e18;
constexpr long double epsilon = 1e-9;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
	((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
	for (auto &e : t) {
		read(e);
	}
}

template <typename T>
void writeContainer(T &t) {
	for (const auto &e : t) {
		write(e, " ");
	}
	write("\n");
}

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void solve() {
	int n, m;
	read(n, m);
	vector<vector<char>> labyrinth(n, vector<char>(m));
	for (auto &row : labyrinth) readContainer(row);
	int si = 0, sj = 0, fi = 0, fj = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (labyrinth[i][j] == 'A') {
				si = i;
				sj = j;
			} else if (labyrinth[i][j] == 'B') {
				fi = i;
				fj = j;
			}
		}
	}
	vector<vector<int>> dist(n, vector<int>(m, infinity));
	queue<pair<int, int>> q;
	q.push(make_pair(si, sj));
	dist[si][sj] = 0;
	while (not q.empty()) {
		si = q.front().first;
		sj = q.front().second;
		q.pop();
		if (labyrinth[si][sj] == 'B') break;
		labyrinth[si][sj] = '#';
		for (int k = 0; k < 4; ++k) {
			int ni = si + dx[k];
			int nj = sj + dy[k];
			if (ni >= 0 and ni < n and nj >= 0 and nj < m and labyrinth[ni][nj] != '#') {
				q.push(make_pair(ni, nj));
				dist[ni][nj] = 1 + dist[si][sj];
			}
		}
	}
	if (dist[fi][fj] == infinity) {
		write("NO\n");
	} else {
		string ans = "";
		while (dist[fi][fj] > 0) {
			if (fi - 1 >= 0 and dist[fi - 1][fj] + 1 == dist[fi][fj]) {
				ans += "D";
				--fi;
			} else if (fi + 1 < n and dist[fi + 1][fj] + 1 == dist[fi][fj]) {
				ans += "U";
				++fi;
			} else if (fj - 1 >= 0 and dist[fi][fj - 1] + 1 == dist[fi][fj]) {
				ans += "R";
				--fj;
			} else {
				ans += "L";
				++fj;
			}
		}
		reverse(all(ans));
		write("YES\n", ans.size(), "\n", ans);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
}