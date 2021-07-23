#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        vector<int> freq(26, 0);
        for (const auto &c : s) freq[c - 'a']++;
        int ans = 0, extra = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 1) {
                ++extra;
            } else if (freq[i] > 1) {
                ++ans;
            }
        }
        ans += extra / 2;
        cout << ans << "\n";
    }
    return 0;
}