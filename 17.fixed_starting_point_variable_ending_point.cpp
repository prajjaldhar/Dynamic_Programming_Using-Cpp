#include<bits/stdc++.h>
using namespace std;
int unique_paths(int i, int j, int n, vector<vector<int>>arr)
{
	if (i == n - 1)
		return arr[n - 1][j]; //last column
	int down = arr[i][j] + unique_paths(i + 1, j, n, arr);
	int diag = arr[i][j] + unique_paths(i + 1, j + 1, n, arr);
	return min(down, diag);
}

int unique_paths_memorization(int i, int j, int n, vector<vector<int>>arr, vector<vector<int>>dp)
{
	if (i == n - 1)
		return arr[n - 1][j]; //last column
	if (dp[i][j] != -1)
		return dp[i][j];
	int down = arr[i][j] + unique_paths(i + 1, j, n, arr);
	int diag = arr[i][j] + unique_paths(i + 1, j + 1, n, arr);
	dp[i][j] = min(down, diag);
	return min(down, diag);
}

int unique_paths_Dp(int n, vector<vector<int>>arr)
{
	//direction of travelling is from opposite (n,n) to (0,0)
	//inital condition
	int dp[n][n];
	for (int j = 0; j < n; ++j)
	{
		dp[n - 1][j] = arr[n - 1][j];
	}
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			int down = arr[i][j] + dp[i + 1][j];
			int diag = arr[i][j] + dp[i + 1][ j + 1];
			dp[i][j] = min(down, diag);
		}
	}
	return dp[0][0];
}

int unique_paths_Optimisation(int n, vector<vector<int>>arr)
{
	vector<int>base_row(n, 0);
	for (int j = 0; j < n; ++j)
	{
		base_row[j] = arr[n - 1][j];
	}
	for (int i = n - 2; i >= 0; --i)
	{
		vector<int>current(n, 0);
		for (int j = i; j >= 0; --j)
		{
			int down = arr[i][j] + base_row[j];
			int diag = arr[i][j] + base_row[ j + 1];
			current[j] = min(down, diag);
		}
		base_row = current;
	}

	return base_row[0];

}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>>arr(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int minimum_cost = 0;
		//minimum_cost = unique_paths(0, 0, n, arr);
		//vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
		//minimum_cost = unique_paths_memorization(0, 0, n, arr, dp);
		//minimum_cost = unique_paths_Dp(n, arr);
		minimum_cost = unique_paths_Optimisation(n, arr);
		cout << minimum_cost;
	}
}
//test case:
// 4
// 1
// 2 3
// 3 6 7
// 8 9 6 10