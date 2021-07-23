class Solution {
   public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return (root->val == 0 && root->left == nullptr && root->right == nullptr) ? nullptr : root;
    }
};