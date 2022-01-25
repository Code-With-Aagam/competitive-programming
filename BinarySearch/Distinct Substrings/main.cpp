int solve(string s) {
    unordered_set<string> ans;
    for (int len = 1; len <= s.size(); ++len) {
        for (int i = 0; i + len <= s.size(); ++i) {
            ans.insert(s.substr(i, len));
        }
    }
    return ans.size();
}