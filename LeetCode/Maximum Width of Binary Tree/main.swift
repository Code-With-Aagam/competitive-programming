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
	func widthOfBinaryTree(_ root: TreeNode?) -> Int {
		if let root = root {
			var q = [(TreeNode, Int)]()
			var ans = 0
			q.append((root, 1))
			while !q.isEmpty {
				var len = q.count
				var mx = Int.min
				var mn = Int.max
				let offset = q.first?.1 ?? 0
				while len > 0 {
					let curr = q.removeFirst()
					let node = curr.0
					let level = curr.1 - offset
					mx = max(mx, level)
					mn = min(mn, level)
					if let left = node.left {
						q.append((left, 2 * level))
					}
					if let right = node.right {
						q.append((right, 2 * level + 1))
					}
					len -= 1
				}
				ans = max(ans, mx - mn + 1)
			}
			return ans
		} else {
			return 0
		}
	}
}
