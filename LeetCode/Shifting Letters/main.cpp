class Solution {
   public:
    string shiftingLetters(string s, vector<int> &shifts) {
        int n = shifts.size();
        for (int i = n - 2; i >= 0; --i) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        vector<char> alphabets;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            alphabets.push_back(ch);
        }
        string ans = "";
        for (int i = 0; i < n; ++i) {
            int index = s[i] - 'a';
            index = (index + shifts[i]) % 26;
            ans += alphabets[index];
        }
        return ans;
    }
};