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
    fun verticalTraversal(root: TreeNode?): List<List<Int>> {
        val answer = ArrayList<ArrayList<Int>>()
        if (root == null) return answer
        val q: Queue<Pair<TreeNode, Pair<Int, Int>>> = LinkedList()
        val mp = TreeMap<Int, TreeMap<Int, ArrayList<Int>>>()
        q.add(Pair(root, Pair(0, 0)))
        while (q.isNotEmpty()) {
            val curr = q.remove()
            val node = curr.first
            val line = curr.second.first
            val level = curr.second.second
            if (!mp.containsKey(line)) {
                mp[line] = TreeMap()
            }
            if (mp[line]?.containsKey(level) == false) {
                mp[line]?.set(level, ArrayList())
            }
            mp[line]?.get(level)?.add(node.`val`)
            node.left?.let {
                q.add(Pair(it, Pair(line - 1, level + 1)))
            }
            node.right?.let {
                q.add(Pair(it, Pair(line + 1, level + 1)))
            }
        }
        mp.values.forEach {
            val curr = ArrayList<Int>()
            it.values.forEach {
                it.sorted().forEach {
                    curr.add(it)
                }
            }
            answer.add(curr)
        }
        return answer
    }
}