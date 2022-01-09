class Solution {
    string capitalizeWord(const string &word) {
        string ans = "";
        ans += word.size() > 2 ? toupper(word[0]) : tolower(word[0]);
        for (int i = 1; i < word.size(); ++i) {
            ans += tolower(word[i]);
        }
        return ans;
    }
public:
    string capitalizeTitle(string title) {
        string ans = "", word = "";
        for (const auto &ch : title) {
            if (ch == ' ') {
                ans += capitalizeWord(word);
                ans += " ";
                word = "";
            } else {
                word += ch;
            }
        }
        ans += capitalizeWord(word);
        return ans;
    }
};