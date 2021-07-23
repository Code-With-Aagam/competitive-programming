private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val (n, m, k) = readInts().toList()
        val good = when {
            n % 2 == 1 -> (k >= m / 2 && k % 2 == (m / 2) % 2)
            m % 2 == 1 -> (k <= (m - 1) * n / 2 && k % 2 == 0)
            else -> (k % 2 == 0)
        }
        when (good) {
            true -> println("YES")
            false -> println("NO")
        }
    }
}