#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007;
const int inf = 1e18;
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

/**
 * Recursive -> TLE
 *
 * Minimum Operations required to
 * convert a -> b of size n and m respectively.
 */
int editDistance(const string &a, const string &b, int n, int m) {
	if (n == 0) return m;
	else if (m == 0) return n;
	if (a[n - 1] == b[m - 1]) {
		return editDistance(a, b, n - 1, m - 1);
	} else {
		return 1 + min({
			editDistance(a, b, n - 1, m),	// Remove
			editDistance(a, b, n, m - 1),	// Insert
			editDistance(a, b, n - 1, m - 1)// Replace
		});
	}
}

void solve() {
	string a, b;
	read(a, b);
	int n = a.size(), m = b.size();
	vector<vector<int>> editDistance(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) editDistance[i][0] = i;
	for (int j = 1; j <= m; ++j) editDistance[0][j] = j;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1]) {
				editDistance[i][j] = editDistance[i - 1][j - 1];
			} else {
				editDistance[i][j] = 1 + min({
                    editDistance[i - 1][j], 
                    editDistance[i][j - 1], 
                    editDistance[i - 1][j - 1]
                });
			}
		}
	}
	write(editDistance[n][m]);
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}