class Solution {
    func splitPainting(_ segments: [[Int]]) -> [[Int]] {
        var (N, n) = (100005, 0)
        var color = [Int](repeating: 0, count: N)
        var hash = [Bool](repeating: false, count: N)
        segments.forEach { segment in
            color[segment[0]] += segment[2]
            color[segment[1]] -= segment[2]
            hash[segment[0]] = true
            hash[segment[1]] = true
            n = max(n, segment[1])
        }
        var ans = [[Int]]()
        var (curr, prev) = (0, 0)
        for i in 1 ... n {
            if hash[i] && curr > 0 {
                ans.append([prev, i, curr])
            }
            if hash[i] {
                prev = i
            }
            curr += color[i]
        }
        return ans
    }
}