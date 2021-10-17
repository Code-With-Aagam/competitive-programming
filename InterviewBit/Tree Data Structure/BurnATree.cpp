/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<TreeNode*, TreeNode*> parent;
TreeNode* targetNode;
int target;

void populateParent(TreeNode* root) {
    if (root == nullptr) return;
    if (root -> val == target) targetNode = root;
    if (root -> left != nullptr) {
        parent[root -> left] = root;
        populateParent(root -> left);
    }
    if (root -> right != nullptr) {
        parent[root -> right] = root;
        populateParent(root -> right);
    }
}

int Solution::solve(TreeNode* A, int B) {
    parent.clear();
    targetNode = nullptr;
    target = B;
    populateParent(A);
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(targetNode, 0));
    int ans = 0;
    set<TreeNode*> visited;
    while (!q.empty()) {
        auto [node, curr] = q.front();
        q.pop();
        if (visited.count(node) > 0) continue;
        visited.insert(node);
        ans = max(ans, curr);
        if (node -> left != nullptr) q.push(make_pair(node -> left, curr + 1));
        if (node -> right != nullptr) q.push(make_pair(node -> right, curr + 1));
        if (parent[node] != nullptr) q.push(make_pair(parent[node], curr + 1));
    }
    return ans;
}
