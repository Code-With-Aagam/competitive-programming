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
    fun inorderTraversal(node: TreeNode?): List<Int> {
        var ans = ArrayList<Int>()
        if (node == null) return ans
        var st = Stack<TreeNode>()
        var root = node
        while (root != null || st.isNotEmpty()) {
            while (root != null) {
                st.add(root!!)
                root = root.left
            }
            root = st.pop()
            ans.add(root.`val`)
            root = root.right
        }
        return ans
    }
}