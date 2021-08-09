class Solution {
   public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        string ans = "";
        ans += s[0];
        ans += s[1];
        for (int i = 2; i < s.size(); ++i) {
            int m = ans.size();
            if (s[i] == ans[m - 1] && s[i] == ans[m - 2]) continue;
            ans += s[i];
        }
        return ans;
    }
};