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
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var ans = [Int]()
        if let root = root {
            var st = [TreeNode]()
            st.append(root)
            while !st.isEmpty {
                let node = st.removeLast()
                ans.append(node.val)
                if let right = node.right {
                    st.append(right)
                }
                if let left = node.left {
                    st.append(left)
                }
            }
        }
        return ans
    }
}