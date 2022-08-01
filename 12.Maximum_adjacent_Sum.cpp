#include<bits/stdc++.h>
using namespace std;
int sumRec(int indx, vector<int>arr)
{
	if (indx == 0)
		return arr[indx];
	if (indx < 0)
		return 0;
	//yes call
	int sume, sumo;
	sume = arr[indx] + sumRec(indx - 2, arr);
	//no call
	sumo = 0 + sumRec(indx - 1, arr);
	return max(sume, sumo);
}

int sumMemo(int indx, vector<int>arr, vector<int>&dp)
{
	if (indx == 0)
		return arr[indx];
	if (indx < 0)
		return 0;
	if (dp[indx] != 0) return dp[indx];
	//yes call
	int sume, sumo;
	sume = arr[indx] + sumMemo(indx - 2, arr, dp);
	//no call
	sumo = 0 + sumMemo(indx - 1, arr, dp);
	dp[indx] = max(sume, sumo);
	return max(sume, sumo);
}

int sumTab(int n, vector<int>&arr)
{
	vector<int>dp(n, 0);
	dp[0] = 0;
	int take, nontake;
	for (int i = 1; i <= n; ++i)
	{
		take = arr[i];
		if (i > 1)
			take += dp[i - 2];
		nontake = 0 + dp[i - 1];
		dp[i] = max(take, nontake);
	}
	return dp[n - 1];
}

int sumOptimisation(int n, vector<int>arr)
{
	int prev = 0, prev2 = 0, curr;
	int take, nontake;
	for (int i = 1; i <= n; ++i)
	{
		take = arr[i];
		if (i > 1)
			take += prev2;
		nontake = 0 + prev;
		curr = max(take, nontake);
		prev2 =	prev;
		prev = curr;
	}
	return prev;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n = 4;
		vector<int>arr = {1, 2, 4, 9};
		vector<int>dp(n, 0);
		int ans = sumRec(n - 1, arr);
		cout << ans << "\n";
		ans = sumTab(n, arr);
		cout << ans << "\n";
		ans = sumMemo(n - 1, arr, dp);
		cout << ans << "\n";
		ans = sumOptimisation(n - 1, arr);
		cout << ans;
	}
}

