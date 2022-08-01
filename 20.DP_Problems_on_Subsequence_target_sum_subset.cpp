#include<bits/stdc++.h>
using namespace std;
bool Target_Sum_Subset_rec(int n, int target, vector<int>arr)
{
	if (target == 0)
		return true;
	if (n == 0)
		return (arr[0] == target);
	bool not_take = Target_Sum_Subset_rec(n - 1, target, arr);
	bool take = false;
	if (target >= arr[n])
		take = Target_Sum_Subset_rec(n - 1, target - arr[n], arr);
	return (not_take) or (take);
}

bool Target_Sum_Subset_Memorization(int n, int target, vector<int>arr, vector<bool>dp)
{
	if (target == 0)
		return true;
	if (n == 0)
		return (arr[0] == target);
	if (dp[n] != 0)
		return dp[n];
	bool not_take = Target_Sum_Subset_Memorization(n - 1, target, arr, dp);
	bool take = false;
	if (target >= arr[n])
		take = Target_Sum_Subset_Memorization(n - 1, target - arr[n], arr, dp);
	dp[n] = (not_take) or (take);
	return (not_take) or (take);
}

bool Target_Sum_Subset_Dp(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));
	for (int i = 0; i < n; ++i)
	{
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = target; j >= 0; --j)
		{
			bool not_take = dp[i - 1][j];
			bool take = false;
			if (j >= arr[i])
				take = dp[i - 1] [j - arr[i]];
			dp[i][j] = (not_take) or (take);
		}
	}
	return dp[n - 1][target];
}

bool Target_Sum_Subset_Optimisation(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<int>prev(target + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		prev[0] = true;
	}
	prev[arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		vector<int>current(target + 1, 0);
		for (int j = 1; j <= target; ++j)
		{
			bool not_take = prev[j];
			bool take = false;
			if (j >= arr[i])
				take = prev [j - arr[i]];
			current[j] = (not_take) or (take);
		}
		prev = current;
	}
	return prev[target];

}


//single row space optimistaion
bool Target_Sum_Subset_Optimisation_single_row(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<int>prev(target + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		prev[0] = true;
	}
	prev[arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = target; j >= 0; --j)
		{
			bool not_take = prev[j];
			bool take = false;
			if (j >= arr[i])
				take = prev [j - arr[i]];
			prev[j] = (not_take) or (take);
		}
	}
	return prev[target];

}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int target;
		cin >> target;
		bool ans = 0;
		//ans = Target_Sum_Subset_rec(n - 1, target, arr);
		vector<bool>dp(n, 0);
		//ans = Target_Sum_Subset_Memorization(n - 1, target, arr, dp);
		//ans = Target_Sum_Subset_Dp(n , target, arr);
		//ans = Target_Sum_Subset_Optimisation(n , target, arr);
		ans = Target_Sum_Subset_Optimisation_single_row(n, target, arr);
		cout << ans;
	}
}