private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val arr = mutableListOf<String>()
        val freq = MutableList(n) { MutableList(5) { 0 } }
        repeat(n) {
            val s = readLn()
            arr.add(s)
            for (ch in s) freq[it][ch - 'a']++
        }
        fun findMaxCount(ch: Char): Int {
            val temp = mutableListOf<Int>()
            for (i in arr.indices) {
                val cnt = freq[i][ch - 'a']
                temp.add(cnt - (arr[i].length - cnt))
            }
            temp.sortDescending()
            var (ans, curr) = listOf(0, 0)
            for (ele in temp) {
                curr += ele
                if (curr > 0) ++ans
            }
            return ans
        }

        var ans = 0
        for (ch in "abcde") {
            ans = ans.coerceAtLeast(findMaxCount(ch))
        }
        println(ans)
    }
}