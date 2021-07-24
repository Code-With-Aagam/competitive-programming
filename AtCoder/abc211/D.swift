private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let mod = Int(1e9 + 7)
let nm = readInts()
var adj = [[Int]](repeating: [], count: nm[0])
for _ in 0 ..< nm[1] {
	let uv = readInts()
	adj[uv[0] - 1].append(uv[1] - 1)
	adj[uv[1] - 1].append(uv[0] - 1)
}
var ans = [Int](repeating: 0, count: nm[0])
var dist = [Int](repeating: Int.max, count: nm[0])
var visited = [Bool](repeating: false, count: nm[0])
var q = [Int]()
dist[0] = 0
ans[0] = 1
q.append(0)
visited[0] = true
while !q.isEmpty {
	let curr = q.removeFirst()
	adj[curr].forEach { next in
		if !visited[next] {
			q.append(next)
			visited[next] = true
		}
		if dist[next] > dist[curr] + 1 {
			dist[next] = dist[curr] + 1
			ans[next] = ans[curr]
		} else if dist[next] == dist[curr] + 1 {
			ans[next] = (ans[next] + ans[curr]) % mod
		}
	}
}
print(ans[nm[0] - 1])