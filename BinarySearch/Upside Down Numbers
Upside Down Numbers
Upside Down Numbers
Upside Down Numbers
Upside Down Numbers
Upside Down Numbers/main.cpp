string digits = "01689";
vector<string> ans;

void generateAllNumbers(int lo, int hi, vector<char> &curr) {
    if (lo > hi) {
        string temp = "";
        for (const auto &ch : curr) temp += ch;
        ans.push_back(temp);
        return;
    } else if (lo == hi) {
        for (const auto &ch : digits) {
            if (ch == '0' || ch == '1' || ch == '8') {
                curr[lo] = ch;
                generateAllNumbers(lo + 1, hi - 1, curr);
            }
        }
    } else {
        for (const auto &ch : digits) {
            if ((ch == '0' && lo > 0) || ch == '1' || ch == '8') {
                curr[lo] = ch;
                curr[hi] = ch;
                generateAllNumbers(lo + 1, hi - 1, curr);
            } else if (ch == '6') {
                curr[lo] = ch;
                curr[hi] = '9';
                generateAllNumbers(lo + 1, hi - 1, curr);
            } else if (ch == '9') {
                curr[lo] = ch;
                curr[hi] = '6';
                generateAllNumbers(lo + 1, hi - 1, curr);
            }
        }
    }
}

vector<string> solve(int n) {
    if (n == 0) return {};
    vector<char> curr(n);
    ans.clear();
    generateAllNumbers(0, n - 1, curr);
    return ans;
}