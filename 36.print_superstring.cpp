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
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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

	int length = dp[ind1][ind2];
	string ans = "";
	int i = ind1, j = ind2;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1]) //matched condition
		{
			ans += s1[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			ans += s1[i - 1];
			i = i - 1;
		}
		else
		{
			ans += s2[j - 1];
			j = j - 1;
		}
	}
	while (i > 0)
	{
		ans += s1[i - 1];
		i--;
	}
	while (j > 0)
	{
		ans += s2[j - 1];
		j--;
	}
	return string(ans.rbegin(), ans.rend());
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1 = "brute", s2 = "groot";
		string ans;
		ans = LCS_DP(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}