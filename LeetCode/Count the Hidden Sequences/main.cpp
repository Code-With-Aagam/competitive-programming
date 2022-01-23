class Solution {
public:
	int numberOfArrays(vector<int>& differences, int lower, int upper) {
		vector<long long> arr = {0LL};
		for (const auto &ele : differences) arr.push_back((long long)ele + arr.back());
		upper -= *max_element(cbegin(arr), cend(arr));
		lower -= *min_element(cbegin(arr), cend(arr));
		int ans = upper - lower + 1;
		return (ans >= 0 ? ans : 0);
	}
};