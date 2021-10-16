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

    private fun maxPathSumRecursive(root: TreeNode?): Int {
        if (root == null) return 0
        var ls = maxPathSumRecursive(root.left)
        var rs = maxPathSumRecursive(root.right)
        if (ls < 0) ls = 0
        if (rs < 0) rs = 0
        answer = Math.max(answer, root.`val` + ls + rs)
        return root.`val` + Math.max(ls, rs)
    }

    fun maxPathSum(root: TreeNode?): Int {
        answer = Int.MIN_VALUE
        maxPathSumRecursive(root)
        return answer
    }
}