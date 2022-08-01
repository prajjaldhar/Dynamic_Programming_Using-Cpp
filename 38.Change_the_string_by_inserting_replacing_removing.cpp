//given 2 string find how many times str2 is appreaing on str1
#include<bits/stdc++.h>
using namespace std;
int LCS_rec(int ind1, int ind2, string s1, string s2)
{
	if (ind1 < 0)
		return ind2 + 1;
	if (ind2 < 0)
		return ind1 + 1;
	if (s1[ind1] == s2[ind2])
		return LCS_rec(ind1 - 1, ind2 - 1, s1, s2);
	else
	{
		int x = 1 + LCS_rec(ind1 - 1, ind2, s1, s2); //delete operation
		int y = 1 + LCS_rec(ind1, ind2 - 1, s1, s2); //insert operation(considering hypothetical matching of last character)
		int z = 1 + LCS_rec(ind1 - 1, ind2 - 1, s1, s2); //replace operation
		return min(x, min(y, z));
	}
}

int LCS_memorization(int ind1, int ind2, string s1, string s2, vector<vector<int>>dp)
{
	if (ind1 < 0)
		return ind2 + 1;
	if (ind2 < 0)
		return ind1 + 1;
	if (dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
	if (s1[ind1] == s2[ind2])
	{
		dp[ind1][ind2] = LCS_memorization(ind1 - 1, ind2 - 1, s1, s2, dp);
		return LCS_memorization(ind1 - 1, ind2 - 1, s1, s2, dp);
	}
	else
	{
		int x = 1 + LCS_memorization(ind1 - 1, ind2, s1, s2, dp); //delete operation
		int y = 1 + LCS_memorization(ind1, ind2 - 1, s1, s2, dp); //insert operation(considering hypothetical matching of last character)
		int z = 1 + LCS_memorization(ind1 - 1, ind2 - 1, s1, s2, dp); //replace operation
		dp[ind1][ind2] = min(x, min(y, z));
		return min(x, min(y, z));
	}

}
int LCS_DP(int ind1, int ind2, string s1, string s2)
{
	vector<vector<int>>dp(ind1 + 1, vector<int>(ind2 + 1, 0));

	//if(j==0)
	for (int i = 0; i <= ind1; ++i)
	{
		dp[i][0] = i;
	}


	for (int j = 0; j <= ind2; ++j)
	{
		dp[0][j] = j;
	}


	for (int i = 1; i <= ind1; ++i)
	{
		for (int j = 1; j <= ind2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				int x = 1 + dp[i - 1][j]; //delete operation
				int y = 1 + dp[i][j - 1]; //insert operation(considering hypothetical matching of last character)
				int z = 1 + dp[i - 1][j - 1] ; //replace operation
				dp[i][j] = min(x, min(y, z));
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
				current[j] = prev[j - 1];
			else
			{
				int x = 1 + prev[j];
				int y = 1 + current[j - 1];
				int z = 1 + prev[j - 1];
				current[j] = min(x, min(y, z));
			}
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
		string s1 = "book";
		string s2 = "rok";
		int ans = 0;
		vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
		//ans = LCS_rec(s1.length() - 1, s2.length() - 1, s1, s2); //f(ind1,ind2);
		ans = LCS_memorization(s1.length() - 1, s2.length() - 1, s1, s2, dp);
		//ans = LCS_DP(s1.length(), s2.length(), s1, s2);
		//ans = LCS_Space_Optimised(s1.length(), s2.length(), s1, s2);
		//ans = LCS_single_row_Space_Optimised(s1.length(), s2.length(), s1, s2);
		cout << ans;
	}
}

// ABBDCACB
//bbabcbcab