class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> nums = A;
        for (const auto &ele : A) nums.push_back(ele);
        int maxTillNow = nums[0], currentSum = nums[0], n = nums.size();
        for (const auto &ele : nums) {
            currentSum = max(currentSum + ele, ele);
            maxTillNow = max(maxTillNow, currentSum);
        }
        return maxTillNow;
    }
};