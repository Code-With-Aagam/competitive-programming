class Solution {
   public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> broken(cbegin(brokenLetters), cend(brokenLetters));
        int ans = 0;
        istringstream ss(text);
        string word;
        while (getline(ss, word, ' ')) {
            bool good = true;
            for (const auto &ele : word) {
                if (broken.count(ele) > 0) good = false;
            }
            if (good) ++ans;
        }
        return ans;
    }
};