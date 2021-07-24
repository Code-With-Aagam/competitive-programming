class Solution {
    fun areOccurrencesEqual(s: String): Boolean {
        val freq = IntArray(26)
        s.forEach { freq[it - 'a']++ }
        val ans = hashSetOf<Int>()
        freq.forEach {
            if (it > 0) ans.add(it)
        }
        return ans.size == 1
    }
}