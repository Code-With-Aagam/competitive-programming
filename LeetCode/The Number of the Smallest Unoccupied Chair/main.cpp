class Solution {
   public:
    int smallestChair(vector<vector<int>>& t, int targetFriend) {
        vector<vector<int>> times;
        for (int i = 0; i < t.size(); ++i) {
            times.push_back({t[i][0], t[i][1], i});
        }
        sort(begin(times), end(times));
        vector<int> chair(times.size(), -1);
        for (int i = 0; i < times.size(); ++i) {
            for (int j = 0; j < chair.size(); ++j) {
                if (chair[j] <= times[i][0]) {
                    chair[j] = times[i][1];
                    if (targetFriend == times[i][2]) {
                        return j;
                    }
                    break;
                }
            }
        }
        return 0;
    }
};