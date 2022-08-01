#include<bits/stdc++.h>
using namespace std;
int MCM_rec(int i, int j, vector<int>&arr)
{
	if (i == j)
		return 0;//no extra operation is required
	int minimum = 1e9;
	int steps;
	for (int k = i; k < j; k++)
	{
		steps = arr[i - 1] * arr[k] * arr[j] + MCM_rec(i, k, arr) + MCM_rec(k + 1, j, arr);
		minimum = min(minimum, steps);
	}
	return minimum;
}

int MCM_Memorization(int i, int j, vector<int>&arr, vector<vector<int>>&dp)
{
	if (i == j)
		return 0;//no extra operation is required
	int minimum = 1e9;
	int steps;
	if (dp[i][j] != -1)
		return dp[i][j];
	for (int k = i; k < j; k++)
	{
		steps = arr[i - 1] * arr[k] * arr[j] + MCM_Memorization(i, k, arr, dp) + MCM_Memorization(k + 1, j, arr, dp);
		minimum = min(minimum, steps);
	}
	dp[i][j] = minimum;
	return minimum;
}

int MCM_Dp(vector<int>&arr)
{
	// if (i == j)
	// 	return 0;//no extra operation is required
	int n = arr.size();
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i < n; i++)
		dp[i][i] = 0;

	for (int i = n - 1 ; i >= 1 ; --i)
	{
		for (int j = i + 1; j < n; j++)
		{
			int minimum = 1e9;
			int steps;
			for (int k = i; k < j; k++)
			{
				steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j] ;
				minimum = min(minimum, steps);
			}
			dp[i][j] = minimum;
		}
	}
	//DP TABLE
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	return dp[1][n - 1];
}

int main()
{
	int ans = 0;
	vector<int>arr = {10, 20, 30, 40};
	int n = arr.size();
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	//ans = MCM_rec(1, n - 1, arr);
	//ans = MCM_Memorization(1, n - 1, arr, dp);
	ans = MCM_Dp(arr);
	cout << ans;

}