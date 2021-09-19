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
        val n = readInt()
        val arr = readInts()
        var good = false
        for (i in 1 until n) {
            val diff = arr[i] - arr[i - 1]
            if (diff % 2 == 0) {
                good = true
                break
            }
        }
        when (good) {
            true -> println("YES")
            false -> println("NO")
        }
    }
}