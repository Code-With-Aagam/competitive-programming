private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun toDecimal(binaryNumber: String, p: Int): Long {
    var sum = 0L
    binaryNumber.reversed().forEachIndexed {
            k, v -> sum += v.toString().toLong() * Math.pow(p.toLong().toDouble(), k.toLong().toDouble()).toLong()
    }
    return sum
}

fun main() {
    val k = readInt()
    val ab = readLns()
    val x = toDecimal(ab[0], k)
    val y = toDecimal(ab[1], k)
    println(x * y)
}