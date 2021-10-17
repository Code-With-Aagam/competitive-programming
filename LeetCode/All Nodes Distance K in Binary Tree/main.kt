/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {

    val parent = HashMap<TreeNode, TreeNode>()

    private fun populateParent(root: TreeNode?) {
        if (root == null) return
        root.left?.let {
            parent[it] = root
            populateParent(it)
        }
        root.right?.let {
            parent[it] = root
            populateParent(it)
        }
    }

    fun distanceK(root: TreeNode?, target: TreeNode?, k: Int): List<Int> {
        val ans = ArrayList<Int>()
        if (target == null) return ans
        parent.clear()
        populateParent(root)
        val q: Queue<Pair<TreeNode, Int>> = LinkedList()
        q.add(Pair(target, k))
        val visited = HashSet<TreeNode>()
        while (q.isNotEmpty()) {
            val curr = q.remove()
            val node = curr.first
            val level = curr.second
            if (visited.contains(node)) continue
            if (level == 0) ans.add(node.`val`)
            visited.add(node)
            node.left?.let {
                q.add(Pair(it, level - 1))
            }
            node.right?.let {
                q.add(Pair(it, level - 1))
            }
            parent[node]?.let { 
                q.add(Pair(it, level - 1))
            }
        }
        return ans
    }
}