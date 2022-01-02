#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int inf = 9e18;
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

void solve() {
	int n, q, xi, ki;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	read(q);
	vector<vector<int>> allArrays;
	allArrays.push_back(arr);
	while (true) {
		auto prevArray = allArrays.back();
		vector<int> currArray;
		map<int, int> freq;
		for (const auto &ele : prevArray) freq[ele]++;
		for (const auto &ele : prevArray) currArray.push_back(freq[ele]);
		if (prevArray == currArray) break;
		allArrays.push_back(currArray);
	}
	while (q--) {
		read(xi, ki);
		if (ki < allArrays.size()) {
			write(allArrays[ki][xi - 1], "\n");
		} else {
			write(allArrays.back()[xi - 1], "\n");
		}
	}
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}