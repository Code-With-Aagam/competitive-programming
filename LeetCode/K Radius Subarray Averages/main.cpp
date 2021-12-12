class Solution {
public:
    vector<int> getAverages(vector<int>& A, int k) {
        vector<long long> nums;
        for (const auto &ele : A) nums.push_back((long long)ele);
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int s = i - k, e = i + k;
            if (s < 0 or e >= n) {
                ans.push_back(-1);
                continue;
            }
            long long sum = nums[e];
            if (s - 1 >= 0) sum -= nums[s - 1];
            ans.push_back(sum / ((2 * k) + 1));
        }
        return ans;
    }
};