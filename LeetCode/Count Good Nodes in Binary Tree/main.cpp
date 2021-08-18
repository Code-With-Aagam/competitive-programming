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
    int goodNodes(TreeNode* root, int val) {
        if (root == nullptr) return 0;
        val = max(val, root->val);
        int ans = goodNodes(root->left, val) + goodNodes(root->right, val);
        if (root->val >= val) ++ans;
        return ans;
    }

   public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};