extension Character {
	private var asciiValueNormalised: Int {
		return Int(self.asciiValue ?? UInt8(0))
	}
    
    var integerValue: Int {
        return self.asciiValueNormalised - Character("a").asciiValueNormalised
    }
}

class Solution {
    func areOccurrencesEqual(_ s: String) -> Bool {
        var freq = [Int](repeating: 0, count: 26)
        s.forEach { freq[$0.integerValue] += 1 }
        var ans = Set<Int>()
        freq.forEach {
            if ($0 > 0) {
                ans.insert($0)
            }
        }
        return ans.count == 1
    }
}