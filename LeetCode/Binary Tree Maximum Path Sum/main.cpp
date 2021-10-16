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
	int answer = 0;

	int maxPathSumRecursive(TreeNode *root) {
		if (root == nullptr) return 0;
		int ls = maxPathSumRecursive(root -> left);
		int rs = maxPathSumRecursive(root -> right);
		if (ls < 0) ls = 0;
		if (rs < 0) rs = 0;
		answer = max(answer, ls + rs + root -> val);
		return root -> val + max(ls, rs);
	}
public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
		maxPathSumRecursive(root);
		return answer;
    }
};