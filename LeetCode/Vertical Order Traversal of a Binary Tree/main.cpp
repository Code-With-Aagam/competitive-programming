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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
		queue<tuple<TreeNode*, int, int>> q;
		map<int, map<int, multiset<int>>> mp;
		if (root == nullptr) return answer;
		q.push(make_tuple(root, 0, 0));
		while (!q.empty()) {
			auto [node, line, level] = q.front();
			q.pop();
			mp[line][level].insert(node -> val);
			if (node -> left != nullptr) {
				q.push(make_tuple(node -> left, line - 1, level + 1));
			}
			if (node -> right != nullptr) {
				q.push(make_tuple(node -> right, line + 1, level + 1));
			}
		}
        for (const auto &level : mp) {
            auto levelValue = level.second;
            vector<int> curr;
            for (const auto &set : levelValue) {
                for (const auto &ele : set.second) {
                    curr.push_back(ele);
                }
            }
            answer.push_back(curr);
        }
		return answer;
    }
};