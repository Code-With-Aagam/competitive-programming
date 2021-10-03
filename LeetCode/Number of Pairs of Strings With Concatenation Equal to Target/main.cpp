class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && nums[i] + nums[j] == target) ++ans;
            }
        }
        return ans;
    }
};