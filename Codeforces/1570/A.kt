private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val T = readInt()
    repeat(T) {
        val ab = readInts()
        println(ab[0] + ab[1])
    }
}