private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }
private fun readDouble() = readLn().toDouble()
private fun readDoubles() = readLns().map { it.toDouble() }

fun main() {
    val n = readInt()
    var arr = readInts()
    var ans = 0
    arr = arr.sorted()
    for (i in 1 until n step 2) {
        ans += arr[i] - arr[i - 1]
    }
    print(ans)
}