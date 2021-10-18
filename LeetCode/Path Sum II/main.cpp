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
    vector<vector<int>> allPaths;

    void pathSumRecursive(TreeNode* root, vector<int> &path, int targetSum) {
        if (root == nullptr) {
            return;
        }
        if (root -> left == nullptr and root -> right == nullptr) {
            path.push_back(root -> val);
            if (root -> val == targetSum) {
                allPaths.push_back(path);
            }
            path.pop_back();
            return;
        }
        path.push_back(root -> val);
        pathSumRecursive(root -> left, path, targetSum - root -> val);
        pathSumRecursive(root -> right, path, targetSum - root -> val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        allPaths.clear();
        pathSumRecursive(root, path, targetSum);
        return allPaths;
    }
};