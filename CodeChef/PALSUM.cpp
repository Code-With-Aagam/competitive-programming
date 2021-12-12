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

vector<int> goodNumbers;

bool isGoodNumber(int n) {
	string s = "";
	while (n > 0) {
		s += to_string(n % 2);
		n /= 2;
	}
	string t = s;
	reverse(begin(t), end(t));
	return s == t;
}

void generateGoodNumbers() {
	for (int i = 1; i <= 1000; ++i) {
		if (isGoodNumber(i)) {
			goodNumbers.push_back(i);
		}
	}
}

void solve(int tc) {
	int n;
	read(n);
	vector<int> ans;
	for (const auto &ele : goodNumbers) {
		if (n == 0) break;
		while (n >= ele) {
			ans.push_back(ele);
			n -= ele;
		}
	}
	write(ans.size(), "\n");
	writeContainer(ans);
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	generateGoodNumbers();
	reverse(begin(goodNumbers), end(goodNumbers));
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}