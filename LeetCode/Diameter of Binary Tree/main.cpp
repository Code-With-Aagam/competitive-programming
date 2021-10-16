/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int diameter;

    int diameterOfBinaryTreeRecursive(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = diameterOfBinaryTreeRecursive(root -> left);
        int rh = diameterOfBinaryTreeRecursive(root -> right);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        diameterOfBinaryTreeRecursive(root);
        return diameter;
    }
};