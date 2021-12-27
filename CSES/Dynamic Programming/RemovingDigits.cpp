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

vector<int> findDigits(int n) {
	vector<int> ans;
	while (n > 0) {
		ans.push_back(n % 10);
		n /= 10;
	}
	return ans;
}
/**
 * Recursive -> TLE
 * */
int countSteps(int n) {
	if (n < 0) {
		return inf;
	} else if (n == 0) {
		return 0;
	} else {
		int steps = inf;
		vector<int> digits = findDigits(n);
		for (const auto &digit : digits) {
			if (digit > 0) {
				steps = min(steps, 1 + countSteps(n - digit));
			}
		}
		return steps;
	}
}

void solve() {
	int n;
	read(n);
	vector<int> steps(n + 1, inf);
	steps[0] = 0;
	for (int x = 1; x <= n; ++x) {
		vector<int> digits = findDigits(x);
		for (const auto &digit : digits) {
			if (x - digit >= 0) {
				steps[x] = min(steps[x], 1 + steps[x - digit]);
			}
		}
	}
	write(steps.back(), "\n");
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