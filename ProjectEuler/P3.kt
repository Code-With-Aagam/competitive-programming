fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        var N = readLine()?.toLong() ?: 0L
        var num = 2L
        var ans = 0L
        while (num * num <= N) {
            while (N % num == 0L) {
                ans = ans.coerceAtLeast(num)
                N /= num
            }
            ++num
        }
        println(if (N > 1) N else ans)
    }
}