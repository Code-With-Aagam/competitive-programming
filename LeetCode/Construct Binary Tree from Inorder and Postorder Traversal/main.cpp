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
    vector<int> inorder, postorder;
    int N;
    unordered_map<int, int> mp;

    TreeNode* buildTree(int currentIndex, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(postorder[currentIndex]);
        int mid = mp[root -> val];
        root -> left = buildTree(currentIndex - 1, start, mid - 1);
        root -> right = buildTree(currentIndex - 1, mid + 1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this -> inorder = inorder;
        this -> postorder = postorder;
        this -> N = inorder.size();
        this -> mp.clear();
        for (int i = 0; i < N; ++i) mp[inorder[i]] = i;
        return buildTree(N - 1, 0, N - 1);
    }
};