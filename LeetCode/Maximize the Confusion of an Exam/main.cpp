class Solution {
private:
    int longestOnes(vector<int>& nums, int k) {
        int lo = 0, hi = 0;
        while (hi < nums.size()) {
            if (nums[hi] == 0) --k;
            if (k < 0) {
                if (nums[lo] == 0) ++k;
                ++lo;
            }
            ++hi;
        }
        return hi - lo;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> a, b;
        for (const auto &ch : answerKey) {
            if (ch == 'T') {
                a.push_back(1);
                b.push_back(0);
            } else {
                a.push_back(0);
                b.push_back(1);
            }
        }
        return max(longestOnes(a, k), longestOnes(b, k));
    }
};