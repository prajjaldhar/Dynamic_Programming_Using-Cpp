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
		for (int j = n - 1; j >= 0; --j)
		{
			for (int i = m - 1; i >= 0; --i)
			{
				if (j == n - 1)//last column
					dp[i][j] = arr[i][j];
				else if (i == 0) //1St row
					dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
				else if (i == m - 1) //last row
					dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
				else
					dp[i][j] = max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1])) + arr[i][j];
			}
		}
		int max = dp[0][0];
		for (int i = 1; i < n; ++i)
		{
			if (dp[i][0] > max)
				max = dp[i][0];
		}
		cout << "MAXIMUM GOLD = " << max;
	}
}
//input arr
// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
//output = 33