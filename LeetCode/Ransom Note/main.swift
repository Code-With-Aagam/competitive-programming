class Solution {
	func canConstruct(_ ransomNote: String, _ magazine: String) -> Bool {
		var freq = [Int](repeating: 0, count: 26)
		magazine.forEach {
			freq[$0.intValue] += 1
		}
		ransomNote.forEach {
			freq[$0.intValue] -= 1
		}
		return freq.filter { $0 < 0 }.isEmpty
	}
}

extension Character {
	var intValue: Int {
		return Int(self.asciiValue ?? 0) - Int(Character("a").asciiValue ?? 0)
	}
}
