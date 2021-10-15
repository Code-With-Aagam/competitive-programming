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
    fun preorderTraversal(root: TreeNode?): List<Int> {
        var ans = ArrayList<Int>()
        root?.let {
            var st = Stack<TreeNode>()
            st.push(it)
            while (st.isNotEmpty()) {
                val node = st.pop()
                ans.add(node.`val`)
                node.right?.let {
                    st.push(it)
                }
                node.left?.let {
                    st.push(it)
                }
            }
        }
        return ans
    }
}