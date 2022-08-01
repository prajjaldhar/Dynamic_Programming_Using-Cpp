#include<bits/stdc++.h>
using namespace std;
int unique_paths(int m, int n, vector<vector<int>>arr)
{
	if (m == 0 && n == 0)
		return arr[0][0];
	if (m < 0 || n < 0)
		return 655555;//INT_MAX or 1e9
	int up = arr[m][n] + unique_paths(m - 1, n, arr);
	int left = arr[m][n] + unique_paths(m, n - 1, arr);
	return min(up, left);
}

int unique_paths_memorization(int m, int n, vector<vector<int>>arr, vector<vector<int>>dp)
{
	if (m == 0 && n == 0)
		return arr[0][0];
	if (m < 0 || n < 0)
		return 65536;//INT_MAX or 1e9
	if (dp[m][n] != -1)
		return dp[m][n];
	int up = arr[m][n] + unique_paths_memorization(m - 1, n, arr , dp);
	int left = arr[m][n] + unique_paths_memorization(m, n - 1, arr, dp);
	dp[m][n] = min(up, left);
	return min(up, left);
}

int unique_paths_Dp(int m, int n, vector<vector<int>>arr)
{
	int dp[m][n];
	dp[0][0] = arr[0][0];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != 0 || j != 0)
			{
				int up = arr[i][j] , left = arr[i][j] ;

				if (i > 0)
					up += dp[i - 1][j];
				else
					up += 1e9;
				if (j > 0)
					left += dp[i][j - 1];
				else
					left += 1e9;
				dp[i][j] = min(up, left);
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
				temp[j] = arr[0][0];
			else
			{
				int up = arr[i][j];
				int left = arr[i][j];
				if (i > 0)
					up += dp[j];
				else
					up += 1e9;
				if (j > 0)
					left += temp[j - 1];
				else
					left += 1e9;
				temp[j] = min(up, left);
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
		int minimum_cost = 0;
		//minimum_cost = unique_paths(m - 1, n - 1, arr);
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
		//minimum_cost = unique_paths_memorization(m - 1, n - 1, arr, dp);
		//minimum_cost = unique_paths_Dp(m, n, arr);
		minimum_cost = unique_paths_Optimisation(m, n, arr);
		cout << minimum_cost;
	}
}
//test case:
// 2
// 3
// 5 9 6
// 1 5 2