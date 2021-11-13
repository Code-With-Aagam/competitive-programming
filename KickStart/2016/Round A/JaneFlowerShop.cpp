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
	int M;
	read(M);
	vector<int> A(M + 1);
	readContainer(A);
	long double lo = -1, hi = 1, ans = 0;
	for (int ops = 0; ops < 100; ++ops) {
		long double r = lo + (hi - lo) / 2;
		long double crr = 1;
		for (int x = 0; x < M; ++x) {
			crr *= (1 + r);
		}
		long double cost = crr * -1 * A[0];
		for (int i = 1; i <= M; ++i) {
			crr /= ((1 + r) != 0 ? (1 + r) : 1);
			cost += A[i] * crr;
		}
		if (cost >= 0) {
			ans = r;
			lo = r + 1;
		} else {
			hi = r - 1;
		}
	}
	write(fixed, setprecision(8), "Case #", tc, ": ", ans, "\n");
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