class Solution {
private:
    bool isOperator(const char &ch) {
        return ch == '|' || ch == '!' || ch == '&';
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (const auto &ch : expression) {
            if (ch == '(' || ch == ',') continue;
            if (ch == 't' || ch == 'f' || isOperator(ch)) {
                st.push(ch);
            } else {
                int trueCount = 0, falseCount = 0;
                while (!isOperator(st.top())) {
                    if (st.top() == 't') ++trueCount;
                    else ++falseCount;
                    st.pop();
                }
                char next = '$';
                if (st.top() == '|') {
                    if (trueCount > 0) {
                        next = 't';
                    } else {
                        next = 'f';
                    }
                } else if (st.top() == '&') {
                    if (falseCount > 0) {
                        next = 'f';
                    } else {
                        next = 't';
                    }
                } else {
                    if (falseCount > 0) {
                        next = 't';
                    } else {
                        next = 'f';
                    }
                }
                st.pop();
                st.push(next);
            }
        }
        return st.top() == 't';
    }
};