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
class BSTIterator {
    vector<int> arr;
    int index = 0, len;

    void solve(const TreeNode* root) {
        if (root == nullptr) return;
        solve(root -> left);
        arr.push_back(root -> val);
        solve(root -> right);
    }
public:
    BSTIterator(TreeNode* root) {
        solve(root);
        index = 0;
        len = arr.size();
    }
    
    int next() {
        return arr[index++];
    }
    
    bool hasNext() {
        return index < len;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */