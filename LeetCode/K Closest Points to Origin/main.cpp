class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for (const auto &point : points) {
            int curr = point[0] * point[0] + point[1] * point[1];
            pq.push({curr, point[0], point[1]});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (not pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            res.push_back({curr[1], curr[2]});
        }
        return res;
    }
};