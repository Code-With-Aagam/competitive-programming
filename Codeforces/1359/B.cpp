#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, a, b, i, j, m, n, k, p, x, y;
	char c;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> x >> y;
		int s = 0;
		vector<vector<int>> arr(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cin >> c;
				arr[i][j] = (c == '*') ? 1 : 0;
			}
		}
		y = (2 * x < y) ? (2 * x) : y;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0 ) {
					if (j < m - 1 && arr[i][j + 1] == 0)
					{
						s += y;
						j += 1;
					}
					else s += x;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
