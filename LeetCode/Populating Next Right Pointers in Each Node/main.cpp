/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        Node* curr = root;
        queue<Node*> q;
        q.push(curr);
        while (!q.empty()) {
            int len = q.size();
            vector<Node*> level;
            while (len--) {
                curr = q.front();
                q.pop();
                level.push_back(curr);
                if (curr -> left != nullptr) q.push(curr -> left);
                if (curr -> right != nullptr) q.push(curr -> right);
            }
            for (int i = 0; i < level.size() - 1; i++) {
                level[i] -> next = level[i + 1];
            }
        }
        return root;
    }
};