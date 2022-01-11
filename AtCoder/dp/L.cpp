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

// (1 / x) % mod = binpow(x, mod - 2)
int binpow(int x, int y, int mod = mod) {
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
/**
 * Recursive -> TLE
 * */
pair<int, int> findGameScore(const vector<int> &arr, int i, int j, bool flag) {
	if (i > j) {
		return make_pair(0, 0);
	}
	if (flag) {
		// first player will pick
		auto nextScoreOne = findGameScore(arr, i + 1, j, !flag);
		auto nextScoreTwo = findGameScore(arr, i, j - 1, !flag);
		if (nextScoreOne.first + arr[i] > nextScoreTwo.first + arr[j]) {
			nextScoreOne.first += arr[i];
			return nextScoreOne;
		} else {
			nextScoreTwo.first += arr[j];
			return nextScoreTwo;
		}
	} else {
		// second player will pick
		auto nextScoreOne = findGameScore(arr, i + 1, j, !flag);
		auto nextScoreTwo = findGameScore(arr, i, j - 1, !flag);
		if (nextScoreOne.second + arr[i] > nextScoreTwo.second + arr[j]) {
			nextScoreOne.second += arr[i];
			return nextScoreOne;
		} else {
			nextScoreTwo.second += arr[j];
			return nextScoreTwo;
		}
	}
}

int score[3001][3001][2];

void solve() {
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	for (int i = 0; i < n; ++i) {
		score[i][i][0] = arr[i];
		score[i][i][1] = 0;
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len - 1;
			score[i][j][0] = max(arr[i] + score[i + 1][j][1], arr[j] + score[i][j - 1][1]);
			score[i][j][1] = min(score[i + 1][j][0], score[i][j - 1][0]);
		}
	}
	int totalScore = accumulate(all(arr), 0LL);
	int xScore = score[0][n - 1][0];
	write(2 * xScore - totalScore, "\n");
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