class Solution {
    bool checkPalindrome(const string &s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) return false;
            ++lo;
            --hi;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto &word : words) {
            if (checkPalindrome(word)) return word;
        }
        return "";
    }
};