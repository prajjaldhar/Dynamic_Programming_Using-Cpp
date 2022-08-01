#include<bits/stdc++.h>
using namespace std;
int Target_Sum_Subset_Dp(int n, int target, vector<int>arr)
{
	//i=n and j=target
	//dp[n][target]
	vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));
	for (int i = 0; i < n; ++i)
	{
		dp[i][0] = true;
	}
	if (arr[0] <= target)
		dp[0][arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			bool not_take = dp[i - 1][j];
			bool take = false;
			if (j >= arr[i])
				take = dp[i - 1] [j - arr[i]];
			dp[i][j] = (not_take) or (take);
		}
	}
	//print dp table

	for (auto ele : dp) {
		for (auto i : ele)
			cout << i << " ";
		cout << "\n";
	}

//i==target

	int minimum = 1e9;
	for (int i = 0; i <= target / 2; ++i)
	{
		if (dp[n - 1][i] == true)
		{
			int s1 = i;
			int s2 = target - i;
			minimum = min(minimum, abs(s1 - s2));
		}
	}
	return minimum;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int tot_sum = 0;
		vector<int>arr(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			tot_sum += arr[i];
		}
		int target = tot_sum;

		int ans = Target_Sum_Subset_Dp(n, target, arr);
		cout << ans;
	}
}
