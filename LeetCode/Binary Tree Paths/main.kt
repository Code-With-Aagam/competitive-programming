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

    private var ans = ArrayList<String>()

    private fun allPaths(root: TreeNode?, path: String) {
        if (root == null) return
        if (root.left == null && root.right == null) {
            ans.add(path + root.`val`.toString())
            return
        }
        val newPath = path + root.`val`.toString() + "->"
        allPaths(root.left, newPath)
        allPaths(root.right, newPath)
    }

    fun binaryTreePaths(root: TreeNode?): List<String> {
        ans.clear()
        allPaths(root, "")
        return ans
    }
}