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
    vector<vector<char>> arr(n, vector<char>(n));
    for (auto &row : arr) {
        readContainer(row);
    }
    int cnt = 0;
    pair<int, int> pa, pb;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == '*' && cnt == 0) {
                pa.first = i;
                pa.second = j;
                cnt += 1;
            } else if (arr[i][j] == '*') {
                pb.first = i;
                pb.second = j;
            }
        }
    }
    if (pa.first == pb.first) {
        int nx = 0;
        if (pa.first > 0) {
            nx = pa.first - 1;
        } else {
            nx = pa.first + 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == '*') {
                    write("*");
                } else if (i == nx && (j == pa.second || j == pb.second)) {
                    write("*");
                } else {
                    write(".");
                }
            }
            write("\n");
        }
        return;
    }
    if (pa.second == pb.second) {
        int ny = 0;
        if (pa.second > 0) {
            ny = pa.second - 1;
        } else {
            ny = pa.second + 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == '*') {
                    write("*");
                } else if (j == ny && (pa.first == i || pb.first == i)) {
                    write("*");
                } else {
                    write(".");
                }
            }
            write("\n");
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // deb(i);
            // deb(j);
            // cout << pa.first << ", " << pa.second << "\n";
            // cout << pb.first << ", " << pb.second << "\n";
            // // deb(pa.first == i && pb.second == j);

            if (arr[i][j] == '*') {
                write("*");
            } else if ((pa.first == i && pb.second == j) || (pb.first == i && pa.second == j)) {
                write("*");
            } else {
                write(".");
            }
        }
        write("\n");
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}