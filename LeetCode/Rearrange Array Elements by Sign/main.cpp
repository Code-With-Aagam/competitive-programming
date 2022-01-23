class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size(), i = 0;
		vector<int> ans(n);
		for (const auto &ele : nums) {
			if (ele > 0) {
				ans[i] = ele;
				i += 2;
			}
		}
		i = 1;
		for (const auto &ele : nums) {
			if (ele < 0) {
				ans[i] = ele;
				i += 2;
			}
		}
		return ans;
	}
};