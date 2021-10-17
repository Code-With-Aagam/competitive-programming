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
	private func isBalancedRecursive(_ root: TreeNode?) -> Int {
		if let root = root {
			let lh = isBalancedRecursive(root.left)
			let rh = isBalancedRecursive(root.right)
			if lh == -1 || rh == -1 || abs(rh - lh) > 1 {
				return -1
			} else {
				return 1 + max(lh, rh)
			}
		} else {
			return 0
		}
	}
	
	func isBalanced(_ root: TreeNode?) -> Bool {
		return isBalancedRecursive(root) != -1
	}
}