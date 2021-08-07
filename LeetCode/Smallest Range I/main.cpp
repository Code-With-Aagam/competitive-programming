class Solution {
   public:
    int smallestRangeI(vector<int>& nums, int k) {
        const auto [min, max] = std::minmax_element(nums.begin(), nums.end());
        int gap = *max - *min;
        if (2 * k >= gap) {
            return 0;
        }
        return gap - 2 * k;
    }
};