//given 2 string find how many times str2 is appreaing on str1
#include<bits/stdc++.h>
using namespace std;
int LCS_rec(int ind1, int ind2, string s1, string s2)
{
	if (ind2 < 0)
		return 1;
	if (ind1 < 0)
		return 0;
	if (s1[ind1] == s2[ind2])
		return LCS_rec(ind1 - 1, ind2 - 1, s1, s2) + LCS_rec(ind1 - 1, ind2, s1, s2);
	else
		return LCS_rec(ind1 - 1, ind2, s1, s2);
}
int LCS_memorization(int ind1, int ind2, string s1, string s2, vector<vector<int>>dp)
{
	if (ind2 < 0)
		return 1;
	if (ind1 < 0)
		return 0;
	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	if (s1[ind1] == s2[ind2])
		return dp[ind1][ind2] = LCS_memorization(ind1 - 1, ind2 - 1, s1, s2, dp) + LCS_memorization(ind1 - 1, ind2, s1, s2, dp);
	else
		return dp[ind1][ind2] = LCS_memorization(ind1 - 1, ind2, s1, s2, dp);

}
int LCS_DP(int ind1, int ind2, string s1, string s2)
{
	vector<vector<int>>dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	for (int i = 0; i <= ind1; ++i)
	{
		dp[i][0] = 1;
	}
	// for (int j = 1; j <= ind2; ++j)
	// {
	// 	dp[0][j] = 0;
	// }
	for (int i = 1; i <= ind1; ++i)
	{
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
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
	return dp[ind1][ind2];
}

int LCS_Space_Optimised(int ind1, int ind2, string s1, string s2)
{
	vector<int>prev(ind2 + 1, 0);

	prev[0] = 1;
	for (int i = 1; i <= ind1; ++i)
	{
		vector<int>current(ind2 + 1, 0);
		current[0] = 1;
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				current[j] = prev[j - 1] + prev[j];
			else
				current[j] = prev[j];
		}
		prev = current;
	}
	return prev[ind2] ;
}

int LCS_single_row_Space_Optimised(int ind1, int ind2, string s1, string s2)
{
	vector<int>prev(ind2 + 1, 0);

	prev[0] = 1;
	for (int i = 1; i <= ind1; ++i)
	{

		for (int j = ind2; j >= 1; --j)
		{
			if (s1[i - 1] == s2[j - 1])
				prev[j] = prev[j - 1] + prev[j];
			else
				prev[j] = prev[j];//else has of no use
		}
	}
	return prev[ind2] ;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1 = "babgbag";
		string s2 = "bag";
		int ans = 0;
		vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
		//ans = LCS_rec(s1.length() - 1, s2.length() - 1, s1, s2); //f(ind1,ind2);
		//ans = LCS_memorization(s1.length() - 1, s2.length() - 1, s1, s2, dp);
		//ans = LCS_DP(s1.length(), s2.length(), s1, s2);
		//ans = LCS_Space_Optimised(s1.length(), s2.length(), s1, s2);
		ans = LCS_single_row_Space_Optimised(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}

// ABBDCACB
//bbabcbcab