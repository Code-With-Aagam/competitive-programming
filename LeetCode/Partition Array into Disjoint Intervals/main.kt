import kotlin.math.max
import kotlin.math.min

class Solution {
    fun partitionDisjoint(nums: IntArray): Int {
        val n = nums.size
        val (maxLeft, minRight) = listOf(nums.toMutableList(), nums.toMutableList())
        for (i in 1 until n) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i])
        }
        for (i in n - 2 downTo 0) {
            minRight[i] = min(minRight[i + 1], nums[i])
        }
        var ans = 0
        for (i in 1 until n) {
            if (maxLeft[i - 1] <= minRight[i]) {
                ans = i
                break
            }
        }
        return ans
    }
}