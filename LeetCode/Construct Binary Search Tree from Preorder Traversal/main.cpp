#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* build(const vector<int> &arr, int lo, int hi) {
        if (lo > hi) return nullptr;
        TreeNode* root = new TreeNode(arr[lo]);
        int x = lo + 1;
        while (x <= hi && arr[x] < arr[lo]) x++;
        root -> left = build(arr, lo + 1, x - 1);
        root -> right = build(arr, x, hi);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};