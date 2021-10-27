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

const int N = 1e7 + 1;
bool isprime[N];
int prime[N];

void sieve() {
	memset(isprime, true, sizeof(isprime));
	memset(prime, 0, sizeof(isprime));
	for (int p = 2; p * p <= N; ++p) {
		if (isprime[p]) {
			for (int x = 2 * p; x < N; x += p) {
				isprime[x] = false;
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		if (isprime[i]) {
			prime[i] = 1 + prime[i - 1];
		} else {
			prime[i] = prime[i - 1];
		}
	}
}

void solve(int tc) {
	int X, Y;
	read(X, Y);
	int ans = Y - X - (prime[Y] - prime[X + 1]);
	write(ans, "\n");
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	sieve();
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
// 	write("Time Taken = ", duration.count(), " ms\n");
}