class Solution {
public:
	int countWords(vector<string>& A, vector<string>& B) {
		map<string, int> AM, BM;
		for (const auto &w : A) AM[w]++;
		for (const auto &w : B) BM[w]++;
		int ans = 0;
		for (const auto &w : A) {
			if (AM[w] == 1 and BM[w] == 1) ++ans;
		}
		return ans;
	}
};