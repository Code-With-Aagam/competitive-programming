extension Character {
	private var asciiValueNormalized: Int {
		return Int(self.asciiValue ?? 0)
	}
	
	var intValue: Int {
		return self.asciiValueNormalized - Character("a").asciiValueNormalized
	}
}

class Solution {
	func getLucky(_ s: String, _ k: Int) -> Int {
		var nums = [Int]()
		s.forEach { ch in
			var ele = ch.intValue + 1
			while ele > 0 {
				nums.append(ele % 10)
				ele /= 10
			}
		}
		for _ in 0 ..< k {
			var ele = 0
			nums.forEach { ele += $0 }
			nums.removeAll()
			while ele > 0 {
				nums.append(ele % 10)
				ele /= 10
			}
		}
		var ans = ""
		nums.reversed().forEach { ans += String($0) }
		return Int(ans) ?? 0
	}
}