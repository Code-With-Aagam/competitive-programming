class Solution {
private:
    string multiplyString(const string &s, int k) {
        string ans = "";
        while (k--) {
            ans += s;
        }
        return ans;
    }

public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string ans = "";
        int curr = 0;
        for (const auto &ch : s) {
            if (ch == '[') {
                st.push(make_pair(ans, curr));
                ans = "";
                curr = 0;
            } else if (ch == ']') {
                auto last = st.top();
                st.pop();
                ans = last.first + multiplyString(ans, last.second);
            } else if (isdigit(ch)) {
                curr *= 10;
                curr += ch - '0';
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};