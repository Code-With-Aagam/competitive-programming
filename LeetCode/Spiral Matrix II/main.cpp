class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> arr(n, vector<int>(n));
		int dir = 0, rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1, num = 1;
		while (rowStart <= rowEnd && colStart <= colEnd) {
			if (dir == 0) {
				for (int j = colStart; j <= colEnd; ++j) {
					arr[rowStart][j] = num++;
				}
				rowStart++;
			} else if (dir == 1) {
				for (int i = rowStart; i <= rowEnd; ++i) {
					arr[i][colEnd] = num++;
				}
				colEnd--;
			} else if (dir == 2) {
				for (int j = colEnd; j >= colStart; --j) {
					arr[rowEnd][j] = num++;
				}
				rowEnd--;
			} else {
				for (int i = rowEnd; i >= rowStart; --i) {
					arr[i][colStart] = num++;
				}
				colStart++;
			}
			dir = (dir + 1) % 4;
		}
		return arr;
	}
};