class Solution {
    func smallestChair(_ t: [[Int]], _ targetFriend: Int) -> Int {
        var times = [[Int]]()
        for i in t.indices {
            times.append([t[i][0], t[i][1], i])
        }
        times = times.sorted { $0[0] < $1[0] }
        var chair = [Int](repeating: 0, count: times.count)
        for i in times.indices {
            for j in chair.indices {
                if chair[j] <= times[i][0] {
                    chair[j] = times[i][1]
                    if targetFriend == times[i][2] {
                        return j
                    }
                    break
                }
            }
        }
        return 0
    }
}