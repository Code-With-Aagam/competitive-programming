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
        val (n, k) = readInts()
        var ch = 'a'
        for (i in 0 until n) {
            print(ch)
            if (ch == 'a' + k - 1) ch = 'a'
            else ++ch
        }
        println()
    }
}