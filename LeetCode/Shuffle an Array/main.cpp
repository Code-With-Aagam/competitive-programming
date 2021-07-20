class Solution {
   private:
    vector<int> originalArray, shuffledArray;
    int size;

   public:
    Solution(vector<int>& nums) {
        originalArray = nums;
        shuffledArray = nums;
        size = nums.size();
    }

    vector<int> reset() {
        shuffledArray = originalArray;
        return originalArray;
    }

    vector<int> shuffle() {
        for (int i = 1; i < size; ++i) {
            int j = rand() % (i + 1);
            swap(shuffledArray[i], shuffledArray[j]);
        }
        return shuffledArray;
    }
};