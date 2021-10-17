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
	
	private var ans = 0
	
	private func solve(_ root: TreeNode?) -> Int {
		if let root = root {
			let lh = solve(root.left)
			let rh = solve(root.right)
			ans = max(ans, lh + rh)
			return 1 + max(lh, rh)
		} else {
			return 0
		}
	}
	
	func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
		ans = 0
		solve(root)
		return ans
	}
}
