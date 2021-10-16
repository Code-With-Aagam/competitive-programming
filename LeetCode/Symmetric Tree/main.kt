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

    private fun check(left: TreeNode?, right: TreeNode?): Boolean {
        if (left == null || right == null) return left == right
        if (left.`val` != right.`val`) return false
        return check(left.right, right.left) && check(left.left, right.right)
    }

    fun isSymmetric(root: TreeNode?): Boolean {
        return check(root, root)
    }
}