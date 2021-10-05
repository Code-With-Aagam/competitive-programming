class Solution {
    fun zigzagLevelOrder(root: TreeNode?): List<List<Int>> {
        val q = LinkedList<TreeNode>()
        val ans = mutableListOf<List<Int>>()
        if (root == null) return ans
        q.push(root)
        var leftToRight = true
        while (q.isNotEmpty()) {
            val size = q.size
            val level = mutableListOf<Int>()
            repeat(size) {
                val curr = q.removeFirst()
                level.add(curr.`val`)
                curr.left?.let {
                    q.add(it)
                }
                curr.right?.let {
                    q.add(it)
                }
            }
            ans.add(if (leftToRight) level else level.reversed())
            leftToRight = leftToRight.not()
        }
        return ans
    }
}