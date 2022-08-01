//after buying a stock we first have to sell that stock before buying new one
#include<bits/stdc++.h>
using namespace std;
int buy_sell_rec(int indx, int buy, int cap, vector<int>&arr)
{

	if (indx == arr.size())
		return 0;
	if (cap == 0)
		return 0;
	int profit;
	if (buy)
	{
		profit = max(
		             -arr[indx] + buy_sell_rec(indx + 1, 0, cap, arr),
		             0 + buy_sell_rec(indx + 1, 1, cap, arr)
		         );
	}
	else
	{
		profit = max(
		             arr[indx] + buy_sell_rec(indx + 1, 1, cap - 1, arr),
		             0 + buy_sell_rec(indx + 1, 0, cap, arr)
		         );

	}
	return profit;
}

int buy_sell_memorization(int indx, int buy, int cap, vector<int>&arr, vector<vector<vector<int>>>&dp)
{

	if (indx == arr.size())
		return 0;
	if (cap == 0)
		return 0;
	int profit;
	if (dp[indx][buy][cap] != -1)
		return dp[indx][buy][cap];
	if (buy)
	{
		profit = max(
		             -arr[indx] + buy_sell_memorization(indx + 1, 0, cap, arr, dp),
		             0 + buy_sell_memorization(indx + 1, 1, cap, arr, dp)
		         );
	}
	else
	{
		profit = max(
		             arr[indx] + buy_sell_memorization(indx + 1, 1, cap - 1, arr, dp),
		             0 + buy_sell_memorization(indx + 1, 0, cap, arr, dp)
		         );

	}
	dp[indx][buy][cap] = profit;
	return profit;
}

int buy_sell_Dp(vector<int>&arr)
{
	int n = arr.size();
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); //dp[n=0]
	for (int i = 0; i < n - 1; ++i)
	{
		dp[n][0][0] = 0;
		dp[n][1][0] = 0;
	}
	for (int cap = 0; cap <= 2; ++cap)
	{
		dp[n][0][cap] = 0;
		dp[n][1][cap] = 0;
	}

	for (int indx = n - 1; indx >= 0 ; --indx)
	{
		for (int buy = 0; buy <= 1; ++buy)
		{
			for (int cap = 0; cap <= 2; ++cap)
			{
				int profit;

				if (buy)
				{
					profit = max(
					             -arr[indx] + dp[indx + 1][0][cap],
					             0 + dp[indx + 1] [1][cap]
					         );
				}
				else
				{
					profit = max(
					             arr[indx] + dp[indx + 1][1][cap - 1] ,
					             0 + dp[indx + 1][0][cap]
					         );

				}
				dp[indx][buy][cap] = profit;
			}
		}
	}

	return dp[0][1][2];
}

int buy_sell_Dp_1D_space_optimisation(vector<int>&arr)
{
	int n = arr.size();
	vector<vector<int>>temp(2, vector<int>(3, 0));

	for (int indx = n - 1; indx >= 0 ; --indx)
	{
		vector<vector<int>>current(2, vector<int>(3, 0));
		for (int buy = 0; buy <= 1; ++buy)
		{
			for (int cap = 0; cap <= 2; cap++)
			{
				int profit;

				if (buy)
				{
					profit = max(
					             -arr[indx] + temp[0][cap],
					             0 + temp[1][cap]
					         );
				}
				else
				{
					profit = max(
					             arr[indx] + temp[1][cap - 1] ,
					             0 + temp[0][cap]
					         );

				}
				current[buy][cap] = profit;
			}
			temp = current;
		}
	}

	return temp[1][2];
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {3, 3, 5, 0, 0, 3, 1, 4};
		int profit = 0;
		int n = arr.size();
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
		//profit = buy_sell_rec(0, 1, 2, arr);
		//profit = buy_sell_memorization(0, 1, 2, arr, dp);
		//profit = buy_sell_Dp(arr);
		profit = buy_sell_Dp_1D_space_optimisation(arr);
		cout << profit;
	}
}