#include<bits/stdc++.h>
using namespace std;
int egg_drop_rec(int eggs, int floor)
{
	if (eggs <= 0)
		return 0;
	if (floor < 0)
		return 0;
	if (eggs == 1)
		return floor;//floor == kth floor
	if (floor == 0 || floor == 1)
		return floor;//here floor value = attempt value
	int temp;
	int minimum = 1e9;
	for (int k = 1; k <= floor ; ++k)
	{
		temp = 1 + max(egg_drop_rec(eggs - 1, k - 1), egg_drop_rec(eggs, floor - k));
		minimum = min(minimum, temp);
	}
	return minimum;
}
int egg_drop_memorization(int eggs, int floor, vector<vector<int>>&dp)
{
	if (eggs <= 0)
		return 0;
	if (floor < 0)
		return 0;
	if (eggs == 1)
		return floor;
	if (dp[eggs][floor] != -1)
		return dp[eggs][floor];
	if (floor == 0 || floor == 1)
		return floor;//here floor value = attempt value
	int temp;
	int minimum = 1e9;
	for (int k = 1; k <= floor ; ++k)
	{
		temp = 1 + max(egg_drop_memorization(eggs - 1, k - 1, dp), egg_drop_memorization(eggs, floor - k, dp));
		minimum = min(minimum, temp);
	}
	dp[eggs][floor] = minimum;
	return minimum;
}

int egg_drop_Dp(int eggs, int floor)
{
	vector<vector<int>>dp(eggs + 1, vector<int>(floor + 1, 0));

	for (int j = 1; j <= floor; j++)
		dp[1][j] = j;

	for (int egg = 1; egg <= eggs ; ++egg)
	{
		dp[egg][1] = 1;
		dp[egg][0] = 0;
	}

	for (int egg = 2; egg <= eggs; ++egg)
	{
		for (int j = 2; j <= floor; ++j)
		{
			int temp;
			int minimum = 1e9;
			for (int k = 1; k <= j ; ++k)
			{
				temp = 1 + max(dp[egg - 1][k - 1], dp[egg][j - k] );
				minimum = min(minimum, temp);
			}
			dp[egg][j] = minimum;
		}
	}
	//dp table
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	return dp[eggs][floor];
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int eggs = 2;
		int floor = 36;
		int ans = 0;
		//ans = egg_drop_rec(eggs, floor);
		vector<vector<int>>dp(eggs + 1, vector<int>(floor + 1, -1));
		//ans = egg_drop_memorization(eggs, floor, dp);
		ans = egg_drop_Dp(eggs, floor);
		cout << ans;
	}
}