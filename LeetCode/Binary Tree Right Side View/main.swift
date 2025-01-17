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
	func rightSideView(_ root: TreeNode?) -> [Int] {
		var ans = [Int]()
		if let root = root {
			var q = [TreeNode]()
			q.append(root)
			while !q.isEmpty {
				var len = q.count
				var lastNode = -1
				while len > 0 {
					let node = q.removeFirst()
					lastNode = node.val
					if let left = node.left {
						q.append(left)
					}
					if let right = node.right {
						q.append(right)
					}
					len -= 1
				}
				ans.append(lastNode)
			}
			return ans
		} else {
			return ans
		}
	}
}
