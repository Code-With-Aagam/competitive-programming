import kotlin.math.max

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }
private fun readDouble() = readLn().toDouble()
private fun readDoubles() = readLns().map { it.toDouble() }

fun main() {
    val tc = readInt()
    repeat(tc) {
        val nk = readInts()
        val (n, k) = listOf(nk[0], nk[1])
        var ans = 0
        repeat(n) {
            val lr = readInts()
            val (l, r) = listOf(lr[0], lr[1])
            if (k >= l) {
                ans = maxOf(ans, 0, r - k + 1)
            }
        }
        println(ans)
    }
}