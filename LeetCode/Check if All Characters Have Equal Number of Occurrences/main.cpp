class Solution {
   public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);
        for (const auto &ch : s) freq[ch - 'a']++;
        unordered_set<int> ans;
        for (const auto &ele : freq) {
            if (ele > 0) ans.insert(ele);
        }
        return ans.size() == 1;
    }
};