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

set<int> possibleSums;
/**
 * Recursive -> TLE
 * */
void generatePossibleSums(const vector<int> &coins, int index, int currSum) {
	if (index == coins.size()) {
		if (currSum > 0)
			possibleSums.insert(currSum);
		return;
	}
	generatePossibleSums(coins, index + 1, currSum);
	generatePossibleSums(coins, index + 1, currSum + coins[index]);
}

void solve() {
	int n;
	read(n);
	vector<int> coins(n);
	readContainer(coins);
	int maxSum = accumulate(all(coins), 0LL);
	vector<bool> possible(maxSum + 1, false);
	possible[0] = true;
	for (int i = 0; i < n; ++i) {
		for (int sum = maxSum; sum >= coins[i]; --sum) {
			possible[sum] = possible[sum] or possible[sum - coins[i]];
		}
	}
	vector<int> ans;
	for (int sum = 1; sum <= maxSum; ++sum) {
		if (possible[sum]) ans.push_back(sum);
	}
	write(ans.size(), "\n");
	writeContainer(ans);
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