class Solution {
    fun getLucky(s: String, k: Int): Int {
        val nums = mutableListOf<Int>()
        s.forEach { ch ->
            var ele = ch - 'a' + 1
            while (ele > 0) {
                nums.add(ele % 10)
                ele /= 10
            }
        }
        repeat(k) {
            var ele = 0
            nums.forEach { ele += it }
            nums.clear()
            while (ele > 0) {
                nums.add(ele % 10)
                ele /= 10
            }
        }
        return nums.reversed().joinToString("").toInt()
    }
}