class Solution {
  public:
	int kthGrammar(int N, int K) {
		if (N == 1) return 0;
		else if (K % 2 == 0) {
			return (kthGrammar(N - 1, K / 2) == 0 ? 1 : 0);
		} else {
			return (kthGrammar(N - 1, (K + 1) / 2) == 0 ? 0 : 1);
		}
	}
};