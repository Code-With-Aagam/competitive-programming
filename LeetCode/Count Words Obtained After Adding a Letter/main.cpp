class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		for (auto &start : startWords) sort(begin(start), end(start));
		for (auto &target : targetWords) sort(begin(target), end(target));
        unordered_set<string> startWordsSet(cbegin(startWords), cend(startWords));
		int ans = 0;
		for (const auto &target : targetWords) {
			bool ok = false;
			for (int i = 0; i < target.size(); ++i) {
				string curr = target.substr(0, i) + target.substr(i + 1);
				if (startWordsSet.count(curr) > 0) {
                    ok = true;
                    break;
                }
			}
			if (ok) ++ans;
		}
		return ans;
	}
};