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
	string s, a, ans = "";
	read(a, s);
	if (s == a) {
		write("0\n");
		return;
	}
	int n = s.size(), m = a.size(), i = n - 1, j = m - 1;
	while (i >= 0 and j >= 0) {
		int sd = s[i] - '0', ad = a[j] - '0';
		if (sd - ad >= 0) {
			ans += to_string(sd - ad);
			--i;
			--j;
		} else {
			if (i - 1 >= 0) {
				int snum = stoi(s.substr(i - 1, 2));
				if (snum - ad >= 0 and snum - ad <= 9) {
					ans += to_string(snum - ad);
					i -= 2;
					--j;
				} else {
					write("-1\n");
					return;
				}
			} else {
				write("-1\n");
				return;
			}
		}
	}
	if (j >= 0) {
		write("-1\n");
		return;
	}
	while (i >= 0) {
		ans += s[i];
		--i;
	}
	while (!ans.empty() and ans.back() == '0') ans.pop_back();
	reverse(begin(ans), end(ans));
	write(ans, "\n");
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