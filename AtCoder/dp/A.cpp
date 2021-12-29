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
 * */
int findMinCost(const vector<int> &heights, int currentIndex) {
	if (currentIndex >= heights.size() - 1) return 0;
	int jumpOneCost = inf, jumpTwoCost = inf;
	if (currentIndex + 1 < heights.size()) {
		jumpOneCost = abs(heights[currentIndex] - heights[currentIndex + 1]) + findMinCost(heights, currentIndex + 1);
	}
	if (currentIndex + 2 < heights.size()) {
		jumpTwoCost = abs(heights[currentIndex] - heights[currentIndex + 2]) + findMinCost(heights, currentIndex + 2);
	}
	return min(jumpOneCost, jumpTwoCost);
}

void solve() {
	int N;
	read(N);
	vector<int> H(N);
	readContainer(H);
	int previousToPreviousJumpCost = 0;
	int previousJumpCost = abs(H[1] - H[0]);
	for (int index = 2; index < N; ++index) {
		int jumpOneCost = abs(H[index] - H[index - 1]) + previousJumpCost;
		int jumpTwoCost = abs(H[index] - H[index - 2]) + previousToPreviousJumpCost;
		previousToPreviousJumpCost = previousJumpCost;
		previousJumpCost = min(jumpOneCost, jumpTwoCost);
	}
	write(previousJumpCost);
	// vector<int> minCost(N, inf);
	// minCost[0] = 0;
	// minCost[1] = abs(H[1] - H[0]);
	// for (int index = 2; index < N; ++index) {
	// 	int jumpOneCost = abs(H[index] - H[index - 1]) + minCost[index - 1];
	// 	int jumpTwoCost = abs(H[index] - H[index - 2]) + minCost[index - 2];
	// 	minCost[index] = min(jumpOneCost, jumpTwoCost);
	// }
	// write(minCost.back());
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