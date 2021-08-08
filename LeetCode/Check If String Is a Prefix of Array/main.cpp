class Solution {
   public:
    bool isPrefixString(string s, vector<string>& words) {
        string t = "";
        for (const auto& word : words) {
            t += word;
            if (s == t)
                return true;
            else if (t.size() > s.size())
                return false;
        }
        return false;
    }
};