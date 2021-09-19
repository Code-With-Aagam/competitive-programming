private fun readLine() = kotlin.io.readLine()!!
private fun readInt() = readLine().toInt()
private fun readInts() = readLine().split(" ").map { it.toInt() }

fun main() {
    val testCases = readInt()
    for (testCase in 0 until testCases) {
        val arr = readInts()
        val x = Math.max(arr[0], arr[1])
        val y = Math.min(arr[0], arr[1])
        val diff = (x - y) / y + if ((x - y) % y == 0) 0 else 1
        println(if (diff <= arr[2]) "YES" else "NO")
    }
}
