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

    private var mp = HashMap<Int, Int>()
    private var ans = 0

    private fun pathSumRecursive(root: TreeNode?, targetSum: Int, currentSum: Int) {
        if (root == null) return
        ans += mp.getOrDefault(currentSum + root.`val` - targetSum, 0)
        mp[currentSum + root.`val`] = mp.getOrDefault(currentSum + root.`val`, 0) + 1
        pathSumRecursive(root.left, targetSum, currentSum + root.`val`)
        pathSumRecursive(root.right, targetSum, currentSum + root.`val`)
        mp[currentSum + root.`val`] = mp.getOrDefault(currentSum + root.`val`, 0) - 1
    }

    fun pathSum(root: TreeNode?, targetSum: Int): Int {
        mp.clear()
        ans = 0
        mp[0] = 1
        pathSumRecursive(root, targetSum, 0)
        return ans
    }
}