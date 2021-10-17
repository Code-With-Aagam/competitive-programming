/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
extension TreeNode: Hashable {
	public static func == (lhs: TreeNode, rhs: TreeNode) -> Bool {
		return lhs === rhs
	}
	
	public func hash(into hasher: inout Hasher) {
		hasher.combine(193)
	}
}

class Solution {
	
	private var parent = [TreeNode : TreeNode]()
	
	private func populateParents(_ root: TreeNode) {
		if let left = root.left {
			parent[left] = root
			populateParents(left)
		}
		if let right = root.right {
			parent[right] = root
			populateParents(right)
		}
	}
	
	func distanceK(_ root: TreeNode?, _ target: TreeNode?, _ k: Int) -> [Int] {
		parent = [TreeNode : TreeNode]()
		var ans = [Int]()
		if let root = root, let target = target {
			populateParents(root)
			var q = [(TreeNode, Int)]()
			q.append((target, k))
			var visited = Set<TreeNode>()
			while !q.isEmpty {
				let curr = q.removeFirst()
				let node = curr.0
				let level = curr.1
				if visited.contains(node) {
					continue
				}
				visited.insert(node)
				if level == 0 {
					ans.append(node.val)
					continue
				}
				if let left = node.left {
					q.append((left, level - 1))
				}
				if let right = node.right {
					q.append((right, level - 1))
				}
				if let above = parent[node] {
					q.append((above, level - 1))
				}
			}
			return ans
		} else {
			return ans
		}
	}
}
