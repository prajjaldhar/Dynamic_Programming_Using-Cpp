#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		int ans = 0;
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
				if (i == n - 1 && j == m - 1) //last cell
					dp[i][j] = arr[i][j];
				else if (i == n - 1) //last row
					dp[i][j] = arr[i][j];
				else if (j == m - 1) //last col
					dp[i][j] = arr[i][j];
				else {
					if (arr[i][j] == 0)
						dp[i][j] = 0;
					else
					{
						dp[i][j] = 1 * max(dp[i][j + 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
						if (dp[i][j] > ans)
							ans = dp[i][j];
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << ans;
	}
}
//input array
// 1 0 1 1
// 1 0 1 1
// 0 1 0 1
// 1 1 1 1
// 0 0 0 1

// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 1 1 1 0
// 0 0 1 1 1 0
// 1 1 1 1 1 1