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

int f(const vector<int> &vowels, const vector<int> &consonants) {
    int ans = 0, cnt = 0;
    for (int i = 0; i < (int)vowels.size() - 1; ++i) {
        cnt += vowels[i];
    }
    ans = cnt * 2;
    ans += accumulate(cbegin(consonants), cend(consonants), 0LL);
    return ans;
}

void solve(int tc) {
    string s;
    read(s);
    map<char, int> freq;
    for (const auto &ch : s) {
        freq[ch]++;
    }
    vector<int> vowels, consonants;
    string vowels_str = "AEIOU";
    string consonants_str = "BCDFGHJKLMNPQRSTVWXYZ";
    for (const auto &ch : vowels_str) {
        if (freq[ch] > 0)
            vowels.push_back(freq[ch]);
    }
    for (const auto &ch : consonants_str) {
        if (freq[ch] > 0)
            consonants.push_back(freq[ch]);
    }
    int n = vowels.size(), m = consonants.size();
    if ((n == 0 && m == 1) || (n == 1 && m == 0)) {
        write("Case #", tc, ": ", 0, "\n");
        return;
    }
    sort(begin(vowels), end(vowels));
    sort(begin(consonants), end(consonants));
    write("Case #", tc, ": ", min(f(vowels, consonants), f(consonants, vowels)), "\n");
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