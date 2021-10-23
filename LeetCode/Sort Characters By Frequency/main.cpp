class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqCount;
        for (const auto &ch : s) freqCount[ch]++;
        vector<string> bucket(s.size() + 1);
        for (const auto &[ch, count] : freqCount) {
            bucket[count].append(count, ch);
        }
        string ans = "";
        reverse(begin(bucket), end(bucket));
        for (int i = 0; i < s.size(); ++i) {
            ans += bucket[i];
        }
        return ans;
    }
};