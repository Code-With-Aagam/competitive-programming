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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<pair<TreeNode*, int>> st;
        vector<int> preorder, inorder, postorder;
        st.push(make_pair(root, 0));
        while (!st.empty()) {
            if (st.top().second == 0) {
                preorder.push_back(st.top().first->val);
                st.top().second++;
                if (st.top().first->left != nullptr) {
                    st.push(make_pair(st.top().first->left, 0));
                }
            } else if (st.top().second == 1) {
                inorder.push_back(st.top().first->val);
                st.top().second++;
                if (st.top().first->right != nullptr) {
                    st.push(make_pair(st.top().first->right, 0));
                }
            } else {
                postorder.push_back(st.top().first->val);
                st.pop();
            }
        }
        return inorder;
    }
};