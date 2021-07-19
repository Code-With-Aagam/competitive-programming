class Solution {
	func maxPoints(_ points: [[Int]]) -> Int {
		var dp = [Int](repeating: 0, count: points[0].count)
		for row in points {
			for i in 1 ..< row.count {
				dp[i] = max(dp[i], dp[i - 1] - 1)
				dp[row.count - i - 1] = max(dp[row.count - i - 1], dp[row.count - i] - 1)
			}
			for i in row.indices {
				dp[i] += row[i]
			}
		}
		return dp.max() ?? 0
	}
}