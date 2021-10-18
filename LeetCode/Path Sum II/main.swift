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
	
	private var allPaths = [[Int]]()
	private var path = [Int]()
	
	private func pathSumRecursive(_ root: TreeNode?, _ target: Int) {
		if let root = root {
			if root.left == nil && root.right == nil {
				path.append(root.val)
				if target == root.val {
					allPaths.append(path)
				}
				path.removeLast()
			} else {
				path.append(root.val)
				pathSumRecursive(root.left, target - root.val)
				pathSumRecursive(root.right, target - root.val)
				path.removeLast()
			}
		}
	}
	
	func pathSum(_ root: TreeNode?, _ targetSum: Int) -> [[Int]] {
		allPaths = [[Int]]()
		path = [Int]()
		pathSumRecursive(root, targetSum)
		return allPaths
	}
}
