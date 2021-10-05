/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }
        var ans = [[Int]]()
        var q = [TreeNode]()
        q.append(root)
        var leftToRight = true
        while !q.isEmpty {
            var size = q.count
            var level = [Int]()
            while size > 0 {
                let curr = q.removeFirst()
                level.append(curr.val)
                if let left = curr.left {
                    q.append(left)
                }
                if let right = curr.right {
                    q.append(right)
                }
                size -= 1
            }
            ans.append(leftToRight ? level : level.reversed())
            leftToRight.toggle()
        }
        return ans
    }
}