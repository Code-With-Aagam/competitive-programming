import kotlin.math.max

class Solution {
    fun splitPainting(segments: Array<IntArray>): List<List<Long>> {
        var (N, n) = listOf(100005, 0)
        val color = LongArray(N)
        val hash = BooleanArray(N)
        segments.forEach { segment ->
            color[segment[0]] += segment[2].toLong()
            color[segment[1]] -= segment[2].toLong()
            hash[segment[0]] = true
            hash[segment[1]] = true
            n = max(n, segment[1])
        }
        val ans = ArrayList<List<Long>>()
        var (curr, prev) = listOf(0L, 0L)
        for (i in 1..n) {
            if (hash[i] && curr > 0) {
                ans.add(listOf(prev, i.toLong(), curr))
            }
            if (hash[i]) {
                prev = i.toLong()
            }
            curr += color[i]
        }
        return ans
    }
}