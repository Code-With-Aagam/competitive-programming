class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		vector<string> ans;
		string curr = "";
		for (const auto &ele : s) {
			if (curr.size() == k) {
				ans.push_back(curr);
				curr = "";
			}
            curr += ele;
		}
		if (not curr.empty() and curr.size() <= k) {
			while (curr.size() < k) curr += fill;
			ans.push_back(curr);
		}
		return ans;
	}
};