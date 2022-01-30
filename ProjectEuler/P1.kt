fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val N = readLine()?.toLong() ?: 0L
        val a = (N - 1) / 3
        val b = (N - 1) / 5
        val c = (N - 1) / 15
        var ans = 0L
        ans += 3 * a * (a + 1) / 2
        ans += 5 * b * (b + 1) / 2
        ans -= 15 * c * (c + 1) / 2
        println(ans)
    }
}