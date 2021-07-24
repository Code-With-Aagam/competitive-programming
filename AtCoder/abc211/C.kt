private fun readLn() = readLine() ?: ""

fun main() {
    val s = readLn()
    val t = "chokudai"
    val (n, m, mod) = listOf(s.length, t.length, 1000000007)
    val dp = Array(m + 1) { Array(n + 1) { 0 } }
    for (j in 0..n) dp[0][j] = 1
    for (i in 1..m) {
        for (j in 1..n) {
            if (t[i - 1] != s[j - 1]) {
                dp[i][j] = dp[i][j - 1]
            } else {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]).rem(mod)
            }
        }
    }
    print(dp[m][n])
}