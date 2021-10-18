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
    unordered_map<int, int> mp;
    int ans = 0;

    void pathSumRecursive(TreeNode* root, int target, int curr) {
        if (root == nullptr) return;
        curr += root->val;
        ans += mp[curr - target];
        mp[curr]++;
        pathSumRecursive(root -> left, target, curr);
        pathSumRecursive(root -> right, target, curr);
        mp[curr]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp.clear();      
        ans = 0;
        mp[0] = 1;
        pathSumRecursive(root, targetSum, 0);
        return ans;
    }
};