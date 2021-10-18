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

    private var allPaths = ArrayList<ArrayList<Int>>()
    private var path = ArrayList<Int>()

    private fun pathSumRecursive(root: TreeNode?, targetSum: Int) {
        if (root == null) return
        if (root.left == null && root.right == null) {
            path.add(root.`val`)
            if (targetSum == root.`val`) {
                allPaths.add(ArrayList(path))
            }
            path.remove(root.`val`)
            return
        }
        path.add(root.`val`)
        pathSumRecursive(root.left, targetSum - root.`val`)
        pathSumRecursive(root.right, targetSum - root.`val`)
        path.remove(root.`val`)
    }

    fun pathSum(root: TreeNode?, targetSum: Int): List<List<Int>> {
        allPaths.clear()
        path.clear()
        pathSumRecursive(root, targetSum)
        return allPaths
    }
}