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
	int N, M, X;
	read(N, M, X);
	vector<int> A(M);
	readContainer(A);
	unordered_set<int> costlyCells(cbegin(A), cend(A));
	min_heap<pair<int, int>> bfsQueue;
	bfsQueue.push(make_pair(0, X));
	unordered_set<int> visited;
	while (!bfsQueue.empty()) {
		auto curr = bfsQueue.top();
		int cost = curr.first;
		int node = curr.second;
		bfsQueue.pop();
		if (node == 0 or node == N) {
			write(cost, "\n");
			break;
		}
		visited.insert(node);
		if (visited.count(node - 1) == 0) {
			int nextCost = (costlyCells.count(node - 1) > 0 ? cost + 1 : cost);
			bfsQueue.push(make_pair(nextCost, node - 1));
		}
		if (visited.count(node + 1) == 0) {
			int nextCost = (costlyCells.count(node + 1) > 0 ? cost + 1 : cost);
			bfsQueue.push(make_pair(nextCost, node + 1));
		}
	}
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}