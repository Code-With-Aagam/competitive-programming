/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
	ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
        	l1->next = mergeTwoLists(l1->next, l2);
        	return l1;
        } else {
        	l2->next = mergeTwoLists(l1, l2->next);
        	return l2;
        }
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* ans = dummyNode;
        while (l1 != nullptr && l2 != nullptr) {
        	if (l1->val < l2->val) {
        		dummyNode->next = new ListNode(l1->val);
        		l1 = l1->next;
        	} else {
        		dummyNode->next = new ListNode(l2->val);
        		l2 = l2->next;
        	}
        	dummyNode = dummyNode->next;
        }
        if (l1 != nullptr) dummyNode->next = l1;
        if (l2 != nullptr) dummyNode->next = l2;
        return ans->next;
    }
};