private fun readLine() = kotlin.io.readLine()!!
private fun readInt() = readLine().toInt()
private fun readInts() = readLine().split(" ").map { it.toInt() }

lateinit var dp: Array<IntArray>

fun solve(i: Int, j: Int, n: Int, m: Int, curr: Int): Boolean {
    if (i <= 0 || j <= 0 || i > n || j > m) return false
    if (dp[i][j] != -1) return dp[i][j] != 0
    if (i == n && j == m) return curr == 0
    if (solve(i + 1, j, n, m, curr - j) || solve(i, j + 1, n, m, curr - i)) {
        dp[i][j] = 1
        return true
    }
    dp[i][j] = 0
    return false
}

fun main() {
    val testCases = readInt()
    for (testCase in 0 until testCases) {
        val arr = readInts()
        dp = Array(arr[0] + 1) { IntArray(arr[1] + 1) { -1 } }
        val good = solve(1, 1, arr[0], arr[1], arr[2])
        println(if (good) "YES" else "NO")
    }
}
