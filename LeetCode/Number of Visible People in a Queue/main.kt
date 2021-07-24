import java.util.*

class Solution {
    fun canSeePersonsCount(heights: IntArray): IntArray {
        val ans = IntArray(heights.size)
        val st = Stack<Int>()
        for (i in heights.indices) {
            while (st.isNotEmpty() && heights[st.peek()] <= heights[i]) {
                ans[st.pop()]++
            }
            if (st.isNotEmpty()) ans[st.peek()]++
            st.push(i)
        }
        return ans
    }
}