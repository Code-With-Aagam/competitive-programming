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
private:
	bool check(TreeNode *left, TreeNode *right) {
		if (left == nullptr || right == nullptr) return left == right;
		if (left -> val != right -> val) return false;
		return check(left -> right, right -> left) and check(left -> left, right -> right);
	}
public:
    bool isSymmetric(TreeNode* root) {
		return check(root, root);
    }
};