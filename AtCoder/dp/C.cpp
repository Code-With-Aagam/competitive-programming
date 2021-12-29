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
/**
 * Recursion -> TLE
 */
int findMaxPoints(const vector<vector<int>> &points, int index, int activity) {
	if (index == 0) {
		return points[index][activity];
	}
	int ans = points[index][activity];
	if (activity == 0) {
		ans += max(findMaxPoints(points, index - 1, 1), findMaxPoints(points, index - 1, 2));
	} else if (activity == 1) {
		ans += max(findMaxPoints(points, index - 1, 0), findMaxPoints(points, index - 1, 2));
	} else {
		ans += max(findMaxPoints(points, index - 1, 0), findMaxPoints(points, index - 1, 1));
	}
	return ans;
}

void solve() {
	int n;
	read(n);
	vector<vector<int>> points(n, vector<int>(3));
	for (auto &row : points) readContainer(row);
	vector<int> maxPoints = points[0];
	for (int index = 1; index < n; ++index) {
		vector<int> currentPoints = points[index];
		currentPoints[0] += max(maxPoints[1], maxPoints[2]);
		currentPoints[1] += max(maxPoints[0], maxPoints[2]);
		currentPoints[2] += max(maxPoints[0], maxPoints[1]);
		maxPoints = currentPoints;
	}
	write(*max_element(cbegin(maxPoints), cend(maxPoints)));
	// vector<vector<int>> maxPoints(n, vector<int>(3, 0));
	// maxPoints[0] = points[0];
	// for (int index = 1; index < n; ++index) {
	// 	maxPoints[index][0] = points[index][0] + max(maxPoints[index - 1][1], maxPoints[index - 1][2]);
	// 	maxPoints[index][1] = points[index][1] + max(maxPoints[index - 1][0], maxPoints[index - 1][2]);
	// 	maxPoints[index][2] = points[index][2] + max(maxPoints[index - 1][0], maxPoints[index - 1][1]);
	// }
	// write(*max_element(cbegin(maxPoints.back()), cend(maxPoints.back())));
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