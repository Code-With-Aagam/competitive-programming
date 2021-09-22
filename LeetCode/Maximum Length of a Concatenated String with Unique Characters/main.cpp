class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> freq(26, 0);
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    curr += arr[i].size();
                    for (const auto &ch : arr[i]) {
                        freq[ch - 'a']++;
                    }
                }
            }
            bool good = true;
            for (const auto &ele : freq) {
                if (ele > 1) good = false;
            }
            if (good) ans = max(ans, curr);
        }
        return ans;
    }
};