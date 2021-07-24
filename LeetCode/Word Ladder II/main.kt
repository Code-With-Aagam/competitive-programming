class Solution {
    fun findLadders(
        beginWord: String,
        endWord: String,
        wordList: List<String>
    ): List<List<String>> {
        val seen = hashMapOf<String, Int>()
        val ans = ArrayList<ArrayList<String>>()
        wordList.forEach { word -> seen[word] = Integer.MAX_VALUE }
        val q: Queue<Pair<String, ArrayList<String>>> = LinkedList()
        q.add(Pair(beginWord, arrayListOf(beginWord)))
        while (q.isNotEmpty()) {
            val curr = q.poll()
            val word = curr.first
            var currList = curr.second.toMutableList()
            if (word == endWord) {
                ans.add(currList as ArrayList<String>)
                continue
            }
            for (i in word.indices) {
                val tempWord = StringBuilder(word)
                for (ch in 'a'..'z') {
                    tempWord[i] = ch
                    val tempWordString = tempWord.toString()
                    if (tempWordString == word
                        || seen[tempWordString] == 0
                        || (seen[tempWordString] ?: 0) < currList.size
                    ) continue
                    seen[tempWordString] = currList.size
                    currList.add(tempWordString)
                    q.add(Pair(tempWordString, currList as ArrayList<String>))
                    currList = currList.dropLast(1).toMutableList()
                }
            }
        }
        return ans
    }
}