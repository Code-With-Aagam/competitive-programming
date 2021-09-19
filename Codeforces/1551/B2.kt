import kotlin.math.min

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val nk = readInts()
        val arr = readInts()
        val indices = hashMapOf<Int, ArrayList<Int>>()
        for (i in arr.indices) {
            indices[arr[i]]?.let {
                indices[arr[i]]?.add(i)
            } ?: run {
                indices[arr[i]] = arrayListOf(i)
            }
        }
        val ans = IntArray(nk[0]) { 0 }
        var color = 0
        indices.values.forEach { value ->
            for (i in 0 until min(nk[1], value.size)) {
                ans[value[i]] = color + 1
                ++color
            }
        }
        val done = (color / nk[1]) * nk[1]
        for (i in ans.indices) {
            if (ans[i] > done) {
                ans[i] = 0
            } else if (ans[i] > 0) {
                ans[i] = (ans[i] - 1) % nk[1]
                ++ans[i]
            }
        }
        for (ele in ans) print("$ele ")
        println()
    }
}