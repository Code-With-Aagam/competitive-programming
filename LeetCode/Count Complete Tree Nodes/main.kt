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
    fun countNodes(root: TreeNode?): Int {
        if (root == null) return 0
        val leftHeight = getHeightLeft(root)
        val rightHeight = getHeightRight(root)
        val two = 2
        return if (leftHeight == rightHeight) {
            two.shl(leftHeight) - 1
        } else {
            1 + countNodes(root.left) + countNodes(root.right)
        }
    }

    private fun getHeightRight(root: TreeNode): Int {
        var ans = 0;
        var node: TreeNode = root
        while (node.right != null) {
            ++ans
            node = node.right!!
        }
        return ans
    }

    private fun getHeightLeft(root: TreeNode): Int {
        var ans = 0;
        var node: TreeNode = root
        while (node.left != null) {
            ++ans
            node = node.left!!
        }
        return ans
    }
}