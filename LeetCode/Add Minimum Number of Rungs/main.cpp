class Solution {
   public:
    int addRungs(vector<int> &rungs, int dist) {
        int ans = 0;
        if (rungs[0] > dist) ans = (rungs[0] - 1) / dist;
        for (int i = 1; i < rungs.size(); ++i) {
            int curr = rungs[i] - rungs[i - 1];
            if (curr > dist) {
                ans += (curr - 1) / dist;
            }
        }
        return ans;
    }
};