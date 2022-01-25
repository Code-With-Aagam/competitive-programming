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
    vector<int> A(N);
    readContainer(A);
    int S = accumulate(A.begin(), A.end(), 0LL);
    if (S % 2 == 0) {
        write(N, "\n");
        for (int i = 1; i <= N; ++i) {
            write(i, " ");
        }
        write("\n");
    } else {
        bool found = false;
        for (int x = 3; x < S; x += 2) {
            if (S % x == 0) {
                write(N, "\n");
                for (int i = 1; i <= N; ++i) {
                    write(i, " ");
                }
                write("\n");
                found = true;
                break;
            }
        }
        if (!found) {
            int removed = 0;
            for (int i = 0; i < N; ++i) {
                if (A[i] % 2 == 1) {
                    removed = i;
                    break;
                }
            }
            write(N - 1, "\n");
            for (int i = 1; i <= N; ++i) {
                if (i - 1 != removed) {
                    write(i, " ");
                }
            }
            write("\n");
        }
    }
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
	chrono::duration<double, milli> duration = end - start;
    // write("Time Taken = ", duration.count(), " ms\n");
}