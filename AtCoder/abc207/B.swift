
private func readLn() -> String {
	return readLine()!
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

private func readLong() -> Int64 {
	return Int64(readLn()) ?? Int64(0)
}

private func readLongs() -> [Int64] {
	return readLns().compactMap{ Int64($0) }
}

private func readDouble() -> Double {
	return Double(readLn()) ?? Double(0)
}

private func readDoubles() -> [Double] {
	return readLns().compactMap{ Double($0) }
}

var arr = readDoubles()
let den = arr[2] * arr[3] - arr[1]
if den <= 0 {
	print(-1)
} else {
	let ans = arr[0] / den
	print(ans.roundedUp)
}

extension Double {
	var roundedUp: Int {
		let ans = Int(self)
		if self - Double(ans) > 0.0 {
			return ans + 1
		} else {
			return ans
		}
	}
}
