class Solution {
	vector<int> dsu, rank;
    int N = 1e5 + 1;
    
	int findParent(int u) {
		while (u != dsu[u]) {
			dsu[u] = dsu[dsu[u]];
			u = dsu[u];
		}
		return u;
	}

	void merge(int u, int v) {
		int pu = findParent(u);
		int pv = findParent(v);
		if (pu != pv) {
			if (rank[pu] > rank[pv]) {
                dsu[pv] = pu;
            } else {
                dsu[pu] = pv;
                if (rank[pu] == rank[pv]) {
                    rank[pv]++;
                }
            }
		}
	}
public:
	int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        dsu.resize(N);
        rank.resize(N);
        for (int i = 0; i < N; ++i) {
            dsu[i] = i;
            rank[i] = 1;
        }
		for (int i = 0; i < n; ++i) {
			for (int j = 2; j <= sqrt(nums[i]); ++j) {
				if (nums[i] % j == 0) {
					merge(nums[i], j);
                    merge(nums[i], nums[i] / j);
				}
			}
		}
        map<int, int> mp;
        int ans = 0;
        for (const auto &ele : nums) {
            ans = max(ans, ++mp[findParent(ele)]);
        }
        return ans;
	}
};