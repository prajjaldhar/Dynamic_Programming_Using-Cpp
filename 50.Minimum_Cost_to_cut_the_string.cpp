#include<bits/stdc++.h>
using namespace std;
int Minimum_Cost_to_cut_rec(int i, int j, vector<int>&arr)
{
	if (i > j)
		return 0;
	int minimum = 1e9;
	int minimum_cost;
	for (int indx = i; indx <= j; ++indx)
	{
		minimum_cost = arr[j + 1] - arr[i - 1] +
		               Minimum_Cost_to_cut_rec(i, indx - 1, arr) +
		               Minimum_Cost_to_cut_rec(indx + 1, j, arr);
		minimum = min(minimum_cost, minimum);
	}
	return minimum;
}
int Minimum_Cost_to_cut_Memorization(int i, int j, vector<int>&arr, vector<vector<int>>&dp)
{
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int minimum = 1e9;
	int minimum_cost;
	for (int indx = i; indx <= j; ++indx)
	{
		minimum_cost = arr[j + 1] - arr[i - 1] +
		               Minimum_Cost_to_cut_Memorization(i, indx - 1, arr, dp) +
		               Minimum_Cost_to_cut_Memorization(indx + 1, j, arr, dp);
		minimum = min(minimum_cost, minimum);
	}
	dp[i][j] = minimum;
	return minimum;
}

int Minimum_Cost_to_cut_Dp(vector<int>&arr)
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
			int minimum = 1e9;
			for (int indx = i; indx <= j; ++indx)
			{

				minimum_cost = arr[j + 1] - arr[i - 1] +
				               dp[i][indx - 1] +
				               dp[indx + 1][j];
				minimum = min(minimum, minimum_cost);
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
	vector<int>arr = {1, 3, 4, 5};
	int c = arr.size();
	int n = 7;
	arr.push_back(n);
	arr.insert(arr.begin(), 0);
	sort(arr.begin(), arr.end());
	vector<vector<int>>dp(c + 1, vector<int>(c + 1, -1));
	//ans = Minimum_Cost_to_cut_rec(1, c , arr);
	//ans = Minimum_Cost_to_cut_Memorization(1, c, arr, dp);
	ans = Minimum_Cost_to_cut_Dp(arr);
	cout << ans;

}