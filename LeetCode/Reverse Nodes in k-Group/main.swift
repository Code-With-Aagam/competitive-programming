class Solution {
	private func reverseLinkedList(
		_ start: ListNode?,
		_ end: ListNode?
	) -> ListNode? {
		var (prev, curr, first) = (start, start?.next, start?.next)
		while curr !== end {
			let next = curr?.next
			curr?.next = prev
			prev = curr
			curr = next
		}
		start?.next = prev
		first?.next = curr
		return first
	}
	
	func reverseKGroup(_ h: ListNode?, _ k: Int) -> ListNode? {
		var head = h
		if head == nil || head?.next == nil || k == 1 {
			return head
		}
		let dummy = ListNode(0)
		var start: ListNode? = dummy
		dummy.next = head
		var cnt = 0
		while head != nil {
			cnt += 1
			if cnt % k == 0 {
				start = reverseLinkedList(start, head?.next)
				head = start?.next
			} else {
				head = head?.next
			}
		}
		return dummy.next
	}
}