#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		cin >> m;
		int arr[n][m];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int dp[n][m];
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = m - 1; j >= 0; --j)
			{
				if (i == n - 1 && j == m - 1)
					dp[i][j] = arr[i][j];
				else if (i == n - 1) //last row
					dp[i][j] = dp[i][j + 1] + arr[i][j];
				else if (j == m - 1) //last col
					dp[i][j] = dp[i + 1][j] + arr[i][j];
				else
					dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + arr[i][j];
			}
		}
		cout << dp[0][0];
	}
}
//input arr
// 7
// 7
// 2 8 4 1 6 4 2
// 6 0 9 5 3 8 5
// 1 4 3 4 0 6 5
// 6 4 7 2 4 6 1
// 1 0 3 7 1 2 7
// 1 5 3 2 3 0 9
// 2 2 5 1 9 8 2
//output = 36