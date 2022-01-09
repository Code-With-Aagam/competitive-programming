class Solution {
public:
	int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
		vector<pair<int, int>> times(plantTime.size());
		for (int i = 0; i < times.size(); ++i) {
			times[i] = make_pair(growTime[i], plantTime[i]);
		}
		sort(begin(times), end(times), greater<pair<int, int>>());
		int startTime = 0, totalTime = 0;
		for (const auto &ele : times) {
			startTime += ele.second;
			totalTime = max(totalTime, startTime + ele.first);
		}
		return totalTime;
	}
};