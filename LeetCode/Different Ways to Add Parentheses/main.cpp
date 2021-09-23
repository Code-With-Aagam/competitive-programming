class Solution {
private:
    map<string, vector<int>> cache;

    bool isOperator(const char &ch) {
        return ch == '+' || ch == '-' || ch == '*';
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        if (cache.count(expression) > 0) return cache[expression];
        vector<int> ans;
        for (int i = 0; i < expression.size(); ++i) {
            if (isOperator(expression[i])) {
                auto left = diffWaysToCompute(expression.substr(0, i));
                auto right = diffWaysToCompute(expression.substr(i + 1));
                for (const auto &lhs : left) {
                    for (const auto &rhs : right) {
                        if (expression[i] == '+') {
                            ans.push_back(lhs + rhs);
                        } else if (expression[i] == '-') {
                            ans.push_back(lhs - rhs);
                        } else {
                            ans.push_back(lhs * rhs);
                        }
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(expression));
        cache[expression] = ans;
        return ans;
    }
};