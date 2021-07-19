class Solution {
    fun canBeTypedWords(text: String, brokenLetters: String): Int {
        val broken = brokenLetters.toSet()
        var ans = 0
        val words = text.split(" ")
        for (word in words) {
            var good = true
            for (ch in word) {
                if (broken.contains(ch)) good = false
            }
            if (good) ++ans
        }
        return ans
    }
}