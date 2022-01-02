class Solution {
public:
	bool asteroidsDestroyed(int m, vector<int>& asteroids) {
		long long mass = (long long) m;
		sort(begin(asteroids), end(asteroids));
		int lo = 0, hi = asteroids.size() - 1, idx = -1, lidx = 0;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (mass >= asteroids[mid]) {
				idx = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (idx == -1) return false;
		while (lidx <= idx) {
			swap(asteroids[idx], asteroids[lidx]);
			--idx;
			++lidx;
		}
		for (const auto &ele : asteroids) {
			if (ele > mass) return false;
			mass += (long long) ele;
		}
		return true;
	}
};