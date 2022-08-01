#include<bits/stdc++.h>
using namespace std;
int minimium_coin_change_rec(int n, int target, vector<int>coins)
{
	if (target == 0)
		return 1;
	if (n == 0)
	{
		return (target % coins[0] == 0);
	}
	int not_take = minimium_coin_change_rec(n - 1, target, coins);
	int take = 0;
	if (target >= coins[n])
		take = minimium_coin_change_rec(n, target - coins[n], coins);
	return (not_take + take);
}

int minimium_coin_change_Memorization(int n, int target, vector<int>coins, vector<int>dp)
{
	if (target == 0)
		return 1;
	if (n == 0)
	{
		return (target % coins[n] == 0);
	}
	if (dp[n] != -1)
		return dp[n];
	int not_take = minimium_coin_change_Memorization(n - 1, target, coins, dp);
	int take = 0;
	if (target >= coins[n])
		take = minimium_coin_change_Memorization(n, target - coins[n], coins, dp);
	dp[n] = (not_take + take);
	return (not_take + take);
}

int minimium_coin_change_Dp(int n, int target, vector<int>coins)
{
	//i=n and j=target
	//dp[n][target]
	vector<vector<int>>dp(n, vector<int>(target + 1, 0));
	for (int i = 0; i <= target; ++i)
	{
		dp[0][i] = ( i % coins[0] == 0);
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int not_take = dp[i - 1][j];
			int take = 0;
			if (j >= coins[i])
				take = dp[i] [j - coins[i]];
			dp[i][j] = (not_take + take);
		}
	}
	return dp[n - 1][target];
}

int minimium_coin_change_Optimisation(int n, int target, vector<int>coins)
{
	//i=n and j=target
	//dp[n][target]
	vector<int>prev(target + 1, 0);
	for (int i = 0; i <= target; ++i)
	{
		prev[i] = ( i % coins[0] == 0);
	}
	for (int i = 1; i < n; ++i)
	{
		vector<int>current(target + 1, 0);
		for (int j = 0; j <= target; ++j)
		{
			int not_take = prev[j];
			int take = 0;
			if (j >= coins[i])
				take = current[j - coins[i]];
			current[j] = (not_take + take);
		}
		prev = current;
	}
	return prev[target];
}

int minimium_coin_change_Optimisation_1D(int n, int target, vector<int>coins)
{
	//i=n and j=target
	//dp[n][target]
	vector<int>prev(target + 1, 0);
	for (int i = 0; i <= target; ++i)
	{
		prev[i] = ( i % coins[0] == 0);
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int not_take = prev[j];
			int take = 0;
			if (j >= coins[i])
				take = prev[j - coins[i]];
			prev[j] = (not_take + take);
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
		vector<int>coins(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> coins[i];
		}
		int target;
		cin >> target;
		int ans = 0;
		//ans = minimium_coin_change_rec(n - 1, target, coins);
		vector<int>dp(n, -1);
		//ans = minimium_coin_change_Memorization(n - 1, target, coins, dp);
		//ans = minimium_coin_change_Dp(n , target, coins);
		//ans = minimium_coin_change_Optimisation(n , target, coins);
		ans = minimium_coin_change_Optimisation_1D(n , target, coins);
		cout << ans;
	}
}

// 9 1 5 6
// 11