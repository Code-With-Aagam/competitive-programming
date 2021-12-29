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
 * Number of arrays from [0, index) ending with ele
 *
 * Recursive -> TLE
 * */
int solve(const vector<int> &nums, int index, int ele, int m) {
	if (ele < 1 or ele > m) return 0;
	if (index == 0) return nums[index] == 0 or nums[index] == ele;
	if (nums[index] == 0 or nums[index] == ele) {
		int ans = 0;
		ans += solve(nums, index - 1, ele - 1, m);
		ans %= mod;
		ans += solve(nums, index - 1, ele, m);
		ans %= mod;
		ans += solve(nums, index - 1, ele + 1, m);
		ans %= mod;
		return ans;
	} else {
		return 0;
	}
}

void solve() {
	int n, m;
	read(n, m);
	vector<int> nums(n);
	readContainer(nums);
	vector<vector<int>> arrayCount(n, vector<int>(m + 1, 0));
	if (nums[0] == 0) {
		for (int x = 1; x <= m; ++x) {
			arrayCount[0][x] = 1;
		}
	} else {
		arrayCount[0][nums[0]] = 1;
	}
	for (int index = 1; index < n; ++index) {
		for (int ele = 1; ele <= m; ++ele) {
			if (nums[index] == 0 or nums[index] == ele) {
				arrayCount[index][ele] = 0;
				arrayCount[index][ele] += arrayCount[index - 1][ele - 1];
				arrayCount[index][ele] %= mod;
				arrayCount[index][ele] += arrayCount[index - 1][ele];
				arrayCount[index][ele] %= mod;
				if (ele + 1 <= m) {
					arrayCount[index][ele] += arrayCount[index - 1][ele + 1];
					arrayCount[index][ele] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (const auto &cnt : arrayCount.back()) {
		ans += cnt;
		ans %= mod;
	}
	write(ans);
	// int ans = 0;
	// for (int x = 1; x <= m; ++x) {
	// 	ans += solve(nums, n - 1, x, m);
	// }
	// write(ans);
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