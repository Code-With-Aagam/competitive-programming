fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val N = readLine()?.toInt() ?: 0
        var ans = -1
        for (a in 1 until (N / 3) + 1) {
            val b = (N * N - 2 * N * a) / (2 * N - 2 * a)
            val c = N - (a + b)
            if (a * a + b * b == c * c) {
                ans = ans.coerceAtLeast(a * b * c)
            }
        }
        println(ans)
    }
}