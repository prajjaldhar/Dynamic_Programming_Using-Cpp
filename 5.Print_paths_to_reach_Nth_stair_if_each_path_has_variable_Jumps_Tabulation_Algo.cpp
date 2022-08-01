#include<bits/stdc++.h>
using namespace std;

int print_Paths(int n, int arr[])
{

	int dp[n + 1] = {0};
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= arr[i] && i + j < (n + 1) ; j++)
		{
			dp[i] += dp[i + j];
		}
	}
	// for (int i = 0; i < n + 1; ++i)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n";
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