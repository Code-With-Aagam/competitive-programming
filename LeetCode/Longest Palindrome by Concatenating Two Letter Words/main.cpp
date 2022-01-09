class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> freq;
        int ans = 0;
        for (const auto &word : words) {
            string revWord = word;
            reverse(begin(revWord), end(revWord));
            if (freq[word] > 0) {
                freq[word] -= 1;
                ans += 4;
            } else {
                freq[revWord] += 1;
            }
        }
        for (const auto &[word, cnt] : freq) {
            if (cnt == 1 and word[0] == word[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};