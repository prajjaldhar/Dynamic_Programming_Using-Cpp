#include<bits/stdc++.h>
using namespace std;

int LCS_DP(int ind1, int ind2, string s1, string s2)
{
	vector<vector<int>>dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	int ans = 0;
	for (int i = 0; i <= ind1; ++i)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j <= ind2; ++j)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= ind1; ++i)
	{
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = 0;
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
	return ans;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1 = "adcf", s2 = "adck";
		int ans = 0;
		vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
		//ans = LCS_rec(s1.length() - 1, s2.length() - 1, s1, s2);
		ans = LCS_DP(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}