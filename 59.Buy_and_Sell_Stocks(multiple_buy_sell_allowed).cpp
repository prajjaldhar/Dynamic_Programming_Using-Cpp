//after buying a stock we first have to sell that stock before buying new one
#include<bits/stdc++.h>
using namespace std;
int buy_sell(int indx, int buy, vector<int>&arr)
{
	int profit;
	if (buy)
	{
		profit = max(
		             -arr[indx] + buy_sell(indx + 1, 0, arr),
		             0 + buy_sell(indx + 1, 1, arr)
		         );
	}
	else
	{
		profit = max(
		             arr[indx] + buy_sell(indx + 1, 1, arr),
		             0 + buy_sell(indx + 1, 0, arr)
		         );

	}
	return profit;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {7, 1, 5, 3, 6, 4};
		int profit = buy_sell(0, 1, arr);
		cout << profit;
	}
}