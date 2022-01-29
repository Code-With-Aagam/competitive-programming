#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007LL;
const long double pi = acos(-1);

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

void solve(int tc) {
	int R, C, ans = 0;
	read(R, C);
	vector<vector<int>> H(R, vector<int>(C));
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	for (auto &row : H) {
		readContainer(row);
	}
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	for (int i = 0; i < R; ++i) {
		pq.push({H[i][0], i, 0});
		pq.push({H[i][C - 1], i, C - 1});
		visited[i][0] = true;
		visited[i][C - 1] = true;
	}
	for (int j = 1; j < C - 1; ++j) {
		pq.push({H[0][j], 0, j});
		pq.push({H[R - 1][j], R - 1, j});
		visited[0][j] = true;
		visited[R - 1][j] = true;
	}
	while (not pq.empty()) {
		auto curr = pq.top();
		pq.pop();
		for (int k = 0; k < 4; ++k) {
			int ni = curr[1] + dx[k];
			int nj = curr[2] + dy[k];
			if (ni < 0 or nj < 0 or ni >= R or nj >= C or visited[ni][nj]) continue;
			ans += max(0LL, curr[0] - H[ni][nj]);
			pq.push({max(curr[0], H[ni][nj]), ni, nj});
			visited[ni][nj] = true;
		}
	}
	write("Case #", tc, ": ", ans, "\n");
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}