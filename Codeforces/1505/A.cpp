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

// auto speedup = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return nullptr;
// }();

/**
 * Counting Sort  =  O(N)
 */
void countingSort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (const auto &ele : c) {
        cnt[ele]++;
    }
    vector<int> pNew(n), pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (const auto &ele : p) {
        pNew[pos[c[ele]]] = ele;
        pos[c[ele]]++;
    }
    p = pNew;
}

/**
 * Build Suffix Array from the given String
 * Suffix Array: indexes of suffix of given string in lexicographic sorted order.
 * Example: string = "ababba"
 * suffix array  =  [6, 5, 0, 2, 4, 1, 3]
 *
 * Time Complexity: O(N * log(N)) where N = |S|
 */
vector<int> suffixArray(const string &S) {
    string s = S + "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        countingSort(p, c);
        vector<int> cNew(n);
        cNew[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
            pair<int, int> now = make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]);
            if (prev == now) {
                cNew[p[i]] = cNew[p[i - 1]];
            } else {
                cNew[p[i]] = cNew[p[i - 1]] + 1;
            }
        }
        c = cNew;
        k++;
    }
    return p;
}

void solve(int tc) {
    // string s, t;
    // int n;
    // read(s, n);
    // auto suf = suffixArray(s);
    // while (n--) {
    //     read(t);
    //     // int lo = 0, hi = suf.size() - 1, m = t.size();
    //     // bool found = false;
    //     // while (lo <= hi) {
    //     //     int mid = lo + (hi - lo) / 2;
    //     //     string curr = s.substr(suf[mid], m);
    //     //     if (curr == t) {
    //     //         found = true;
    //     //         break;
    //     //     } else if (curr < t) {
    //     //         lo = mid + 1;
    //     //     } else {
    //     //         hi = mid - 1;
    //     //     }
    //     // }
    //     // write((found ? "Yes\n" : "No\n"));
    // }
    string s;
    while (getline(cin, s)) {
        cout << "NO\n";
    }
}

signed main() {
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}