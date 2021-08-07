class Solution {
   public:
    int smallestRangeII(vector<int> &nums, int k) {
        sort(begin(nums), end(nums));
        int ans = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            int mx = max(nums[i] + k, nums.back() - k);
            int mn = min(nums[i + 1] - k, nums.front() + k);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};