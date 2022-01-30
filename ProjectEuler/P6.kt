fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val N = readLine()?.toLong() ?: 0L
        var ans = N * (N + 1) / 2L
        ans *= ans
        for (num in 1 until N + 1) {
            ans -= num * num
        }
        println(ans)
    }
}