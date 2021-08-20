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
    const vector<int> dx = {0, 0, 1, -1};
    const vector<int> dy = {1, -1, 0, 0};
    string dirs = "RLDU";
    int n, m, si = 0, sj = 0;
    read(n, m);
    vector<vector<char>> grid(n, vector<char>(m)), prev(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (auto &ele : grid) readContainer(ele);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
                break;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (grid[i][j] == 'B') {
            string ans = "";
            while (1) {
                ans += prev[i][j];
                if (ans.back() == 'L')
                    ++j;
                else if (ans.back() == 'R')
                    --j;
                else if (ans.back() == 'U')
                    ++i;
                else if (ans.back() == 'D')
                    --i;
                if (i == si && j == sj) break;
            }
            reverse(begin(ans), end(ans));
            write("YES\n", ans.size(), "\n", ans);
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj] != '#') {
                q.push(make_pair(ni, nj));
                prev[ni][nj] = dirs[k];
            }
        }
    }
    write("NO");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // read(T);
    for (int t = 1; t <= T; ++t) {
        solve();
    }
}