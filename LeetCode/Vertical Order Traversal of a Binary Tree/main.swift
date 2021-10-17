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
	func verticalTraversal(_ root: TreeNode?) -> [[Int]] {
		var ans = [[Int]]()
		if let root = root {
			var q = [(TreeNode, Int, Int)]()
			var mp = Dictionary<Int, Dictionary<Int, [Int]>>()
			q.append((root, 0, 0))
			while !q.isEmpty {
				let curr = q.removeFirst()
				let node = curr.0
				let line = curr.1
				let level = curr.2
				if !mp.keys.contains(line) {
					mp[line] = Dictionary<Int, [Int]>()
				}
				if mp[line]?.keys.contains(level) == false {
					mp[line]?[level] = [Int]()
				}
				mp[line]?[level]?.append(node.val)
				if let left = node.left {
					q.append((left, line - 1, level + 1))
				}
				if let right = node.right {
					q.append((right, line + 1, level + 1))
				}
			}
			mp.sorted(by: { $0.key < $1.key }).forEach { lineKeyValues in
				var curr = [Int]()
				lineKeyValues.value.sorted(by: { $0.key < $1.key }).forEach { levelKeyValue in
					curr += levelKeyValue.value.sorted()
				}
				ans.append(curr)
			}
			return ans
		} else {
			return ans
		}
	}
}
