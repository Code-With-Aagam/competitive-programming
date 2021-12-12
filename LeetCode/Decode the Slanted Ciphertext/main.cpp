class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int total = encodedText.size(), cols = total / rows, k = 0;
        vector<vector<char>> board(rows, vector<char>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] = encodedText[k++];
            }
        }
        string ans = "";
        int i = 0, j = 0, prevj = 0;
        while (j < cols) {
            ans += board[i][j];
            ++i;
            ++j;
            if (i >= rows) {
                i = 0;
                j = prevj + 1;
                prevj = j;
            }
        }
        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};