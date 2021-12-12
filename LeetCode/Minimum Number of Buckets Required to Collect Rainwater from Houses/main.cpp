class Solution {
public:
	int minimumBuckets(string street) {
		if (street == "H" or street == "HH" or street == "HHH") return -1;
        int n = street.size();
        if (street.size() >= 2 and ((street[0] == 'H' and street[1] == 'H') or (street[n - 1] == 'H' and street[n - 2] == 'H'))) {
            return -1;
        }
		for (int i = 0; i < n; ++i) {
			if (i + 3 < n and street.substr(i, 3) == "HHH") {
				return -1;
			}
		}
		// .H.H.
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (street[i] == 'H') {
                if (i - 1 >= 0 and street[i - 1] == 'D') continue;
				if (i + 1 < n and street[i + 1] == '.') {
					street[i] = 'D';
					street[i + 1] = 'D';
				}
				++ans;
			}
		}
		return ans;
	}
};