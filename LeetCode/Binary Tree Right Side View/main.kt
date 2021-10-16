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
    fun rightSideView(root: TreeNode?): List<Int> {
        val ans = ArrayList<Int>()
        if (root == null) return ans
        val q: Queue<TreeNode> = LinkedList()
        q.add(root)
        while (q.isNotEmpty()) {
            val len = q.size
            var rightMostElement = -1
            repeat(len) {
                val node = q.remove()
                rightMostElement = node.`val`
                node.left?.let {
                    q.add(it)
                }
                node.right?.let {
                    q.add(it)
                }
            }
            ans.add(rightMostElement)
        }
        return ans
    }
}