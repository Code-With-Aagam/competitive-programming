import kotlin.math.max

class Solution {
    var students = Array(0) { IntArray(0) }
    var mentors = Array(0) { IntArray(0) }
    var dp = IntArray(257) { -1 }

    fun solve(i: Int, mask: Int): Int {
        if (i == students.size) return 0
        if (dp[mask] != -1) return dp[mask]
        var (ans, one) = listOf(0, 1)
        for (j in students.indices) {
            if (mask.and(one.shl(j)) == 0) {
                var curr = 0
                for (k in students[0].indices) {
                    if (students[i][k] == mentors[j][k]) ++curr
                }
                ans = max(ans, curr + solve(i + 1, mask.or(one.shl(j))))
            }
        }
        dp[mask] = ans
        return ans
    }

    fun maxCompatibilitySum(s: Array<IntArray>, m: Array<IntArray>): Int {
        students = s
        mentors = m
        dp = IntArray(257) { -1 }
        return solve(0, 0)
    }
}