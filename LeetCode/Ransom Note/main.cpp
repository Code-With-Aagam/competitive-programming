class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for (const auto &ch : magazine) {
            freq[ch - 'a']++;
        }
        for (const auto &ch : ransomNote) {
            freq[ch - 'a']--;
        }
        for (const auto &ele : freq) {
            if (ele < 0) return false;
        }
        return true;
    }
};