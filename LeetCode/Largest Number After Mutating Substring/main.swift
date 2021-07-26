extension Character {
	private var asciiValueNormalized: Int {
		return Int(self.asciiValue ?? 0)
	}
	
	var intValue: Int {
		return self.asciiValueNormalized - Character("0").asciiValueNormalized
	}
}

class Solution {
	func maximumNumber(_ N: String, _ change: [Int]) -> String {
		var num = Array(N)
		var i = 0
		while i < num.count && num[i].intValue >= change[num[i].intValue] {
			i += 1
		}
		while i < num.count && num[i].intValue <= change[num[i].intValue] {
			num[i] = Character(String(change[num[i].intValue]))
			i += 1
		}
		return String(num)
	}
}