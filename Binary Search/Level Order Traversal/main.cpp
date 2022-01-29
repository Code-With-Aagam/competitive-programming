/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree *root) {
	vector<int> ans;
	if (root == nullptr) return ans;
	queue<Tree*> q;
	q.push(root);
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			auto node = q.front();
			q.pop();
			ans.push_back(node->val);
			if (node -> left != nullptr) {
				q.push(node -> left);
			}
			if (node -> right != nullptr) {
				q.push(node -> right);
			}
		}
	}
	return ans;
}