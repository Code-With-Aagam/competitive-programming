class Solution {
	var students = [[Int]]()
	var mentors = [[Int]]()
	var dp = [Int](repeating: -1, count: 257)
	
	func solve(_ i: Int, _ mask: Int) -> Int {
		if i == students.count { return 0 }
		if dp[mask] != -1 { return dp[mask] }
		var ans = 0
		for j in students.indices {
			if (mask & (1 << j)) == 0 {
				var curr = 0
				for k in students[0].indices {
					if students[i][k] == mentors[j][k] {
						curr += 1
					}
				}
				ans = max(ans, curr + solve(i + 1, mask | (1 << j)))
			}
		}
		dp[mask] = ans
		return ans
	}
	
	func maxCompatibilitySum(_ s: [[Int]], _ m: [[Int]]) -> Int {
		students = s
		mentors = m
		dp = [Int](repeating: -1, count: 257)
		return solve(0, 0)
	}
}