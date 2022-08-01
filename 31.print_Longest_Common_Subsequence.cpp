#include<bits/stdc++.h>
using namespace std;

string LCS_DP(int ind1, int ind2, string s1, string s2)
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
				dp[i][j] =  max(dp[i - 1][j], dp[i][j - 1]);

		}
	}

	//dp table
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}

	int length = dp[ind1][ind2];
	string ans = "";
	for (int i = 0; i < length; ++i)
	{
		ans += "$";
	}
	int index = length - 1;
	int i = ind1, j = ind2;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1]) //matched condition
		{
			ans[index] = s1[i - 1];
			index--;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i = i - 1;
		}
		else
		{
			j = j - 1;
		}
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1 = "bleed", s2 = "blue";
		string ans;
		ans = LCS_DP(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}
//bleed blue
//red rose
//brute groot