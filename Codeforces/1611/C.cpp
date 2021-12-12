#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

const int mod = 1000000007LL;
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

void solve(int tc) {
	int n;
	read(n);
	vector<int> arr(n);
	readContainer(arr);
	if (n <= 2) {
		writeContainer(arr);
	} else {
		if (arr[0] == n or arr[n - 1] == n) {
			int lo, hi;
			deque<int> ans;
			ans.push_back(n);
			if (arr[0] == n) {
				lo = 1;
				hi = n - 1;
			} else {
				lo = 0;
				hi = n - 2;
			}
			while (lo <= hi) {
				if (arr[lo] < arr[hi]) {
					ans.push_front(arr[lo]);
					++lo;
				} else {
					ans.push_back(arr[hi]);
					--hi;
				}
			}
			writeContainer(ans);
		} else {
			write("-1\n");
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
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}