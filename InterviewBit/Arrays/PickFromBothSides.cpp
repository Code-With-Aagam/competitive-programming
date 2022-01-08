int Solution::solve(vector<int> &A, int B) {
	int N = A.size();
	for (int i = 1; i < N; ++i) A[i] += A[i - 1];
	auto rangeSum = [&](int l, int r) {
		int ans = A[r];
		if (l > 0) {
			ans -= A[l - 1];
		}
		return ans;
	};
	int ans = -1e9;
	for (int b = 0; b <= B; ++b) {
		int c = B - b;
		int x = rangeSum(0, b - 1);
		int y = rangeSum(N - c, N - 1);
		ans = max(ans, x + y);
	}
	return ans;
}