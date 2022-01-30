class Solution {
public:
	int findFinalValue(vector<int>& nums, int original) {
		while (find(cbegin(nums), cend(nums), original) != cend(nums)) {
            original <<= 1;
        }
		return original;
	}
};