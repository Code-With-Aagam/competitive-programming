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
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        var (ans, q) = ([[Int]](), [TreeNode]())
		guard let root = root else { return ans }
		q.append(root)
		while (!q.isEmpty) {
			var (curr, cnt) = ([Int](), q.count)
			while (cnt > 0) {
				let node = q.removeFirst()
				curr.append(node.val)
				if let left = node.left {
					q.append(left)
				}
				if let right = node.right {
					q.append(right)
				}
				cnt -= 1
			}
			ans.append(curr)
		}
		return ans.reversed()
    }
}