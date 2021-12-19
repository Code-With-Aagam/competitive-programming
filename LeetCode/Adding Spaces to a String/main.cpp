class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        unordered_set<int> spacesIndices(begin(spaces), end(spaces));
        for (int i = 0; i < n; ++i) {
            if (spacesIndices.count(i) > 0) {
                ans += " ";
            }
            ans += s[i];
        }
        return ans;
    }
};