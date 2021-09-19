private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readDoubles() -> [Double] {
	return readLns().compactMap{ Double($0) }
}

let ab = readDoubles()
let ans = ((ab[0] - ab[1]) / 3.0) + ab[1]
print(ans)