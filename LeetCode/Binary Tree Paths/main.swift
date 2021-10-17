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
	
	private var ans = [String]()
	
	private func solve(_ root: TreeNode?, _ path: String) {
		if let root = root {
			if root.left == nil && root.right == nil {
				ans.append("\(path)\(root.val)")
			} else {
				solve(root.left, "\(path)\(root.val)->")
				solve(root.right, "\(path)\(root.val)->")
			}
		} else {
			return
		}
	}
	
	func binaryTreePaths(_ root: TreeNode?) -> [String] {
		ans = [String]()
		solve(root, "")
		return ans
	}
}
