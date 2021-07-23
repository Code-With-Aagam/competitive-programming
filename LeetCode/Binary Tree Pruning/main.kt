class Solution {
    fun pruneTree(root: TreeNode?): TreeNode? {
        return if (root == null) {
            null
        } else {
            root.left = pruneTree(root.left)
            root.right = pruneTree(root.right)
            return if (root.`val` == 0 
                    && root.left == null 
                    && root.right == null) {
                null
            } else {
                root
            }
        }
    }
}