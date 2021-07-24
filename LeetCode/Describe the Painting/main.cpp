class Solution {
   public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long N = 100005LL, n = 0LL;
        vector<long long> color(N, 0);
        vector<bool> hash(N, false);
        for (const auto& segment : segments) {
            color[segment[0]] += segment[2];
            color[segment[1]] -= segment[2];
            hash[segment[0]] = true;
            hash[segment[1]] = true;
            n = max(n, (long long)segment[1]);
        }
        vector<vector<long long>> ans;
        long long curr = 0, prev = 0;
        for (long long i = 1; i <= n; ++i) {
            if (hash[i] && curr > 0) {
                ans.push_back({prev, i, curr});
            }
            if (hash[i]) prev = i;
            curr += color[i];
        }
        return ans;
    }
};