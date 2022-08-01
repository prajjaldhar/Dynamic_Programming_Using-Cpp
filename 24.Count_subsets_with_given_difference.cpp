#include<bits/stdc++.h>
using namespace std;
int Target_Sum_Subset_rec(int n, int target, vector<int>arr)
{
// 	if (target == 0)//not pick any subsets
// 		return 1;
// 	if (n == 0)
// 		return (arr[0] == target);
	if (n == 0)
	{
		if (target == 0 && arr[0] == 0)
			return 2;//we have two possibility take or not take that 0
		else if (target == 0 || target == arr[0])
			return 1;//pick that element
		else
			return 0;
	}
	int not_take = Target_Sum_Subset_rec(n - 1, target, arr);
	int take = 0;
	if (target >= arr[n])
		take = Target_Sum_Subset_rec(n - 1, target - arr[n], arr);
	return (not_take) + (take);
}

int Target_Sum_Subset_Memorization(int n, int target, vector<int>arr, vector<int>dp)
{
	// if (target == 0)
	// 	return 1;
	// if (n == 0)
	// 	return (arr[0] == target);
	if (n == 0)
	{
		if (target == 0 && arr[0] == 0)
			return 2;//we have two possibility take or not take that 0
		else if (target == 0 || target == arr[0])
			return 1;//pick that element
		else
			return 0;
	}
	if (dp[n] != 0)
		return dp[n];
	int not_take = Target_Sum_Subset_Memorization(n - 1, target, arr, dp);
	int take = 0;
	if (target >= arr[n])
		take = Target_Sum_Subset_Memorization(n - 1, target - arr[n], arr, dp);
	dp[n] = (not_take) + (take);
	return (not_take) + (take);
}

int Target_Sum_Subset_Dp(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<vector<int>>dp(n, vector<int>(target + 1, 0));
	if (arr[0] == 0)
		dp[0][0] = 2;
	else
		dp[0][0] = 1;
	if (arr[0] != 0 && arr[0] <= target)
		dp[0][arr[0]] = 1;
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = 1;
	}
	// dp[0][arr[0]] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			int not_take = dp[i - 1][j];
			int take = 0;
			if (j >= arr[i])
				take = dp[i - 1] [j - arr[i]];
			dp[i][j] = (not_take) + (take);
		}
	}
	return dp[n - 1][target];
}

int Target_Sum_Subset_Optimisation(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<int>prev(target + 1, 0);
	if (arr[0] == 0)
		prev[0] = 2;
	else
		prev[0] = 1;
	if (arr[0] != 0 && arr[0] <= target)
		prev[arr[0]] = 1;
	// prev[0] = 1;
	// prev[arr[0]] = 1;
	for (int i = 1; i < n; ++i)
	{
		vector<int>current(target + 1, 0);
		current[0] = 1;
		for (int j = 1; j <= target; ++j)
		{
			int not_take = prev[j];
			int take = 0;
			if (j >= arr[i])
				take =  prev[j - arr[i]];
			current[j] = (not_take) + (take);
		}
		prev = current;
	}
	return prev[target];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, D;
		cin >> n;
		vector<int>arr(n, 0);
		int tot_sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			tot_sum += arr[i];
		}
		cin >> D;
		if ((tot_sum - D) < 0 || (tot_sum - D) % 2 )
		{
			cout << "false case";
			return 0;
		}
		int target = (tot_sum - D) / 2;
		int ans = 0;
		//ans = Target_Sum_Subset_rec(n - 1, target, arr);
		vector<int>dp(n, 0);
		//ans = Target_Sum_Subset_Memorization(n - 1, target, arr, dp);
		ans = Target_Sum_Subset_Dp(n , target, arr);
		//ans = Target_Sum_Subset_Optimisation(n , target, arr);
		cout << ans << "\n";
	}
}
// 5
// 3 1 1 2 1
// 0

// 4
// 5 2 6 4
// 3

// 4
// 5 2 5 1
// 3