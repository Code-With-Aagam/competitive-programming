class Solution {
public:
	int minimumCost(vector<int>& cost) {
		sort(begin(cost), end(cost));
		int i = cost.size() - 1, ans = 0;
		while (i >= 0) {
			ans += cost[i];
			if (i - 1 >= 0)	ans += cost[i - 1];
			i -= 3;
		}
		return ans;
	}
};