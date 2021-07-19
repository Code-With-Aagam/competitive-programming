class Solution {
    fun lowestCommonAncestor(
        r: TreeNode?,
        p: TreeNode?,
        q: TreeNode?
    ): TreeNode? {
        var root = r
        while (root != null) {
            root = if (p?.`val` ?: 0 > root.`val`
                && q?.`val` ?: 0 > root.`val`
            ) {
                root.right
            } else if (p?.`val` ?: 0 < root.`val`
                && q?.`val` ?: 0 < root.`val`
            ) {
                root.left
            } else {
                return root
            }
        }
        return root
    }
}