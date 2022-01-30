class Solution {
public:
	vector<int> maxScoreIndices(vector<int>& nums) {
		int n = nums.size(), zeros = 0, ones = 0;
		vector<int> left(n + 1, 0), right(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] == 0) ++zeros;
            left[i] = zeros;
        }
		for (int i = n - 1; i >= 0; --i) {
			if (nums[i] == 1) ++ones;
			right[i] = ones;
		}
		int maxScore = 0;
		for (int i = 0; i <= n; ++i) {
			maxScore = max(maxScore, left[i] + right[i]);
		}
		vector<int> ans;
		for (int i = 0; i <= n; ++i) {
			if (maxScore == left[i] + right[i]) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};