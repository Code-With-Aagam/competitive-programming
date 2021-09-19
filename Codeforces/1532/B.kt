private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }
private fun readDouble() = readLn().toDouble()
private fun readDoubles() = readLns().map { it.toDouble() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        val (a, b, k) = readLongs()
        var curr: Long
        if (k % 2 == 0L) {
            curr = (k / 2) * (a - b)
        } else {
            curr = ((k - 1) / 2) * (a - b)
            curr += a
        }
        println(curr)
    }
}