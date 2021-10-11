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
    int N;
    read(N);
    vector<string> board(2);
    read(board[0]);
    read(board[1]);
    bool canReach = true;
    int i = 0, j = 0;
    while (i < N - 1) {
        if (board[0][i + 1] == '0') j = 0;
        else if (board[1][i + 1] == '0') j = 1;
        else {
            canReach = false;
            break;
        }
        ++i;
    }
    write((canReach ? "YES\n" : "NO\n"));
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
	chrono::duration<double, std::milli> duration = end - start;
	// cout << "Time Taken = " << duration.count() << " ms" << "\n";
}