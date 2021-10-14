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
    fun levelOrderBottom(root: TreeNode?): List<List<Int>> {
        val ans = ArrayList<ArrayList<Int>>()
        if (root == null) return ans
        val q = LinkedList<TreeNode>()
        q.add(root)
        while (!q.isEmpty()) {
            val curr = ArrayList<Int>()
            var cnt = q.size
            while (cnt > 0) {
                val node = q.poll()
                node?.`val`?.let { curr.add(it) }
                node?.left?.let { q.add(it) }
                node?.right?.let { q.add(it) }
                cnt--
            }
            ans.add(curr)
        }
        return ans.reversed()
    }
}