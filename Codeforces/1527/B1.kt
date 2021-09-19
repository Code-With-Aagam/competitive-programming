import kotlin.math.log2

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
//private fun readInts() = readLn().split(" ").map { it.toInt() }
//private fun readLong() = readLn().toLong()
//private fun readLongs() = readLn().split(" ").map { it.toLong() }

fun main(args: Array<String>) {
    val T = readInt()
    for (t in 1..T) {
        val N = readInt()
        val S = readLn()
        val zeros = S.count { it == '0' }
        when {
            zeros == 0 -> println("DRAW")
            zeros % 2 == 0 || zeros == 1 -> println("BOB")
            else -> println("ALICE")
        }
    }
}