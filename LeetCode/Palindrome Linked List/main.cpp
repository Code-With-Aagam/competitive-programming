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
	ListNode* findMiddleNode(ListNode* head) {
		if (head == nullptr && head->next == nullptr) return head;
		ListNode* slow = head, *fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* curr = head, *prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
	}

public:
    bool isPalindrome(ListNode* head) {
    	ListNode* middleNode = findMiddleNode(head);
    	ListNode* reverseHead = reverseList(middleNode);
    	while (reverseHead != nullptr) {
    		if (head->val != reverseHead->val) return false;
    		head = head->next;
    		reverseHead = reverseHead->next;
    	}
    	return true;
    }
};