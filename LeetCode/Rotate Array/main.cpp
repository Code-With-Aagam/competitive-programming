class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k %= N;
        reverse(nums.begin(), nums.begin() + N - k);
        reverse(nums.begin() + N - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};