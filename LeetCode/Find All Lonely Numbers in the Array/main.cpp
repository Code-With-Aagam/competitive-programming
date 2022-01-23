class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		map<int, int> freq;
		for (const auto &ele : nums) freq[ele]++;
		vector<int> ans;
		for (const auto &ele : nums) {
			if (freq[ele] == 1 and freq[ele - 1] == 0 and freq[ele + 1] == 0) {
				ans.push_back(ele);
			}
		}
		return ans;
	}
};