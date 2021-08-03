class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        set<vector<int>> ans;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> curr;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    curr.push_back(nums[i]);
                }
            }
            ans.insert(curr);
        }
        return vector<vector<int>>(cbegin(ans), cend(ans));
    }
};