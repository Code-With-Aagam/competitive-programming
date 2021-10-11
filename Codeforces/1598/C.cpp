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
    int S = accumulate(cbegin(A), cend(A), 0LL);
    int target = 2 * S;
    if (target % N != 0) {
        write("0\n");
        return;
    }
    target /= N;
    map<int, int> mp;
    int ans = 0;
    for (const auto &ele : A) {
        ans += mp[target - ele];
        mp[ele]++;
    }
    write(ans, "\n");
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