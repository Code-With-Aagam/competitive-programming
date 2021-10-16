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

    var answer = 0

    private fun diameterOfBinaryTreeRecursive(root: TreeNode?): Int {
        if (root == null) return 0
        val lh = diameterOfBinaryTreeRecursive(root.left)
        val rh = diameterOfBinaryTreeRecursive(root.right)
        answer = Math.max(answer, lh + rh)
        return 1 + Math.max(lh, rh)
    }

    fun diameterOfBinaryTree(root: TreeNode?): Int {
        answer = 0
        diameterOfBinaryTreeRecursive(root)
        return answer
    }
}