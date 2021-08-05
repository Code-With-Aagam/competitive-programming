class Solution {
    void pathSumRecursive(vector<vector<int>> &ans, vector<int> path, TreeNode *root, int targetSum, int currentSum) {
        if (root == nullptr) return;
        currentSum += root->val;
        path.push_back(root->val);
        if (currentSum == targetSum && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }
        pathSumRecursive(ans, path, root->left, targetSum, currentSum);
        pathSumRecursive(ans, path, root->right, targetSum, currentSum);
    }

   public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        pathSumRecursive(result, path, root, targetSum, 0);
        return result;
    }
};