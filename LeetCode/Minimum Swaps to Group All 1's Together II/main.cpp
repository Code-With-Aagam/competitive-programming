class Solution {
public:
	int minSwaps(vector<int>& arr) {
        vector<int> nums = arr;
        for (const auto &ele : arr) nums.push_back(ele);
		int ones = count(cbegin(arr), cend(arr), 1), zeros = 0;
		for (int i = 0; i < ones; ++i) {
			if (nums[i] == 0) ++zeros;
		}
		int ans = zeros;
		for (int i = ones; i < nums.size(); ++i) {
			if (nums[i] == 0) ++zeros;
			if (nums[i - ones] == 0) --zeros;
			ans = min(ans, zeros);
		}
		return ans;
	}
};