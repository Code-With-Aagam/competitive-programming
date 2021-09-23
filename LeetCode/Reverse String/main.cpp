class Solution {
private:
	void reverseStringRecursive(vector<char>& s, int i, int j) {
		if (i < j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			reverseStringRecursive(s, i + 1, j - 1);
		}
	}

public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverseStringRecursive(s, 0, n - 1);
    }
};