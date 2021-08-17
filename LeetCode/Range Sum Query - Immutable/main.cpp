class NumArray {
    vector<int> ans;

   public:
    NumArray(vector<int>& nums) {
        ans = vector<int>(nums.size());
        partial_sum(begin(nums), end(nums), begin(ans));
    }

    int sumRange(int left, int right) {
        return ans[right] - (left > 0 ? ans[left - 1] : 0);
    }
};