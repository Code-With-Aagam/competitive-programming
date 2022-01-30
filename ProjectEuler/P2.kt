fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val N = readLine()?.toLong() ?: 0L
        val fibonacciNumbers = mutableListOf(1L, 2L)
        while (fibonacciNumbers[fibonacciNumbers.size - 1] + fibonacciNumbers[fibonacciNumbers.size - 2] <= N) {
            fibonacciNumbers.add(fibonacciNumbers[fibonacciNumbers.size - 1] + fibonacciNumbers[fibonacciNumbers.size - 2])
        }
        val ans = fibonacciNumbers.filter { it % 2 == 0L }.sum()
        println(ans)
    }
}