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
	vector<int> b(7);
	readContainer(b);
	auto good = [&](vector<int> &arr) {
		vector<int> bdash;
		for (int mask = 1; mask < (1 << 3); ++mask) {
			int curr = 0;
			for (int i = 0; i < 3; ++i) {
				if (mask & (1 << i)) {
					curr += arr[i];
				}
			}
			bdash.push_back(curr);
		}
		sort(begin(bdash), end(bdash));
		return b == bdash;
	};
	for (int mask = 0; mask < (1 << 7); ++mask) {
		vector<int> curr;
		for (int i = 0; i < 7; ++i) {
			if (mask & (1 << i)) {
				curr.push_back(b[i]);
			}
		}
		if (curr.size() == 3) {
			bool found = false;
			sort(begin(curr), end(curr));
			do {
				if (good(curr)) {
					found = true;
					break;
				}
			} while (next_permutation(begin(curr), end(curr)));
			if (found) {
				writeContainer(curr);
				break;
			}
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