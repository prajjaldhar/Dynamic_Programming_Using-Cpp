#include<bits/stdc++.h>
using namespace std;
int unique_paths(int m, int n, vector<vector<int>>arr)
{
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	if (m >= 0 && n >= 0 && arr[m][n] == -1)
		return 0;
	int up = unique_paths(m - 1, n, arr);
	int left = unique_paths(m, n - 1, arr);
	return up + left;
}

int unique_paths_memorization(int m, int n, vector<vector<int>>arr, vector<vector<int>>dp)
{
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	if (m >= 0 && n >= 0 && arr[m][n] == -1)
		return 0;
	if (dp[m][n] != -1)
		return dp[m][n];
	int up = unique_paths_memorization(m - 1, n, arr , dp);
	int left = unique_paths_memorization(m, n - 1, arr, dp);
	dp[m][n] = up + left;
	return up + left;
}

int unique_paths_Dp(int m, int n, vector<vector<int>>arr)
{
	int dp[m][n];
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == -1)//dead cell
				dp[i][j] = 0;
			else if (i != 0 || j != 0)
			{
				int up = 0, left = 0;
				if (i > 0)
					up = dp[i - 1][j];
				if (j > 0)
					left = dp[i][j - 1];
				dp[i][j] = up + left;
			}
		}
	}
	return dp[m - 1][n - 1];
}

int unique_paths_Optimisation(int m, int n, vector<vector<int>>arr)
{
	vector<int>dp(n, 0);
	for (int i = 0; i < m ; ++i)
	{
		vector<int>temp(n, 0);
		for (int j = 0; j < n ; ++j)
		{
			if (i == 0 && j == 0)
				temp[j] = 1;
			else if (arr[i][j] == -1)
				temp[j] = 0;
			else
			{
				int up = 0;
				int left = 0;
				if (i > 0)
					up = dp[j];
				if (j > 0)
					left = temp[j - 1];
				temp[j] = up + left;
			}
		}
		dp = temp;
	}
	return dp[n - 1];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> m >> n;
		vector<vector<int>>arr(m , vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int possible_ways = 0;
		//possible_ways = unique_paths(m - 1, n - 1, arr);
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
		//possible_ways = unique_paths_memorization(m - 1, n - 1, arr, dp);
		//possible_ways = unique_paths_Dp(m, n, arr);
		possible_ways = unique_paths_Optimisation(m, n, arr);
		cout << possible_ways;
	}
}
//test case:
// 4
// 4
// 0 0 0 -1
// 0 -1 0 -1
// 0 -1 0 0
// -1 0 -1 0