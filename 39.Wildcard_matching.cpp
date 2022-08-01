//given 2 string find how many times str2 is appreaing on str1
#include<bits/stdc++.h>
using namespace std;
bool WildCard_Matching_rec(int ind1, int ind2, string s1, string s2)
{
	if (ind1 <= 0 && ind2 < 0)
		return true;
	if (ind1 < 0 && ind2 >= 0)
		return false;
	if (ind1 >= 0 && ind2 < 0)
	{
		for (int i = 0; i <= ind1; ++i)
		{
			if (s1[i] != '*')
				return false;
		}
		return true;
	}
	if (s1[ind1] == s2[ind2] || s1[ind1] == '?')
		return WildCard_Matching_rec(ind1 - 1, ind2 - 1, s1, s2);
	if (s1[ind1] == '*')
	{
		return WildCard_Matching_rec(ind1 - 1, ind2, s1, s2) or
		       WildCard_Matching_rec(ind1, ind2 - 1, s1, s2);
	}
	return false;
}

bool WildCard_Matching_memorization(int ind1, int ind2, string s1, string s2, vector<vector<int>>dp)
{
	if (ind1 <= 0 && ind2 < 0)
		return true;
	if (ind1 < 0 && ind2 >= 0)
		return false;
	if (ind1 >= 0 && ind2 < 0)
	{
		for (int i = 0; i <= ind1; ++i)
		{
			if (s1[i] != '*')
				return false;
		}
		return true;
	}
	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	if (s1[ind1] == s2[ind2] || s1[ind1] == '?' )
	{
		dp[ind1][ind2] = WildCard_Matching_memorization(ind1 - 1, ind2 - 1, s1, s2, dp);
		return WildCard_Matching_memorization(ind1 - 1, ind2 - 1, s1, s2, dp);
	}
	if (s1[ind1] == '*')
	{
		dp[ind1][ind2] = WildCard_Matching_memorization(ind1 - 1, ind2, s1, s2, dp) or
		                 WildCard_Matching_memorization(ind1, ind2 - 1, s1, s2, dp);
		return WildCard_Matching_memorization(ind1 - 1, ind2, s1, s2, dp) or
		       WildCard_Matching_memorization(ind1, ind2 - 1, s1, s2, dp); ;
	}
	return false;
}
int WildCard_Matching_DP(int ind1, int ind2, string s1, string s2)
{
	vector<vector<bool>>dp(ind1 + 1, vector<bool>(ind2 + 1, 0));
	//if(i==0 && j==0)
	dp[0][0] = true;
	//if(j>=0 && i==0)
	for (int j = 1; j <= ind2; ++j)
	{
		dp[0][j] = false;
	}
	//if(j==0 && i>=0)
	for (int i = 1; i <= ind1 ; ++i)
	{

		for (int m = 1; m <= i; ++m)
		{
			if (s1[m - 1] != '*')
			{
				dp[i][0] = false;
				break;
			}
			else
				dp[i][0] = true;
		}
	}
	for (int i = 1; i <= ind1; ++i)
	{
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (s1[i - 1] == '*')
				dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
			else
				dp[i][j] = false;
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

int WildCard_Matching_Space_Optimised(int ind1, int ind2, string s1, string s2)
{
	vector<bool>prev(ind2 + 1, 0);
	vector<bool>current(ind2 + 1, 0);
	prev[0] = true;
	//if(j>=0 && i==0)
	for (int j = 1; j <= ind2; ++j)
	{
		prev[j] = false;
	}
	//if(j==0 && i>=0)
	for (int i = 1; i <= ind1 ; ++i)
	{

		for (int m = 1; m <= i; ++m)
		{
			if (s1[m - 1] != '*')
			{
				current[i] = false;
				break;
			}
			else
				current[0] = true;
		}
	}
	for (int i = 1; i <= ind1; ++i)
	{
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
				current[j] = prev[j - 1];
			else if (s1[i - 1] == '*')
				current[j] = prev[j] or current[j - 1];
			else
				current[j] = false;
		}
		prev = current;
	}
	return prev[ind2] ;
}

int WildCard_Matching_single_row_Space_Optimised(int ind1, int ind2, string s1, string s2)
{
	vector<int>prev(ind2 + 1, 0);

	prev[0] = 1;
	for (int i = 1; i <= ind1; ++i)
	{

		for (int j = ind2; j >= 1; --j)
		{
			if (s1[i - 1] == s2[j - 1])
				prev[j] = prev[j - 1] ;
			else
			{
				int x = 1 + prev[j];
				//int y = 1 + current[j - 1];
				int z = 1 + prev[j - 1];
				prev[j] = min(x, z);
			}

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
		string s1 = "ab*?";
		string s2 = "abdfed";
		bool ans = 0;
		vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
		//ans = WildCard_Matching_rec(s1.length() - 1, s2.length() - 1, s1, s2); //f(ind1,ind2);
		//ans = WildCard_Matching_memorization(s1.length() - 1, s2.length() - 1, s1, s2, dp);
		//ans = WildCard_Matching_DP(s1.length(), s2.length(), s1, s2);
		ans = WildCard_Matching_Space_Optimised(s1.length(), s2.length(), s1, s2);
		//ans = WildCard_Matching_single_row_Space_Optimised(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}

// ABBDCACB
//bbabcbcab