#include<bits/stdc++.h>
using namespace std;
int Brust_Ballon_rec(int i, int j, vector<int>&arr)
{
	if (i > j)
		return 0;
	int maximum = -1e9;
	int minimum_cost;
	for (int indx = i; indx <= j; ++indx)
	{
		minimum_cost = arr[i - 1] * arr[indx] * arr[j + 1] +
		               Brust_Ballon_rec(i, indx - 1, arr) +
		               Brust_Ballon_rec(indx + 1, j, arr);
		maximum = max(minimum_cost, maximum);
	}
	return maximum;
}
int Brust_Ballon_Memorization(int i, int j, vector<int>&arr, vector<vector<int>>&dp)
{
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int maximum = -1e9;
	int minimum_cost;
	for (int indx = i; indx <= j; ++indx)
	{
		minimum_cost =  arr[i - 1] * arr[indx] * arr[j + 1] +
		                Brust_Ballon_Memorization(i, indx - 1, arr, dp) +
		                Brust_Ballon_Memorization(indx + 1, j, arr, dp);
		maximum = max(minimum_cost, maximum);
	}
	dp[i][j] = maximum;
	return maximum;
}

int Brust_Ballon_Dp(vector<int>&arr)
{
	int n = arr.size();
	//we have added 0 and len in original array hence
	//we need to sub those two
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int i = n - 2; i >= 1; i--)
	{
		for (int j = 1; j <= n - 2; j++)
		{
			if (i > j) continue;
			int minimum_cost;
			int minimum = -1e9;
			for (int indx = i; indx <= j; ++indx)
			{

				minimum_cost = arr[i - 1] * arr[indx] * arr[j + 1] +
				               dp[i][indx - 1] +
				               dp[indx + 1][j];
				minimum = max(minimum, minimum_cost);
			}
			dp[i][j] = minimum;
		}
	}
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	return dp[1][n - 2];
}


int main()
{
	int ans = 0;
	vector<int>arr = {3, 1, 5, 8};
	int n = arr.size();
	arr.push_back(1);
	arr.insert(arr.begin(), 1);
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	//ans = Brust_Ballon_rec(1, n , arr);
	//ans = Brust_Ballon_Memorization(1, n, arr, dp);
	ans = Brust_Ballon_Dp(arr);
	cout << ans;

}