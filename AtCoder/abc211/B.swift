private func readLn() -> String {
	return readLine() ?? ""
}

let t = ["H", "2B", "3B", "HR"].sorted()
var s = [String]()
for _ in 0 ..< 4 {
	let c = readLn()
	s.append(c)
}
s.sort()
print((s == t ? "Yes" : "No"))