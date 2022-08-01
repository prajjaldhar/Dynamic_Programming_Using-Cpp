#include<bits/stdc++.h>
using namespace std;
int minimium_coin_change_rec(int n, int target, vector<int>coins)
{
	if (target == 0)
		return 0;
	if (n == 0)
	{
		if (target % coins[n] == 0)
			return (target / coins[n]);
		else
			return 1e9;
	}
	int not_take = 0 + minimium_coin_change_rec(n - 1, target, coins);
	int take = 1e9;
	if (target >= coins[n])
		take = 1 + minimium_coin_change_rec(n, target - coins[n], coins);
	return min(not_take, take);
}

int minimium_coin_change_Memorization(int n, int target, vector<int>coins, vector<int>dp)
{
	if (target == 0)
		return 0;
	if (n == 0)
	{
		if (target % coins[n] == 0)
			return (target / coins[n]);
		else
			return 1e9;
	}
	if (dp[n] != -1)
		return dp[n];
	int not_take = 0 + minimium_coin_change_Memorization(n - 1, target, coins, dp);
	int take = 1e9;
	if (target >= coins[n])
		take = 1 + minimium_coin_change_Memorization(n, target - coins[n], coins, dp);
	dp[n] = min(not_take, take);
	return min(not_take, take);
}

int minimium_coin_change_Dp(int n, int target, vector<int>coins)
{
	//i=n and j=target
	//dp[n][target]
	vector<vector<int>>dp(n, vector<int>(target + 1, 0));
	for (int i = 0; i <= target; ++i)
	{
		if ( i % coins[0] == 0)
			dp[0][i] = i / coins[0];
		else
			dp[0][i] = 1e9;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int not_take = 0 + dp[i - 1][j];
			int take = 1e9;
			if (j >= coins[i])
				take = 1 +  dp[i] [j - coins[i]];
			dp[i][j] = min(not_take, take);
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
		if ( i % coins[0] == 0)
			prev[i] = i / coins[0];
		else
			prev[i] = 1e9;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = target; j >= 0; --j)
		{
			int not_take = 0 + prev[j];
			int take = 1e9;
			if (j >= coins[i])
				take = 1 +  prev[j - coins[i]];
			prev[j] = min(not_take, take);
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
		ans = minimium_coin_change_Optimisation(n , target, coins);
		cout << ans;
	}
}

// 9 1 5 6
// 11