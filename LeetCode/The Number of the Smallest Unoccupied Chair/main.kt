import kotlin.collections.ArrayList

class Solution {
    fun smallestChair(t: Array<IntArray>, targetFriend: Int): Int {
        val times = ArrayList<IntArray>()
        for (i in t.indices) {
            times.add(intArrayOf(t[i][0], t[i][1], i))
        }
        times.sortBy { it.first() }
        val chair = IntArray(times.size)
        for (i in times.indices) {
            for (j in chair.indices) {
                if (chair[j] <= times[i][0]) {
                    chair[j] = times[i][1]
                    if (targetFriend == times[i][2]) {
                        return j
                    }
                    break
                }
            }
        }
        return 0
    }
}