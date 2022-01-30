fun main() {
    val T = readLine()?.toInt() ?: 0
    val palindromeNumbers = mutableListOf<Int>()
    for (x in 100 until 1000) {
        for (y in 100 until 1000) {
            val numString = (x * y).toString()
            if (numString == numString.reversed()) {
                palindromeNumbers.add(x * y)
            }
        }
    }
    palindromeNumbers.sort()
    repeat(T) {
        val N = readLine()?.toInt() ?: 0
        var (lo, hi, ans) = listOf(0, palindromeNumbers.size, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (palindromeNumbers[mid] < N) {
                ans = mid
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        println(palindromeNumbers[ans])
    }
}