class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n, ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int curr = 0;
            for (int i = 1; i <= m; ++i) {
                curr += min(mid / i, n);
            }
            if (curr >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};