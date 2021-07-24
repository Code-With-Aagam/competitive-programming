struct Pair {
	var first: String
	var second: [String]
}

class Solution {
	func findLadders(
		_ beginWord: String,
		_ endWord: String,
		_ wordList: [String]
	) -> [[String]] {
		var seen = [String : Int]()
		var ans = [[String]]()
		wordList.forEach{ seen[$0] = Int.max }
		var q = [Pair]()
		q.append(Pair(first: beginWord, second: [beginWord]))
		while !q.isEmpty {
			let curr = q.removeFirst()
			let word = curr.first
			var currList = curr.second
			if word == endWord {
				ans.append(currList)
				continue
			}
			for i in 0 ..< word.count {
				var tempWord = Array(word)
				for ch in "abcdefghijklmnopqrstuvwxyz" {
					tempWord[i] = ch
					let tempWordString = String(tempWord)
					if tempWordString == word 
                    || seen[tempWordString] == 0 
                    || (seen[tempWordString] ?? 0) < currList.count 
                    {
						continue
					}
					seen[tempWordString] = currList.count
					currList.append(tempWordString)
					q.append(Pair(first: tempWordString, second: currList))
					currList.removeLast()
				}
			}
		}
		return ans
	}
}