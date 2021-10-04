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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
        	int size = q.size();
        	vector<int> level;
        	while (size--) {
        		auto curr = q.front();
                q.pop();
        		level.push_back(curr->val);
        		if (curr->left != nullptr) q.push(curr->left);
        		if (curr->right != nullptr) q.push(curr->right);
        	}
        	if (leftToRight) {
        		ans.push_back(level);
        	} else {
        		reverse(begin(level), end(level));
        		ans.push_back(level);
        	}
        	leftToRight = !leftToRight;
        }
        return ans;
    }
};