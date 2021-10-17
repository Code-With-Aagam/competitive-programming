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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1ULL));
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            int mx = INT_MIN, mn = INT_MAX;
            int offset = q.front().second;
            while (len--) {
                auto [node, level] = q.front();
                q.pop();
                level -= offset;
                mx = max(mx, level);
                mn = min(mn, level);
                if (node -> left != nullptr) {
                    q.push(make_pair(node -> left, 2 * level));
                }
                if (node -> right != nullptr) {
                    q.push(make_pair(node -> right, 2 * level + 1));
                }
            }
            ans = max(ans, mx - mn + 1);
        }
        return ans;
    }
};