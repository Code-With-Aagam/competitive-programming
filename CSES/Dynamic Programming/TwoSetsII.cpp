#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18;
constexpr long double eps = 1e-9;

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
 */
int findNumberOfSubsets(const vector<int> &arr, int index, int sum) {
	if (sum < 0) return 0;
	if (index == arr.size()) return sum == 0;
	int including = findNumberOfSubsets(arr, index + 1, sum - arr[index]);
	int excluding = findNumberOfSubsets(arr, index + 1, sum);
	return including + excluding;
}

int binpow(int x, int y) {
	x %= mod;
	int res = 1;
	while (y > 0) {
		if (y & 1) res = res * x;
		res %= mod;
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return res;
}

void solve() {
	int n;
	read(n);
	int S = (n * (n + 1)) / 2;
	if (S % 2 == 1) {
		write(0);
		return;
	}
	S /= 2;
	vector<vector<int>> countOfSubsets(n + 1, vector<int>(S + 1, 0));
	for (int i = 0; i < n; ++i) countOfSubsets[i][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int s = 0; s <= S; ++s) {
			countOfSubsets[i][s] = countOfSubsets[i - 1][s];
			if (s - i >= 0) {
				countOfSubsets[i][s] += countOfSubsets[i - 1][s - i];
				countOfSubsets[i][s] %= mod;
			}
		}
	}
	int ans = countOfSubsets.back().back();
	ans *= binpow(2, mod - 2);
	ans %= mod;
	write(ans);
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