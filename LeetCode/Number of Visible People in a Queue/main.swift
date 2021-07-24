class Solution {
    func canSeePersonsCount(_ heights: [Int]) -> [Int] {
        var ans = [Int](repeating: 0, count: heights.count)
        var st = [Int]()
        for i in heights.indices {
            while !st.isEmpty && heights[st.last!] <= heights[i] {
                ans[st.removeLast()] += 1
            }
            if let last = st.last {
                ans[last] += 1
            }
            st.append(i)
        }
        return ans
    }
}