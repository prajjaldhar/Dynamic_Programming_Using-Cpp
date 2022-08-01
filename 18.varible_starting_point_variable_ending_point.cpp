#include<bits/stdc++.h>
using namespace std;
int unique_paths(int i, int j, int m, int n, vector<vector<int>>arr)
{
	if (j < 0 || j >= m)
		return -1e9;
	if (i == 0)
		return arr[0][j];
	int up = arr[i][j] + unique_paths(i - 1, j , m, n, arr);
	int rdiag = arr[i][j] + unique_paths(i - 1, j + 1, m, n, arr);
	int ldiag = arr[i][j] + unique_paths(i - 1, j - 1, m, n, arr);
	return max(up, max(rdiag, ldiag));
}

int unique_paths_memorization(int i, int j, int m, int n, vector<vector<int>>arr, vector<vector<int>>dp)
{
	if (j < 0 || j >= m)
		return -1e9;
	if (i == 0)
		return arr[0][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	int up = arr[i][j] + unique_paths_memorization(i - 1, j , m, n, arr, dp);
	int rdiag = arr[i][j] + unique_paths_memorization(i - 1, j + 1, m, n, arr, dp);
	int ldiag = arr[i][j] + unique_paths_memorization(i - 1, j - 1, m, n, arr, dp);
	dp[i][j] = max(up, max(rdiag, ldiag));
	return max(up, max(rdiag, ldiag));
}

int unique_paths_Dp(int m, int n, vector<vector<int>>arr)
{
	//direction of travelling is from opposite (n,n) to (0,0)
	//inital condition
	int dp[m][n] = {0};
	//base case
	for (int j = 0; j < m ; ++j)
	{
		dp[0][j] = arr[0][j];
	}
	for (int i = 1; i < n ; ++i)
	{
		for (int j = 0; j < m ; ++j)
		{
			int rdiag = arr[i][j];
			int ldiag = arr[i][j];
			int up = arr[i][j] + dp[i - 1][j];
			if (j + 1 < m )
				rdiag += dp[i - 1][ j + 1];
			else
				rdiag += (-1e9);
			if (j - 1 >= 0)
				ldiag += dp[i - 1][ j - 1];
			else
				ldiag += (-1e9);
			dp[i][j] = max(up, max(rdiag, ldiag));
		}
	}
	int maximum = -1e9;
	for (int j = 0; j < m - 1; ++j)
	{
		maximum = max(maximum, dp[n - 1][j]);
	}
	return maximum;
}

int unique_paths_Optimisation(int m, int n, vector<vector<int>>arr)
{
	//direction of travelling is from opposite (n,n) to (0,0)
	//inital condition
	vector<int>prev(n, 0);
	//base case
	for (int j = 0; j < m ; ++j)
	{
		prev[j] = arr[0][j];
	}
	for (int i = 1; i < n ; ++i)
	{
		vector<int>curr(n, 0);
		for (int j = 0; j < m ; ++j)
		{
			int rdiag = arr[i][j];
			int ldiag = arr[i][j];
			int up = arr[i][j] + prev[j];
			if (j + 1 < m - 1)
				rdiag += prev[ j + 1];
			else
				rdiag += (-1e9);
			if (j - 1 >= 0)
				ldiag += prev[ j - 1];
			else
				ldiag += (-1e9);
			curr[j] = max(up, max(rdiag, ldiag));
		}
		prev = curr;
	}
	int maximum = -1e9;
	for (int j = 0; j < m - 1; ++j)
	{
		maximum = max(maximum, prev[j]);
	}
	return maximum;
}

int solve_rec(int m, int n, vector<vector<int>>arr)
{
	int maximum = -1e9;
	for (int j = 0; j < m ; ++j)
	{
		maximum = max(maximum, unique_paths(n - 1, j, m, n, arr));
	}
	return maximum;
}

int solve_Memo(int m, int n, vector<vector<int>>arr)
{
	int maximum = -1e9;
	for (int j = 0; j < m ; ++j)
	{
		vector<vector<int>>dp(m, vector<int>(m, -1));
		maximum = max(maximum, unique_paths_memorization(n - 1, j, m, n, arr, dp));
	}
	return maximum;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		vector<vector<int>>arr(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int minimum_cost = 0;
		//minimum_cost = solve_rec(m, n, arr);
		//vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
		//minimum_cost = solve_Memo(m, n, arr);
		minimum_cost = unique_paths_Dp(m, n, arr);
		//minimum_cost = unique_paths_Optimisation(m, n, arr);
		cout << minimum_cost;
	}
}
//test case:
// 4
// 4
// 1 2 10 4
// 100 3 2 1
// 1 1 20 2
// 1 2 2 1