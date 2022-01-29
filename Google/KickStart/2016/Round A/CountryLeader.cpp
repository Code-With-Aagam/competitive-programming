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

int N;

void solve(int tc) {
	int best = 0;
	string line;
	unordered_map<string, int> possibleAnswers;
	while (getline(cin, line)) {
		if (line[0] >= '0' and line[0] <= '9') {
			N = stoi(line);
			break;
		}
		unordered_set<char> st;
		for (const auto &ele : line) {
			if (ele != ' ') {
				st.insert(ele);
			}
		}
		if (not st.empty() and st.size() >= best) {
			best = st.size();
			possibleAnswers[line] = best;
		}
	}
	vector<string> ans;
	for (const auto &ele : possibleAnswers) {
		if (ele.second == best) {
			ans.push_back(ele.first);
		}
	}
	sort(begin(ans), end(ans));
	write("Case #", tc, ": ", ans[0], "\n");
}

signed main() {
	auto start = chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	read(T);
	read(N);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	// write("Time Taken = ", duration.count(), " ms\n");
}