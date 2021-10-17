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
	
	private var ans = Int.min
	
	private func solve(_ root: TreeNode?) -> Int {
		if let root = root {
			var ls = solve(root.left)
			var rs = solve(root.right)
			if ls < 0 {
				ls = 0
			}
			if rs < 0 {
				rs = 0
			}
			ans = max(ans, root.val + ls + rs)
			return root.val + max(ls, rs)
		} else {
			return 0
		}
	}
	
	func maxPathSum(_ root: TreeNode?) -> Int {
		ans = Int.min
		solve(root)
		return ans
	}
}