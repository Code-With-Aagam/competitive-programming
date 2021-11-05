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
    int ans = 0;

    void dfs(TreeNode* root, bool left) {
        if (root == nullptr) return;
        if (root -> left == nullptr && root -> right == nullptr && left) ans += root -> val;
        dfs(root -> right, false);
        dfs(root -> left, true);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        dfs(root, false);
        return ans;
    }
};