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
    int H, W;
    read(H, W);
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &row : A) readContainer(row);
    bool good = true;
    for (int i1 = 0; i1 < H; ++i1) {
        for (int j1 = 0; j1 < W; ++j1) {
            for (int i2 = i1 + 1; i2 < H; ++i2) {
                for (int j2 = j1 + 1; j2 < W; ++j2) {
                    if (A[i1][j1] + A[i2][j2] > A[i1][j2] + A[i2][j1]) {
                        good = false;
                        break;
                    }
                }
            }
        }
    }
    write((good ? "Yes" : "No"));
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