private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
	var t = readInt()
	while (t > 0) {
		val (a, b) = readInts()
		println(a + b)
		t--
	}
}