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
    vector<string> ans;

    void allPaths(TreeNode* root, string path) {
        if (root == nullptr) return;
        if (root -> left == nullptr and root -> right == nullptr) {
            path += to_string(root -> val);
            ans.push_back(path);
            return;
        }
        path += to_string(root -> val) + "->";
        allPaths(root -> left, path);
        allPaths(root -> right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        allPaths(root, "");
        return ans;        
    }
};