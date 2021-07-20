class Solution {
	private let originalArray: [Int]
	private let size: Int
	private var random: RandomNumberGenerator
	
	init(_ nums: [Int]) {
		self.originalArray = nums
		self.size = nums.count
		self.random = SystemRandomNumberGenerator()
	}
	
	func reset() -> [Int] {
		return self.originalArray
	}
	
	func shuffle() -> [Int] {
		var shuffledArray = originalArray
		for i in 1 ..< size {
			let j = Int(UInt64(random.next()) % UInt64(i + 1))
			shuffledArray.swapAt(i, j)
		}
		return shuffledArray
	}
}