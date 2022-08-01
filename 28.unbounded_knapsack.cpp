#include<bits/stdc++.h>
using namespace std;
int knapsack_unbounded_rec(int n, vector<int>weight, vector<int>value, int bag_weight)
{
	if (n == 0)
	{
		if (weight[0] <= bag_weight)
			return (bag_weight / weight[0]) * value[0];
		else
			return 0;
	}
	if (bag_weight == 0)
		return 0;
	int not_take = 0 + knapsack_unbounded_rec(n - 1, weight, value, bag_weight);
	int take = (-1e9);
	if (weight[n] <= bag_weight)
		take = value[n] + knapsack_unbounded_rec(n, weight, value, bag_weight - weight[n]);
	return max(take, not_take);
}

int knapsack_unbounded_Memorization(int n, vector<int>weight, vector<int>value, int bag_weight, vector<int>dp)
{
	if (n == 0)
	{
		if (weight[0] <= bag_weight)
			return (bag_weight / weight[0]) * value[0];
		else
			return 0;
	}
	if (dp[n] != -1)
		return dp[n];
	int not_take = 0 + knapsack_unbounded_Memorization(n - 1, weight, value, bag_weight, dp);
	int take = (-1e9);
	if (weight[n] <= bag_weight)
		take = value[n] + knapsack_unbounded_Memorization(n , weight, value, bag_weight - weight[n], dp);
	dp[n] = max(not_take, take);
	return max(take, not_take);
}

int knapsack_unbounded_Dp(int n, vector<int>weight, vector<int>value, int bag_weight)
{
	//i=n and j=weight
	//dp[n][weight]
	vector<vector<int>>dp(n, vector<int>(bag_weight + 1, 0));
	for (int i = weight[0]; i <= bag_weight; ++i)
	{
		dp[0][i] = int(i / weight[0]) * value[0];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= bag_weight; ++j)
		{
			int not_take = 0 + dp[i - 1][j];
			int take = (-1e9);
			if (weight[i] <= j)
				take = value[i] + dp[i] [j - weight[i]];
			dp[i][j] = max(not_take, take);
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
	return dp[n - 1][bag_weight];
}


int knapsack_unbounded_Optimisation(int n, vector<int>weight, vector<int>value, int bag_weight)
{
	//i=n and j=weight
	//dp[n][weight]
	vector<int>prev(bag_weight + 1, 0);
	for (int i = weight[0]; i <= bag_weight; ++i)
	{
		prev[i] = (i / weight[0]) * value[0];
	}
	for (int i = 1; i < n; ++i)
	{
		vector<int>current(bag_weight + 1, 0);
		for (int j = 0; j <= bag_weight; ++j)
		{
			int not_take = 0 + prev[j];
			int take = -1e9;
			if (weight[i] <= j)
				take = value[i] + current[j - weight[i]];
			current[j] = max(not_take, take);
		}
		prev = current;
	}

	return prev[bag_weight];
}

//

int knapsack_unbounded_single_row_Optimisation(int n, vector<int>weight, vector<int>value, int bag_weight)
{
	//i=n and j=weight
	//dp[n][weight]
	vector<int>prev(bag_weight + 1, 0);
	for (int i = weight[0]; i <= bag_weight; ++i)
	{
		prev[i] = (i / weight[0]) * value[0];
	}
	for (int i = 1; i < n; ++i)
	{

		for (int j = 0; j <= bag_weight; ++j)
		{
			int not_take = 0 + prev[j];
			int take = -1e9;
			if (weight[i] <= j)
				take = value[i] + prev[j - weight[i]];
			prev[j] = max(not_take, take);
		}
	}

	return prev[bag_weight];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, bag_weight;
		cin >> n;
		vector<int>weight(n, 0);
		vector<int>value(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> weight[i] >> value[i];
		}
		cin >> bag_weight;
		int ans = 0;
		//ans = knapsack_unbounded_rec(n - 1, weight, value, bag_weight);
		vector<int>dp(n, -1);
		//ans = knapsack_unbounded_Memorization(n - 1, weight, value, bag_weight, dp);
		//ans = knapsack_unbounded_Dp(n , weight, value, bag_weight);
		//ans = knapsack_unbounded_Optimisation(n , weight, value, bag_weight);
		ans = knapsack_unbounded_single_row_Optimisation(n , weight, value, bag_weight);
		cout << ans;
	}
}

// 3
// 2 5
// 4 11
// 6 13
// 10