class Solution {
	func partitionDisjoint(_ nums: [Int]) -> Int {
		let n = nums.count
		var (maxLeft, minRight) = (nums, nums)
		for i in 1 ..< n {
			maxLeft[i] = max(maxLeft[i - 1], nums[i])
		}
		for i in (0 ..< n - 1).reversed() {
			minRight[i] = min(minRight[i + 1], nums[i])
		}
		var ans = 0
		for i in 1 ..< n {
			if maxLeft[i - 1] <= minRight[i] {
				ans = i
				break
			}
		}
		return ans
	}
}