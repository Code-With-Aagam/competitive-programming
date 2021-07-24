private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")

fun main() {
    val t = mutableListOf("H", "2B", "3B", "HR").sorted()
    val s = mutableListOf<String>()
    for (i in 0 until 4) {
        val c = readLn()
        s.add(c)
    }
    s.sort()
    when (s) {
        t -> print("Yes")
        else -> print("No")
    }
}