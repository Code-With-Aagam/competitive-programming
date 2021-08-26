class Solution {
   public:
    bool judgeSquareSum(int c) {
        set<long long> squares;
        long long x = 0LL;
        while ((x * x) <= 1e9) {
            squares.insert(x * x);
            ++x;
        }
        for (long long a = 0; a * a <= c; ++a) {
            long long b = c - (a * a);
            if (squares.count(b) > 0) {
                return true;
            }
        }
        return false;
    }
};