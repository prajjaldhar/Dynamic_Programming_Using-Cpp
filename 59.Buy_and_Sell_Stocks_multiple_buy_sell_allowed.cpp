//after buying a stock we first have to sell that stock before buying new one
#include<bits/stdc++.h>
using namespace std;
int buy_sell_rec(int indx, int buy, vector<int>&arr)
{

	if (indx == arr.size())
		return 0;

	int profit;
	if (buy)
	{
		profit = max(
		             -arr[indx] + buy_sell_rec(indx + 1, 0, arr),
		             0 + buy_sell_rec(indx + 1, 1, arr)
		         );
	}
	else
	{
		profit = max(
		             arr[indx] + buy_sell_rec(indx + 1, 1, arr),
		             0 + buy_sell_rec(indx + 1, 0, arr)
		         );

	}
	return profit;
}

int buy_sell_memorization(int indx, int buy, vector<int>&arr, vector<vector<int>>&dp)
{

	if (indx == arr.size())
		return 0;

	int profit;
	if (dp[indx][buy] != -1)
		return dp[indx][buy];
	if (buy)
	{
		profit = max(
		             -arr[indx] + buy_sell_memorization(indx + 1, 0, arr, dp),
		             0 + buy_sell_memorization(indx + 1, 1, arr, dp)
		         );
	}
	else
	{
		profit = max(
		             arr[indx] + buy_sell_memorization(indx + 1, 1, arr, dp),
		             0 + buy_sell_memorization(indx + 1, 0, arr, dp)
		         );

	}
	dp[indx][buy] = profit;
	return profit;
}

int buy_sell_Dp(vector<int>&arr)
{
	int n = arr.size();
	vector<vector<int>>dp(n + 1, vector<int>(2, 0)); //dp[n=0]
	dp[n][1] = 0;
	dp[n][0] = 0;
	for (int indx = n - 1; indx >= 0 ; --indx)
	{
		for (int buy = 0; buy <= 1; ++buy)
		{

			int profit;

			if (buy)
			{
				profit = max(
				             -arr[indx] + dp[indx + 1][0],
				             0 + dp[indx + 1] [1]
				         );
			}
			else
			{
				profit = max(
				             arr[indx] + dp[indx + 1][1] ,
				             0 + dp[indx + 1][0]
				         );

			}
			dp[indx][buy] = profit;

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

	return dp[0][1];
}

int buy_sell_Dp_1D_space_optimisation(vector<int>&arr)
{
	int n = arr.size();
	vector<int>temp(n + 1, 0);
	temp[1] = 0;
	temp[0] = 0;
	for (int indx = n - 1; indx >= 0 ; --indx)
	{
		vector<int>curr(2, 0);
		for (int buy = 0; buy <= 1; ++buy)
		{

			int profit;

			if (buy)
			{
				profit = max(
				             -arr[indx] + temp[0],
				             0 + temp[1]
				         );
			}
			else
			{
				profit = max(
				             arr[indx] + temp[1] ,
				             0 + temp[0]
				         );

			}
			curr[buy] = profit;
		}
		temp = curr;
	}

	return temp[1];
}

int buy_sell_variable_method(vector<int>arr)
{
	int n = arr.size();
	int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;
	for (int indx = n - 1; indx >= 0 ; --indx)
	{

		currBuy = max(
		              -arr[indx] + aheadNotBuy,
		              0 + aheadBuy
		          );

		currNotBuy = max(
		                 arr[indx] + aheadBuy ,
		                 0 + aheadNotBuy
		             );


		aheadBuy = currBuy;
		aheadNotBuy = currNotBuy;
	}
	return aheadBuy;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {7, 1, 5, 3, 6, 4};
		int profit = 0;
		int n = arr.size();
		vector<vector<int>>dp(n + 1, vector<int>(2, -1));
		//profit = buy_sell_rec(0, 1, arr);
		//profit = buy_sell_memorization(0, 1, arr, dp);
		//profit = buy_sell_Dp(arr);
		profit = buy_sell_Dp_1D_space_optimisation(arr);
		profit = buy_sell_variable_method(arr);
		cout << profit;
	}
}