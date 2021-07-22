class Solution {
   public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft = nums, minRight = nums;
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (maxLeft[i - 1] <= minRight[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};