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

template <class... Args>
auto create(size_t n, Args &&...args) {
    if constexpr (sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, create(args...));
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void solve(int tc) {
    int N;
    read(N);
    vector<int> A(N);
    readContainer(A);
    int ans = INT_MAX;
    vector<int> freq(N + 1, -1);
    for (int j = 0; j < N; j++) {
        if (freq[A[j]] != -1) {
            ans = min(ans, j - freq[A[j]] + 1);
        }
        freq[A[j]] = j;
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    write(ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}