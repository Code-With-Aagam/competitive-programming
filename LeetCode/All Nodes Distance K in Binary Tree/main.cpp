/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	map<TreeNode*, TreeNode*> parent;

	void populateParent(TreeNode *root) {
		if (root == nullptr) return;
		if (root -> left != nullptr) {
			parent[root -> left] = root;
			populateParent(root -> left);
		}
		if (root -> right != nullptr) {
			parent[root -> right] = root;
			populateParent(root -> right);
		}
	}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		parent.clear();
		populateParent(root);
		queue<pair<TreeNode*, int>> q;
		vector<int> ans;
		set<TreeNode*> visited;
		q.push(make_pair(target, k));
		while (!q.empty()) {
			auto [node, curr] = q.front();
			q.pop();
			if (visited.count(node) > 0) continue;
			if (curr == 0) ans.push_back(node -> val);
			visited.insert(node);
			if (node -> left != nullptr) q.push(make_pair(node -> left, curr - 1));
			if (node -> right != nullptr) q.push(make_pair(node -> right, curr - 1));
			if (parent[node] != nullptr) q.push(make_pair(parent[node], curr - 1));
		}
		return ans;
    }
};