#include<bits/stdc++.h>
using namespace std;

int print_Paths(int n, int arr[])
{

	int dp[n + 1] = { -1};
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int minimum = INT_MAX;

		for (int j = 1; j <= arr[i] && i + j < (n + 1) ; j++)
		{
			if (dp[i + j] != -1)
			{
				minimum = min(minimum, dp[i + j]);
			}
		}
		if (minimum != INT_MAX)
		{
			dp[i] = minimum + 1;
		}
		else
		{
			dp[i] = -1;
		}
	}
	return dp[0];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		//Variable paths
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		int ans = print_Paths(n, arr);
		cout << ans;
	}
}