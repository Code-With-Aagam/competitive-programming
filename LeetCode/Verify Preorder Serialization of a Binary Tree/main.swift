class Solution {
    func isValidSerialization(_ preorder: String) -> Bool {
        let preorderArray = preorder.split(separator: ",")
        var outdegree = 1
        for each in preorderArray {
            let eachNode = String(each)
            outdegree -= 1
            if outdegree < 0 { return false }
            if eachNode != "#" {
                outdegree += 2
            }
        }
        return outdegree == 0
    }
}