import kotlin.math.max

class Solution {
    fun maxPoints(points: Array<IntArray>): Long {
        val dp = MutableList<Long>(points[0].size) { 0L }
        for (row in points) {
            for (i in 1 until row.size) {
                dp[i] = max(dp[i], dp[i - 1] - 1)
                dp[row.size - i - 1] = max(dp[row.size - i - 1], dp[row.size - i] - 1)
            }
            for (i in row.indices) {
                dp[i] = dp[i] + row[i]
            }
        }
        return dp.max() ?: 0L
    }
}