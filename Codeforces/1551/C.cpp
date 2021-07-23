#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> arr(n);
        for (auto &ele : arr) cin >> ele;
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
        cout << ans << "\n";
    }
    return 0;
}