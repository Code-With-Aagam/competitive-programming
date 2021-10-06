/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, vector<string>& moves) {
    vector<Tree*> parents;
    pair<Tree*, vector<Tree*>> curr = make_pair(root, parents);
    for (const auto &ele : moves) {
        if (ele == "LEFT") {
            auto node = curr.first;
            auto parents = curr.second;
            parents.push_back(node);
            node = node->left;
            curr = make_pair(node, parents);
        } else if (ele == "RIGHT") {
            auto node = curr.first;
            auto parents = curr.second;
            parents.push_back(node);
            node = node->right;
            curr = make_pair(node, parents);
        } else {
            auto parents = curr.second;
            auto node = parents.back();
            parents.pop_back();
            curr = make_pair(node, parents);
        }
    }
    return curr.first->val;
}