#include<bits/stdc++.h>
using namespace std;
int LCS_rec(int ind1, int ind2, string s1, string s2)
{
	if (ind1 < 0 or ind2 < 0)
		return 0;
	//match condition
	// int match = (-1e9);
	// int not_match = (-1e9);
	// if (s1[ind1] == s2[ind2])
	// 	match = 1 + LCS_rec(ind1 - 1, ind2 - 1, s1, s2);
	// not_match = 0 + max(LCS_rec(ind1 - 1, ind2, s1, s2), LCS_rec(ind1, ind2 - 1, s1, s2));
	// return max(match, not_match);
	if (s1[ind1] == s2[ind2])
		return 1 + LCS_rec(ind1 - 1, ind2 - 1, s1, s2);
	return max(LCS_rec(ind1 - 1, ind2, s1, s2), LCS_rec(ind1, ind2 - 1, s1, s2));

}
int LCS_memorization(int ind1, int ind2, string s1, string s2, vector<vector<int>>dp)
{
	if (ind1 < 0 or ind2 < 0)
		return 0;
	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	//match condition
	int match = (-1e9);
	int not_match = (-1e9);
	if (s1[ind1] == s2[ind2])
		match = 1 + LCS_memorization(ind1 - 1, ind2 - 1, s1, s2, dp);
	not_match = 0 + max(LCS_memorization(ind1 - 1, ind2, s1, s2, dp), LCS_memorization(ind1, ind2 - 1, s1, s2, dp));
	dp[ind1][ind2] = max(match, not_match);
	return max(match, not_match);
}
int LCS_DP(int ind1, int ind2, string s1, string s2)
{
	vector<vector<int>>dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	int match = (-1e9);
	int not_match = (-1e9);
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
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
	int match = (-1e9);
	int not_match = (-1e9);
	for (int i = 0; i <= ind1; ++i)
	{
		prev[0] = 0;
	}
	for (int i = 1; i <= ind1; ++i)
	{
		vector<int>current(ind2 + 1, 0);
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				match = 1 + prev[j - 1];
			not_match = 0 + max(prev[j], current[j - 1]);
			current[j] = max(match, not_match);
		}
		prev = current;
	}
	return prev[ind2] ;
}

int minimumInsertion(string s1, string s2)
{

	int ans = 0;
	vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
	//ans = LCS_rec(s1.length() - 1, s2.length() - 1, s1, s2); //f(ind1,ind2);
	//ans = LCS_memorization(s1.length() - 1, s2.length() - 1, s1, s2, dp);
	ans = LCS_DP(s1.length(), s2.length(), s1, s2);
	//ans = LCS_Space_Optimised(s1.length(), s2.length(), s1, s2);
	cout << ans << "\n";
	int deletion = s1.length() - ans;
	int insertion = s2.length() - ans;
	return deletion + insertion;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1 = "sooraj";
		string s2 = "prajjal";
		int ans;
		ans = minimumInsertion(s1, s2);
		cout << ans;
	}
}

// ABBDCACB
//bbabcbcab