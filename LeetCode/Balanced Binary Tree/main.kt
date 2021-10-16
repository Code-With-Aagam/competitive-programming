/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    private fun isBalancedRecursive(root: TreeNode?): Int {
        if (root == null) return 0
        val lh = isBalancedRecursive(root.left)
        val rh = isBalancedRecursive(root.right)
        if (lh == -1 || rh == -1) return -1
        if (Math.abs(lh - rh) > 1) return -1
        return 1 + Math.max(lh, rh)
    }
    
    fun isBalanced(root: TreeNode?): Boolean {
        return isBalancedRecursive(root) != -1
    }
}