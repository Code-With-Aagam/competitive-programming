class Solution {
public:
    string multiply(string A, string B) {
        int n = A.size(), m = B.size();
        vector<int> arr(n + m);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (A[i] - '0') * (B[j] - '0');
                int sum = mul + arr[i + j + 1];
                arr[i + j + 1] = sum % 10;
                arr[i + j] += sum / 10;
            }
        }
        string ans = "";
        for (const auto &ch : arr) {
            if (ans.empty() && ch == 0) continue;
            ans += to_string(ch);
        }
        return ans == "" ? "0" : ans;        
    }
};