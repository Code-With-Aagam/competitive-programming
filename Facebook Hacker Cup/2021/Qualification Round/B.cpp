#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

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
    int n;
    read(n);
    vector<vector<char>> board(n, vector<char>(n));
    int minRequired = LLONG_MAX;
    for (int i = 0; i < n; ++i) readContainer(board[i]);
    for (int i = 0; i < n; ++i) {
        int zeros = 0, ones = 0, dots = 0;
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O')
                zeros++;
            else if (board[i][j] == 'X')
                ones++;
            else if (board[i][j] == '.')
                dots++;
        }
        if (zeros == 0) minRequired = min(minRequired, dots);
    }
    for (int j = 0; j < n; ++j) {
        int zeros = 0, ones = 0, dots = 0;
        for (int i = 0; i < n; ++i) {
            if (board[i][j] == 'O')
                zeros++;
            else if (board[i][j] == 'X')
                ones++;
            else if (board[i][j] == '.')
                dots++;
        }
        if (zeros == 0) minRequired = min(minRequired, dots);
    }
    if (minRequired == LLONG_MAX) {
        write("Case #", tc, ": ", "Impossible", "\n");
        return;
    }
    // int numberOfWays = 0;
    set<vector<pair<int, int>>> numberOfWays;
    for (int i = 0; i < n; ++i) {
        int zeros = 0, ones = 0, dots = 0;
        vector<pair<int, int>> ways;
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O')
                zeros++;
            else if (board[i][j] == 'X')
                ones++;
            else if (board[i][j] == '.') {
                dots++;
                ways.push_back(make_pair(i, j));
            }
        }
        if (zeros == 0 && dots == minRequired) {
            numberOfWays.insert(ways);
        }
    }
    for (int j = 0; j < n; ++j) {
        int zeros = 0, ones = 0, dots = 0;
        vector<pair<int, int>> ways;
        for (int i = 0; i < n; ++i) {
            if (board[i][j] == 'O')
                zeros++;
            else if (board[i][j] == 'X')
                ones++;
            else if (board[i][j] == '.') {
                dots++;
                ways.push_back(make_pair(i, j));
            }
        }
        if (zeros == 0 && dots == minRequired) {
            numberOfWays.insert(ways);
        }
    }
    write("Case #", tc, ": ", minRequired, " ", numberOfWays.size(), "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    read(T);
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }
}