fun main() {
    val T = readLine()?.toInt() ?: 0
    repeat(T) {
        val NK = readLine()?.split(" ")?.map { it.toInt() } ?: emptyList()
        val S = readLine() ?: ""
        var ans = 0
        for (index in S.indices) {
            if (index + 1 - NK[1] >= 0) {
                var curr = 1
                for (i in index + 1 - NK[1] until index + 1) {
                    curr *= S[i] - '0'
                }
                ans = ans.coerceAtLeast(curr)
            }
        }
        println(ans)
    }
}