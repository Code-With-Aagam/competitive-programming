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
    int n, ele;
    read(n);
    max_heap<pair<int, int>> heap;
    for (int i = 1; i <= n; ++i) {
        read(ele);
        if (ele > 0)
        heap.push(make_pair(ele, i));
    }
    vector<pair<int, int>> ans;
    while (heap.size() > 1) {
        auto first = heap.top();
        heap.pop();
        auto second = heap.top();
        heap.pop();
        ans.push_back(make_pair(first.second, second.second));
        first.first--;
        second.first--;
        if (first.first > 0) heap.push(first);
        if (second.first > 0) heap.push(second);
    }
    write(ans.size(), "\n");
    for (const auto &ele : ans) {
        write(ele.first, " ", ele.second, "\n");
    }
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