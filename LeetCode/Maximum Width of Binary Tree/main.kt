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
    fun widthOfBinaryTree(root: TreeNode?): Int {
        if (root == null) return 0
        val q: Queue<Pair<TreeNode, Int>> = LinkedList()
        q.add(Pair(root, 1))
        var ans = 0
        while (q.isNotEmpty()) {
            val len = q.size
            val offset = q.peek().second
            var mx = Int.MIN_VALUE
            var mn = Int.MAX_VALUE
            repeat(len) {
                val curr = q.remove()
                val node = curr.first
                val level = curr.second - offset
                mx = Math.max(mx, level)
                mn = Math.min(mn, level)
                node.left?.let {
                    q.add(Pair(it, 2 * level))
                }
                node.right?.let {
                    q.add(Pair(it, 2 * level + 1))
                }
            }
            ans = Math.max(ans, mx - mn + 1)
        }
        return ans
    }
}