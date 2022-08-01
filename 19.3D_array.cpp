//alice and bob are at position (0,0) and (0,m-1) they are allowed to
//move along (i+1,j-1) (i+1,j) (i+1,j+1) find max gold they together can fetch
//when both are at same cell any one of them can pick the gold

//fixed starting point and variable ending point question
#include<bits/stdc++.h>
using namespace std;

int unique_paths_rec(int i, int j1, int j2, int m, int n, vector<vector<int>>arr)
{
	if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
		return -1e9;
	if (i == n - 1)
		if (j1 == j2)
			return arr[i][j1];
		else
			return arr[i][j1] + arr[i][j2];
	int sum, maximum = -1e9;
	//for every movement of alice there asssociated 3 movements of BoB
	for (int Cj1 = -1; Cj1 <= 1 ; ++Cj1)//alice
	{
		for (int Cj2 = -1; Cj2 <= 1; ++Cj2)//bob
		{
			if (j1 == j2)
			{
				sum = arr[i][j1] + unique_paths_rec(i + 1, j1 + Cj1, j2 + Cj2, m, n, arr);
				maximum = max(maximum, sum);
			}
			else
			{
				sum = arr[i][j1] + arr[i][j2] + unique_paths_rec(i + 1, j1 + Cj1, j2 + Cj2, m, n, arr);
				maximum = max(maximum, sum);
			}
		}
	}
	return maximum;
}


int unique_paths_memorization(int i, int j1, int j2, int m, int n, vector<vector<int>>arr, vector<vector<vector<int>>>dp)
{
	if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
		return -1e9;
	if (dp[i][j1][j2] != -1)
		return dp[i][j1][j2];
	if (i == n - 1)
		if (j1 == j2)
			return arr[i][j1];
		else
			return arr[i][j1] + arr[i][j2];
	int sum, maximum = -1e9;
	//for every movement of alice there asssociated 3 movements of BoB
	for (int Cj1 = -1; Cj1 <= 1 ; ++Cj1)//alice
	{
		for (int Cj2 = -1; Cj2 <= 1; ++Cj2)//bob
		{
			if (j1 == j2)
			{
				sum = arr[i][j1] + unique_paths_rec(i + 1, j1 + Cj1, j2 + Cj2, m, n, arr);
				maximum = max(maximum, sum);
			}
			else
			{
				sum = arr[i][j1] + arr[i][j2] + unique_paths_rec(i + 1, j1 + Cj1, j2 + Cj2, m, n, arr);
				maximum = max(maximum, sum);
			}

		}
	}
	dp[i][j1][j2] = maximum;
	return maximum;
}

int unique_paths_Dp(int m , int n, vector<vector<int>>arr)
{
	int dp[n][m][m];
	for (int j1 = 0; j1 < m ; ++j1)
	{
		for (int j2 = 0; j2 < m; ++j2)
		{
			if (j1 == j2)
				dp[n - 1][j1][j2] = arr[n - 1][j1];
			else
				dp[n - 1][j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];
		}
	}
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j1 = 0; j1 < m ; ++j1)
		{
			for (int j2 = 0; j2 < m; ++j2)
			{
				int maximum = -1e9, sum;
				//for every movement of alice there asssociated 3 movements of BoB
				for (int Cj1 = -1; Cj1 <= 1 ; ++Cj1)//alice
				{
					for (int Cj2 = -1; Cj2 <= 1; ++Cj2)//bob
					{
						if (j1 == j2)
						{
							if (j1 + Cj1 >= 0 && j1 + Cj1 < m && j2 + Cj2 >= 0 && j2 + Cj2 < m)
							{
								sum = arr[i][j1] + dp[i + 1][j1 + Cj1] [j2 + Cj2];
								maximum = max(maximum, sum);
							}
						}
						else
						{
							if (j1 + Cj1 >= 0 && j1 + Cj1 < m && j2 + Cj2 >= 0 && j2 + Cj2 < m)
							{
								sum = arr[i][j1] + arr[i][j2] + dp[i + 1][j1 + Cj1] [j2 + Cj2];
								maximum = max(maximum, sum);
							}
						}

					}
				}
				dp[i][j1][j2] = maximum;
			}
		}
	}
	return dp[0][0][m - 1];
}

int unique_paths_Optimisation(int m , int n, vector<vector<int>>arr)
{
	vector<vector<int>>front(m, vector<int>(m));
	for (int j1 = 0; j1 < m ; ++j1)
	{
		for (int j2 = 0; j2 < m; ++j2)
		{
			if (j1 == j2)
				front[j1][j2] = arr[n - 1][j1];
			else
				front[j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];
		}
	}
	for (int i = n - 2; i >= 0; --i)
	{
		vector<vector<int>>current(m, vector<int>(m));
		for (int j1 = 0; j1 < m ; ++j1)
		{
			for (int j2 = 0; j2 < m; ++j2)
			{

				int maximum = -1e9, sum;
				//for every movement of alice there asssociated 3 movements of BoB
				for (int Cj1 = -1; Cj1 <= 1 ; ++Cj1)//alice
				{
					for (int Cj2 = -1; Cj2 <= 1; ++Cj2)//bob
					{
						if (j1 == j2)
						{
							if (j1 + Cj1 >= 0 && j1 + Cj1 < m && j2 + Cj2 >= 0 && j2 + Cj2 < m)
							{
								sum = arr[i][j1] + front[j1 + Cj1] [j2 + Cj2];
								maximum = max(maximum, sum);
							}
						}
						else
						{
							if (j1 + Cj1 >= 0 && j1 + Cj1 < m && j2 + Cj2 >= 0 && j2 + Cj2 < m)
							{
								sum = arr[i][j1] + arr[i][j2] + front[j1 + Cj1] [j2 + Cj2];
								maximum = max(maximum, sum);
							}
						}

					}
				}
				current[j1][j2] = maximum;
			}
		}
		front = current;
	}
	return front[0][m - 1];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> n >> m;
		vector<vector<int>>arr(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
			}
		}
		int minimum_cost = 0;
		//minimum_cost = unique_paths_rec(0, 0, m - 1, m, n, arr);
		vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
		//minimum_cost = unique_paths_memorization(0, 0, m - 1, m, n, arr, dp);
		//minimum_cost = unique_paths_Dp(m, n, arr);
		minimum_cost = unique_paths_Optimisation(m, n, arr);
		cout << minimum_cost;
	}
}

// 3
// 4
// 2 3 1 2
// 3 4 2 2
// 5 6 3 5