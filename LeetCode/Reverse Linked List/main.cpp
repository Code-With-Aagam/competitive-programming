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
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ans = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }

public:
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
};