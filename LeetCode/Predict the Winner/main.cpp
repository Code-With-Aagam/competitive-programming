class Solution {
private:
    int findScore(const vector<int> &nums, int i, int j, int turn) {
        if (i > j) return 0;
        if (turn == 0) {
            return max(nums[i] + findScore(nums, i + 1, j, 1), nums[j] + findScore(nums, i, j - 1, 1));
        } else {
            return min(findScore(nums, i + 1, j, 0), findScore(nums, i, j - 1, 0));
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int scoreOne = findScore(nums, 0, nums.size() - 1, 0);
        int scoreTwo = accumulate(cbegin(nums), cend(nums), 0LL) - scoreOne;        
        return scoreOne >= scoreTwo;
    }
};