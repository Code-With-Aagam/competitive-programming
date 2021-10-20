class Solution {
	func reverseWords(_ s: String) -> String {
		var ans = s
		while ans.starts(with: " ") {
			ans.removeFirst()
		}
		while ans.reversed().starts(with: " ") {
			ans.removeLast()
		}
		return ans.split(separator: " ").reversed().joined(separator: " ")
	}
}
