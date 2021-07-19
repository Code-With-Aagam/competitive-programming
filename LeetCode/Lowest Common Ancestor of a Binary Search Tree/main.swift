class Solution {
	func lowestCommonAncestor(
		_ r: TreeNode?,
		_ p: TreeNode?,
		_ q: TreeNode?
	) -> TreeNode? {
		var root = r
		while root != nil {
			if p?.val ?? 0 > root?.val ?? 0
				&& q?.val ?? 0 > root?.val ?? 0 {
				root = root?.right
			} else if p?.val ?? 0 < root?.val ?? 0
						&& q?.val ?? 0 < root?.val ?? 0 {
				root = root?.left
			} else {
				return root
			}
		}
		return root
	}
}