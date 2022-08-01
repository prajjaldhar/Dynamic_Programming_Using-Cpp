#include<bits/stdc++.h>
using namespace std;
int Partition_arr_rec(int i, int k, vector<int>&arr)
{
	int n = arr.size();
	if (i == n)
		return 0;
	int maximum = -1e9;
	int sum;
	int length = 0;
	int maxAns = -1e9;
	for (int j = i; j < min(n, i + k); ++j)
	{
		length++;
		maximum = max(maximum, arr[j]);
		sum = (length * maximum) + Partition_arr_rec(j + 1, k, arr);
		maxAns = max(maxAns, sum);
	}
	return maxAns;
}

int Partition_arr_memorization(int i, int k, vector<int>arr, vector<int>dp)
{
	int n = arr.size();
	if (i == n)
		return 0;

	if (dp[i] != -1)
		return dp[i];
	int maximum = -1e9;
	int sum;
	int length = 0;
	int maxAns = -1e9;
	for (int j = i; j < min(n, i + k); ++j)
	{
		length++;
		maximum = max(maximum, arr[j]);
		sum = (length * maximum) + Partition_arr_rec(j + 1, k, arr);
		maxAns = max(maxAns, sum);
	}
	dp[i] = maxAns;
	return maxAns;
}

int Partition_arr_Dp(int k, vector<int> arr)
{
	int n = arr.size();
	vector<int>dp(n + 1, 0);
	for (int i = n - 1; i >= 0 ; --i)
	{
		int maximum = -1e9;
		int sum;
		int length = 0;
		int maxAns = -1e9;
		for (int j = i; j < min(n, i + k); ++j)
		{
			length++;
			maximum = max(maximum, arr[j]);
			sum = (length * maximum) + dp[j + 1];
			maxAns = max(maxAns, sum);
		}
		dp[i] = maxAns;
	}
	return dp[0];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {1, 15, 7, 9, 2, 5, 10};
		int ans = 0;
		int n = arr.size();
		int k = 3;
		vector<int>dp(n + 1, -1);
		//ans = Partition_arr_rec(0, k, arr);
		//ans = Partition_arr_memorization(0, k, arr, dp);
		ans = Partition_arr_Dp(k, arr);
		cout << ans;
	}
}