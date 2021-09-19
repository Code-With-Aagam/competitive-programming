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

void solve() {
    int n;
    read(n);
    vector<string> arr(n);
    readContainer(arr);
    vector<vector<int>> freq(n, vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
        for (const auto &ch : arr[i]) {
            freq[i][ch - 'a']++;
        }
    }
    auto findMaxCount = [&](const char &ch) {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            int cnt = freq[i][ch - 'a'];
            temp.push_back(cnt - ((int)arr[i].size() - cnt));
        }
        sort(begin(temp), end(temp), greater<int>());
        int ans = 0, curr = 0;
        for (const auto &ele : temp) {
            curr += ele;
            if (curr > 0)
                ++ans;
        }
        return ans;
    };
    int ans = 0;
    for (char ch = 'a'; ch <= 'e'; ++ch) {
        ans = max(ans, findMaxCount(ch));
    }
    write(ans, "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    read(T);
    for (int t = 1; t <= T; ++t) {
        solve();
    }
}