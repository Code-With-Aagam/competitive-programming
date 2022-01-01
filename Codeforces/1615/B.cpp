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

constexpr int N = 2e5 + 5;
constexpr int bits = 30;
vector<vector<int>> zerosCount(bits, vector<int>(N + 1, 0LL));

void solve(int tc) {
	int L, R;
	read(L, R);
	int ans = R - L + 1;
	for (int currBit = 0; currBit < bits; ++currBit) {
		int curr = zerosCount[currBit][R + 1] - zerosCount[currBit][L];
		ans = min(ans, curr);
	}
	write(ans, "\n");
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int currBit = 0; currBit < bits; ++currBit) {
		for (int num = 0; num < N; ++num) {
			zerosCount[currBit][num + 1] = zerosCount[currBit][num] + ((num & (1LL << currBit)) ? 0 : 1);
		}
	}
	int T = 1;
	read(T);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}