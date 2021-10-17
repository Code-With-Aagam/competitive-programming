class Solution {
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        val freq = Array(26) { 0 }
        magazine.forEach {
            freq[it - 'a']++
        }
        ransomNote.forEach {
            freq[it - 'a']--
        }
        return freq.none { it < 0 }
    }
}