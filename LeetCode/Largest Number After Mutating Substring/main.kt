fun Int.digitToChar(): Char {
    if (this in 0..9) {
        return '0' + this
    }
    throw IllegalArgumentException("Int $this is not a decimal digit")
}

class Solution {
    fun maximumNumber(N: String, change: IntArray): String {
        val num = StringBuilder(N)
        var i = 0
        while (i < num.length && (num[i] - '0') >= change[num[i] - '0']) {
            ++i
        }
        while (i < num.length && (num[i] - '0') <= change[num[i] - '0']) {
            num[i] = change[num[i] - '0'].digitToChar()
            ++i
        }
        return num.toString()
    }
}