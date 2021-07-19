class Solution {
	func canBeTypedWords(_ text: String, _ brokenLetters: String) -> Int {
		let broken = Set<Character>(brokenLetters)
		var ans = 0
		let words = text.split(separator: " ")
		for word in words {
			var good = true
			for ch in word {
				if broken.contains(ch) {
					good = false
					break
				}
			}
			if good { ans += 1 }
		}
		return ans
	}
}