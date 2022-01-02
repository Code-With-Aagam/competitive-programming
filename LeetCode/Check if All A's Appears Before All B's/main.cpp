class Solution {
public:
    bool checkString(string s) {
        return is_sorted(cbegin(s), cend(s));
    }
};