class Solution {
	func pruneTree(_ root: TreeNode?) -> TreeNode? {
		guard var root = root else { return nil }
		root.left = pruneTree(root.left)
		root.right = pruneTree(root.right)
		return root.val == 0 
            && root.left == nil 
            && root.right == nil ? nil : root
	}
}