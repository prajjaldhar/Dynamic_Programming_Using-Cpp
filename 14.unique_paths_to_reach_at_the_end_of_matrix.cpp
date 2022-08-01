#include<bits/stdc++.h>
using namespace std;
int unique_paths(int m, int n)
{
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	int up = unique_paths(m - 1, n);
	int left = unique_paths(m, n - 1);
	return up + left;
}

int unique_paths_memorization(int m, int n, vector<vector<int>>dp)
{
	if (m == 0 && n == 0)
		return 1;
	if (m < 0 || n < 0)
		return 0;
	if (dp[m][n] != -1)
		return dp[m][n];
	int up = unique_paths_memorization(m - 1, n, dp);
	int left = unique_paths_memorization(m, n - 1, dp);
	dp[m][n] = up + left;
	return up + left;
}

int unique_paths_Dp(int m, int n)
{
	int dp[m][n];
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != 0 || j != 0)
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

int unique_paths_Optimisation(int m, int n)
{
	vector<int>dp(n, 0);
	for (int i = 0; i < m ; ++i)
	{
		vector<int>temp(n, 0);
		for (int j = 0; j < n ; ++j)
		{
			if (i == 0 && j == 0)
				temp[j] = 1;
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
		int possible_ways = 0;
		//possible_ways = unique_paths(m - 1, n - 1);
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
		//possible_ways = unique_paths_memorization(m - 1, n - 1, dp);
		//possible_ways = unique_paths_Dp(m, n);
		possible_ways = unique_paths_Optimisation(m, n);
		cout << possible_ways;
	}
}