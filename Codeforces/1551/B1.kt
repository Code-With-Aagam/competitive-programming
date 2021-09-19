private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    val t = readInt()
    repeat(t) {
        val s = readLn()
        val freq = MutableList(26) { 0 }
        for (c in s) freq[c - 'a']++
        var (ans, extra) = listOf(0, 0)
        for (i in 0 until 26) {
            when (freq[i]) {
                1 -> ++extra
                in 2..Integer.MAX_VALUE -> ++ans
            }
        }
        ans += extra / 2
        println(ans)
    }
}