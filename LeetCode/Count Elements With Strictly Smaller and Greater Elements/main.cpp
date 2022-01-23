class Solution {
public:
	int countElements(vector<int>& nums) {
		sort(begin(nums), end(nums));
		int n = nums.size(), ans = 0;
		for (int i = 0; i < n; ++i) {
			bool left = false, right = false;
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) left = true;
			}
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] < nums[j]) right = true;
			}
			if (left and right) ++ans;
		}
		return ans;
	}
};