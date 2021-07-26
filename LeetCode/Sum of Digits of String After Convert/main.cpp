class Solution {
   public:
    int getLucky(string s, int k) {
        vector<int> nums;
        auto extractDigits = [&](int n) {
            while (n > 0) {
                nums.push_back(n % 10);
                n /= 10;
            }
        };
        for (const auto &ch : s) {
            int ele = ch - 'a' + 1;
            extractDigits(ele);
        }
        while (k--) {
            int ele = 0;
            for (const auto &x : nums) ele += x;
            nums.clear();
            extractDigits(ele);
        }
        reverse(begin(nums), end(nums));
        string ans = "";
        for (const auto &ele : nums) {
            ans += to_string(ele);
        }
        return stoi(ans);
    }
};