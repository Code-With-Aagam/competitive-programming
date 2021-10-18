/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
	
	private var mp = [Int : Int]()
	private var ans = 0
	
	private func pathSumRecursive(_ root: TreeNode?, _ targetSum: Int, _ currentSum: Int) {
		if let root = root {
			ans += mp[currentSum + root.val - targetSum] ?? 0
			mp[currentSum + root.val] = (mp[currentSum + root.val] ?? 0) + 1
			pathSumRecursive(root.left, targetSum, currentSum + root.val)
			pathSumRecursive(root.right, targetSum, currentSum + root.val)
			mp[currentSum + root.val] = (mp[currentSum + root.val] ?? 0) - 1
		}
	}
	
	func pathSum(_ root: TreeNode?, _ targetSum: Int) -> Int {
		mp = [Int : Int]()
		ans = 0
		mp[0] = 1
		pathSumRecursive(root, targetSum, 0)
		return ans
	}
}
