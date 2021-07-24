private func readLn() -> String {
	return readLine() ?? ""
}

let c = readLn()
let (s, t) = (Array(c), Array("chokudai"))
let (n, m) = (s.count, t.count)
let mod = 1000000007
let temp = [Int](repeating: 0, count: n + 1)
var dp = [[Int]](repeating: temp, count: m + 1)
for j in 0 ... n {
	dp[0][j] = 1
}
for i in 1 ... m {
	for j in 1 ... n {
		if t[i - 1] != s[j - 1] {
			dp[i][j] = dp[i][j - 1]
		} else {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod
		}
	}
}
print(dp[m][n])