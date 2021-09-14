class Solution {
	func reverseOnlyLetters(_ s: String) -> String {
		var stack = [Character]()
		s.forEach { ch in
			if ch.isLetter {
				stack.append(ch)
			}
		}
		var ans = ""
		s.forEach { ch in
			if ch.isLetter {
				ans += String(stack.removeLast())
			} else {
				ans += String(ch)
			}
		}
		return ans
	}
}