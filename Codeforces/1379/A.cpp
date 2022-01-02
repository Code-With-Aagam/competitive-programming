#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

const string t = "abacaba";

bool isCountOne(const string &s) {
	int cnt = 0;
	for (int i = 0; i + t.size() <= s.size(); ++i) {
		if (s.substr(i, t.size()) == t) ++cnt;
	}
	return cnt == 1;
}

void solve() {
	int n;
	string s;
	read(n, s);
	if (isCountOne(s)) {
		for (auto &ch : s) {
			if (ch == '?') ch = 'z';
		}
		write("Yes\n", s, "\n");
		return;
	}
	for (int i = 0; i + t.size() <= n; ++i) {
		string fs = s;
		bool good = true;
		for (int j = 0; j < t.size(); ++j) {
			if (fs[i + j] != '?' and fs[i + j] != t[j]) {
				good = false;
				break;
			}
			fs[i + j] = t[j];
		}
		if (good and isCountOne(fs)) {
			for (auto &ch : fs) {
				if (ch == '?') ch = 'z';
			}
			write("Yes\n", fs, "\n");
			return;
		}
	}
	write("No\n");
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