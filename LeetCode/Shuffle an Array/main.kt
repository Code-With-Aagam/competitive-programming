import kotlin.random.Random

class Solution(nums: IntArray) {
    private val originalArray = nums
    private val size = nums.size
    private val random = Random(42)

    fun reset() = originalArray

    fun shuffle(): IntArray {
        val shuffledArray = originalArray.toMutableList()
        for (i in 1 until size) {
            val j = random.nextInt(0, i + 1)
            Collections.swap(shuffledArray, i, j)
        }
        return shuffledArray.toIntArray()
    }
}