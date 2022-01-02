class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int ans = 0, prev = 0;
		for (const auto &row : bank) {
			int curr = 0;
			for (const auto &ch : row) {
				if (ch == '1') ++curr;
			}
			ans += prev * curr;
			if (curr > 0) prev = curr;
		}
		return ans;
	}
};