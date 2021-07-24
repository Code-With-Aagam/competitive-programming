import java.util.*

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val nm = readInts()
    val adj = Array(nm[0]) { mutableListOf<Int>() }
    repeat(nm[1]) {
        val uv = readInts()
        adj[uv[0] - 1].add(uv[1] - 1)
        adj[uv[1] - 1].add(uv[0] - 1)
    }
    val (ans, dist) = listOf(IntArray(nm[0]), IntArray(nm[0]) { Integer.MAX_VALUE })
    val visited = BooleanArray(nm[0])
    val q: Queue<Int> = LinkedList()
    val mod = (1e9 + 7).toInt()
    dist[0] = 0
    ans[0] = 1
    q.add(0)
    visited[0] = true
    while (q.isNotEmpty()) {
        val curr = q.poll()
        adj[curr].forEach { next ->
            if (!visited[next]) {
                q.add(next)
                visited[next] = true
            }
            if (dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1
                ans[next] = ans[curr]
            } else if (dist[next] == dist[curr] + 1) {
                ans[next] = (ans[next] + ans[curr]).rem(mod)
            }
        }
    }
    print(ans[nm[0] - 1])
}