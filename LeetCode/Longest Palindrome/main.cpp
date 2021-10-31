class Solution {
public:
	int longestPalindrome(string s) {
		map<char, int> freq;
		for (const auto &ele : s) freq[ele]++;
		int ans = 0;
		bool done = false;
		for (const auto &ele : freq) {
			if (ele.second % 2 == 1 && !done) {
				ans++;
				done = true;
			}
			ans += (ele.second / 2) * 2;
		}
		return ans;
	}
};