#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
// #define int long long

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
int findMaximumPages(const vector<int> &prices, const vector<int> &pages, int index, int maximumPrice) {
	if (index == prices.size()) {
		return 0;
	}
	int including = 0;
	if (maximumPrice - prices[index] >= 0) {
		including = pages[index] + findMaximumPages(prices, pages, index + 1, maximumPrice - prices[index]);
	}
	int excluding = findMaximumPages(prices, pages, index + 1, maximumPrice);
	return max(including, excluding);
}

void solve() {
	int n, maximumPrice;
	read(n, maximumPrice);
	vector<int> prices(n), pages(n);
	readContainer(prices);
	readContainer(pages);
	vector<vector<int>> maximumPages(n + 1, vector<int>(maximumPrice + 1, 0));
	for (int index = 1; index <= n; ++index) {
		for (int price = 0; price <= maximumPrice; ++price) {
			int including = 0;
			if (price - prices[index - 1] >= 0) {
				including = pages[index - 1] + maximumPages[index - 1][price - prices[index - 1]];
			}
			int excluding = maximumPages[index - 1][price];
			maximumPages[index][price] = max(including, excluding);
		}
	}
	write(maximumPages.back().back(), "\n");
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