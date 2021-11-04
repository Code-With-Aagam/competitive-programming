class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        set<string> st;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 10 <= s.size()) {
                string curr = s.substr(i, 10);
                if (st.count(curr) > 0) ans.push_back(curr);
                st.insert(curr);
            }
        }
        st.clear();
        for (const auto &ele : ans) st.insert(ele);
        ans.clear();
        for (const auto &ele : st) ans.push_back(ele);
        return ans;
    }
};