/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    queue<Tree*> q;
    vector<int> ans;
    if (root == nullptr) return ans;
    q.push(root);
    while (!q.empty()) {
        auto size = q.size();
        while (size--) {
            auto curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    return ans;
}