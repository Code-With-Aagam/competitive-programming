private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        var c1 = n / 3
        val c2 = (n - c1) / 2
        if ((n - c1) % 2 == 1) ++c1
        println("$c1 $c2")
    }
}