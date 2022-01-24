#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define deb(x) cout << #x << " is " << x << "\n"
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int infinity = 1e18;
constexpr long double epsilon = 1e-9;

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

class TrieNode {
	TrieNode* children[26] = { nullptr };
	bool lastCharacter = false;

	int getIndex(const char &ch) {
		return ch - 'a';
	}
public:
	bool containsKey(const char &ch) {
		int index = getIndex(ch);
		return children[index] != nullptr;
	}

	TrieNode* getNextNode(const char &ch) {
		int index = getIndex(ch);
		return children[index];
	}

	void createNode(const char &ch) {
		int index = getIndex(ch);
		children[index] = new TrieNode();
	}

	void markLastCharacter() {
		lastCharacter = true;
	}

	bool isLastCharacter() {
		return lastCharacter;
	}
};

class SearchEngine {
	TrieNode* root = new TrieNode();
public:
	void add(string word) {
		TrieNode* node = root;
		for (const auto &ch : word) {
			if (not node -> containsKey(ch)) {
				node -> createNode(ch);
			}
			node = node -> getNextNode(ch);
		}
		node -> markLastCharacter();
	}

	bool exists(string word) {
		TrieNode* node = root;
		for (const auto &ch : word) {
			if (ch != '.') {
				if (not node -> containsKey(ch)) {
					return false;
				}
				node = node -> getNextNode(ch);
			} else {
				queue<TrieNode*> q;
				for (char w = 'a'; w <= 'z'; ++w) {
					if (node -> containsKey(w)) {
						q.push(node -> getNextNode(w));
					}
				}

			}
		}
		return node -> isLastCharacter();
	}
};

void solve() {

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// read(T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
}