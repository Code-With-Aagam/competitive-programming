class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX, mnIndex = -1, mx = INT_MIN, mxIndex = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxIndex = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                mnIndex = i;
            }
        }
        if (mxIndex == mnIndex) return 1;
        int minFromFront = mnIndex + 1;
        int maxFromFront = mxIndex + 1;
        int minFromBack = n - minFromFront + 1;
        int maxFromBack = n - maxFromFront + 1;
        if (mnIndex < mxIndex) {
            return min({minFromFront + maxFromBack, minFromBack, maxFromFront});
        } else {
            return min({maxFromFront + minFromBack, maxFromBack, minFromFront});
        }
    }
};