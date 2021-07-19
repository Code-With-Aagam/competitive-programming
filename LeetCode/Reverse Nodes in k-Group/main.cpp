class Solution {
   private:
    ListNode* reverseLinkedList(ListNode* start, ListNode* end) {
        ListNode *prev = start, *curr = start->next, *first = start->next;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = prev;
        first->next = curr;
        return first;
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* start = dummy;
        dummy->next = head;
        int cnt = 0;
        while (head != nullptr) {
            ++cnt;
            if (cnt % k == 0) {
                start = reverseLinkedList(start, head->next);
                head = start->next;
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }
};