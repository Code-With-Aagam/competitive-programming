private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let NK = readInts()
let c = readInts()
var window = Dictionary<Int, Int>()
for i in 0 ..< NK[1] {
	if let val = window[c[i]] {
		window[c[i]] = val + 1
	} else {
		window[c[i]] = 1
	}
}
var ans = window.count
for i in NK[1] ..< NK[0] {
	if let val = window[c[i - NK[1]]] {
		window[c[i - NK[1]]] = val - 1
	}
	if let val = window[c[i]] {
		window[c[i]] = val + 1
	} else {
		window[c[i]] = 1
	}
	if let val = window[c[i - NK[1]]], val == 0 {
		window.removeValue(forKey: c[i - NK[1]])
	}
	ans = max(ans, window.count)
}
print(ans)