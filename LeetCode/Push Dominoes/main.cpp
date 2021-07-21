class Solution {
   public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        int ops = 0;
        auto replaceAllOccurences = [&](string &s, const string &from, const string &to) {
            int startPosition = 0;
            while ((startPosition = s.find(from, startPosition)) != string::npos) {
                s.replace(startPosition, from.length(), to);
                startPosition += to.length();
            }
        };
        while (true) {
            string newDominoes = ans;
            replaceAllOccurences(newDominoes, "R.L", "|");
            replaceAllOccurences(newDominoes, ".L", "LL");
            replaceAllOccurences(newDominoes, "R.", "RR");
            replaceAllOccurences(newDominoes, "|", "R.L");
            if (ans == newDominoes) {
                break;
            } else {
                ans = newDominoes;
            }
        }
        return ans;
    }
};