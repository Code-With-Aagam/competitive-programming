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
int findMaximumValue(
    const vector<pair<int, int>> &items,
    int index,
    int currWeight,
    int maxWeight
) {
	if (index == items.size()) return 0;
	int including = 0;
	if (currWeight + items[index].first <= maxWeight) {
		including = items[index].second + findMaximumValue(
		                items,
		                index + 1,
		                currWeight +
		                items[index].first,
		                maxWeight
		            );
	}
	int excluding = findMaximumValue(
	                    items,
	                    index + 1,
	                    currWeight,
	                    maxWeight
	                );
	return max(including, excluding);
}

void solve() {
	int n, W;
	read(n, W);
	vector<pair<int, int>> items(n);
	for (auto &item : items) {
		read(item.first, item.second);
	}
	vector<vector<int>> maxValue(n + 1, vector<int>(W + 1));
	for (int index = 1; index <= n; ++index) {
		for (int w = 0; w <= W; ++w) {
			maxValue[index][w] = maxValue[index - 1][w];
			if (w - items[index - 1].first >= 0) {
				maxValue[index][w] = max(maxValue[index][w], items[index - 1].second + maxValue[index - 1][w - items[index - 1].first]);
			}
		}
	}
	write(*max_element(cbegin(maxValue.back()), cend(maxValue.back())));
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