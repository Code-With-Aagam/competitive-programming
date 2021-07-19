class Solution {
   public:
    TreeNode *lowestCommonAncestor(
        TreeNode *root,
        TreeNode *p,
        TreeNode *q) {
        while (root != nullptr) {
            if (p->val > root->val and q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val and q->val < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return root;
    }
};