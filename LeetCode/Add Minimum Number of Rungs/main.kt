class Solution {
    fun addRungs(rungs: IntArray, dist: Int): Int {
        var ans = 0
        if (rungs[0] > dist) ans = (rungs[0] - 1) / dist
        for (i in 1 until rungs.size) {
            val curr = rungs[i] - rungs[i - 1]
            if (curr > dist) {
                ans += (curr - 1) / dist
            }
        }
        return ans
    }
}