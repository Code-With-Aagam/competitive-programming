vector<string> ans;
const vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateAllNumbers(int index, const string &digits, string &curr) {
    if (index == digits.size()) {
        ans.push_back(curr);
        return;
    }
    for (const auto &ch : mapping[digits[index] - '0']) {
        curr += ch;
        generateAllNumbers(index + 1, digits, curr);
        curr.pop_back();
    }
}

vector<string> solve(string digits) {
    string curr = "";
    ans.clear();
    generateAllNumbers(0, digits, curr);
    return ans;
}