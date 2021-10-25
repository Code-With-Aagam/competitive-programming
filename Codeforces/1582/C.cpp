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

int check(const string &S, int i, int j, const char &ch) {
    int rem = 0;
    while (i < j) {
        if (S[i] == S[j]) {
            i++;
            j--;
        } else if (S[i] == ch) {
            i++;
            rem++;
        } else if (S[j] == ch) {
            j--;
            rem++;
        } else {
            return -1;
        }
    }
    return rem;
}

void solve(int tc) {
    int N;
    read(N);
    string S;
    read(S);
    int i = 0, j = N - 1;
    while (i < j) {
        if (S[i] == S[j]) {
            i++;
            j--;
        } else {
            break;
        }
    }
    if (i == j) {
        write("0\n");
        return;
    }
    int X = check(S, 0, N - 1, S[i]);
    int Y = check(S, 0, N - 1, S[j]);
    if (X == -1 && Y == -1) {
        write("-1\n");
        return;
    }
    if (X == -1) X = 1e18;
    if (Y == -1) Y = 1e18;
    write(min(X, Y), "\n");
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