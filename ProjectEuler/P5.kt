private tailrec fun gcd(x: Int, y: Int): Int {
    return if (y == 0) {
        x
    } else {
        gcd(y, x % y)
    }
}

fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val N = readLine()?.toInt() ?: 0
        var ans = 1
        for (num in 1 until N + 1) {
            ans = (ans * num) / gcd(ans, num);
        }
        println(ans)
    }
}