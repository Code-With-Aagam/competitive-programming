fun main() {
    val T = readLine()?.toInt() ?: 0
    val N = (5e5).toInt()
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
    repeat(T) {
        val n = readLine()?.toInt() ?: 0
        println(primeNumbers[n - 1])
    }
}