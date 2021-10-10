class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ops = 0;
        while (left != right) {
            ++ops;
            left >>= 1;
            right >>= 1;
        }
        return left << ops;
    }
};