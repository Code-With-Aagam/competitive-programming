private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readDoubles() = readLns().map { it.toDouble() }

fun main() {
    val ab = readDoubles()
    print(((ab[0] - ab[1]) / 3.0) + ab[1])
}