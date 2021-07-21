class Solution {
    fun pushDominoes(dominoes: String): String {
        var ans = dominoes
        while (true) {
            val newDominoes = ans.replace(
                "R.L",
                "|"
            ).replace(
                ".L",
                "LL"
            ).replace(
                "R.",
                "RR"
            ).replace(
                "|",
                "R.L"
            )
            if (ans == newDominoes) {
                break
            } else {
                ans = newDominoes
            }
        }
        return ans
    }
}