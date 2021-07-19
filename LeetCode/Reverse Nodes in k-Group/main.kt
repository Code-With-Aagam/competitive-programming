class Solution {
    private fun reverseLinkedList(
        start: ListNode?, 
        end: ListNode?
    ): ListNode? {
        var (prev, curr, first) = listOf(start, start?.next, start?.next)
        while (curr != end) {
            val next = curr?.next
            curr?.next = prev
            prev = curr
            curr = next
        }
        start?.next = prev
        first?.next = curr
        return first
    }

    fun reverseKGroup(h: ListNode?, k: Int): ListNode? {
        var head = h
        if (head?.next == null || k == 1) {
            return head
        }
        val dummy = ListNode(0)
        var start: ListNode? = dummy
        dummy.next = head
        var cnt = 0
        while (head != null) {
            ++cnt
            when (cnt % k) {
                0 -> {
                    start = reverseLinkedList(start, head.next)
                    head = start?.next
                }
                else -> head = head.next
            }
        }
        return dummy.next
    }
}