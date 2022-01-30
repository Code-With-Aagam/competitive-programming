fun main() {
    val T = readLine()?.toInt() ?: 0
    val N = (1e6).toInt()
    val isPrime = MutableList(N + 1) { true }
    val primeNumbers = mutableListOf<Int>()
    for (num in 2 until N + 1) {
        if (isPrime[num]) {
            primeNumbers.add(num)
            for (nextNum in 2 * num until N + 1 step num) {
                isPrime[nextNum] = false
            }
        }
    }
    val primeNumbersPrefixSum = mutableListOf<Long>()
    primeNumbersPrefixSum.add(primeNumbers[0].toLong())
    for (index in 1 until primeNumbers.size) {
        primeNumbersPrefixSum.add(primeNumbersPrefixSum.last() + primeNumbers[index])
    }
    repeat(T) {
        val n = readLine()?.toInt() ?: 0
        var (lo, hi, ans) = listOf(0, primeNumbers.size - 1, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (primeNumbers[mid] <= n) {
                ans = mid
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        println(primeNumbersPrefixSum[ans])
    }
}