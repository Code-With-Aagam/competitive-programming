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
	ListNode* reverseList(ListNode* head) {
		ListNode* curr = head, *prev = nullptr;
		while (curr != nullptr) {
			ListNode* node = curr->next;
			curr->next = prev;
			prev = curr;
			curr = node;
		}
		return prev;
	}
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
        	prev = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* revHead = reverseList(slow);
    	while (head != nullptr) {
    		ListNode* headNext = head->next;
    		ListNode* revHeadNext = revHead->next;
    		head->next = revHead;
    		if (headNext == nullptr) break;
    		revHead->next = headNext;
    		head = headNext;
    		revHead = revHeadNext;
    	}
    }
};