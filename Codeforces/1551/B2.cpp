#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> arr(n);
        for (auto &ele : arr) cin >> ele;
        map<int, vector<int>> indices;
        for (int i = 0; i < n; ++i) indices[arr[i]].push_back(i);
        vector<int> ans(n, 0);
        int color = 0;
        for (const auto &[key, value] : indices) {
            for (int i = 0; i < min((int)value.size(), k); ++i) {
                ans[value[i]] = color + 1;
                ++color;
            }
        }
        int done = (color / k) * k;
        for (int i = 0; i < n; ++i) {
            if (ans[i] > done) {
                ans[i] = 0;
            } else if (ans[i] > 0) {
                ans[i] = (ans[i] - 1) % k;
                ++ans[i];
            }
        }
        for (const auto &ele : ans) cout << ele << " ";
        cout << "\n";
    }
    return 0;
}