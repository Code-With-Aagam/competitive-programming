/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
	Node* flatten(Node* head) {
		Node* curr = head;
		stack<Node*> st;
		while (curr != nullptr || !st.empty()) {
			if (curr -> child != nullptr) {
				if (curr -> next != nullptr) {
					st.push(curr -> next);
				}
				curr -> next = curr -> child;
				curr -> next -> prev = curr;
				curr -> child = nullptr;
			} else {
				if (curr -> next == nullptr && !st.empty()) {
					curr -> next = st.top();
					st.pop();
					curr -> next -> prev = curr;
				}
			}
			curr = curr -> next;
		}
		return head;
	}
};