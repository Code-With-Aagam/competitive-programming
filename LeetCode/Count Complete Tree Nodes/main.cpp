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
    int getHeightLeft(TreeNode* root) {
        int ans = 0;
        while (root -> left != nullptr) {
            ++ans;
            root = root -> left;
        }
        return ans;
    }

    int getHeightRight(TreeNode* root) {
        int ans = 0;
        while (root -> right != nullptr) {
            ++ans;
            root = root -> right;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = getHeightLeft(root);
        int rightHeight = getHeightRight(root);
        if (leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;
        } else {
            return 1 + countNodes(root -> left) + countNodes(root -> right);
        }
    }
};