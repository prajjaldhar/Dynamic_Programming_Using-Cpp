#include<bits/stdc++.h>
using namespace std;
int isPallindrome(string str)
{
	string temp = str;
	reverse(str.begin(), str.end());
	if (str == temp)
		return 1;
	else
		return 0;
}
int pallindrome_partition_rec(int i, string str)
{
	int n = str.length();
	if (i == n)
		return 0;
	string temp = "";
	int minimum = 1e9;
	int cost;
	for (int j = i; j < n; ++j)
	{
		temp += str[j];
		if (isPallindrome(temp))
		{
			cost = 1 + pallindrome_partition_rec(j + 1, str);
			//minimum = min(minimum, cost);
		}
		minimum = min(minimum, cost);
	}
	return minimum;
}

int pallindrome_partition_memorization(int i, string str, vector<int>dp)
{
	int n = str.length();
	if (i == n)
		return 0;
	string temp = "";
	if (dp[i] != 0)
		return dp[i];
	int minimum = 1e9;
	int cost;
	for (int j = i; j < n; ++j)
	{
		temp += str[j];
		if (isPallindrome(temp))
		{
			cost = 1 + pallindrome_partition_memorization(j + 1, str, dp);
			//minimum = min(minimum, cost);
		}
		minimum = min(minimum, cost);
	}
	dp[i] = minimum;
	return minimum;
}

int pallindrome_partition_Dp(string str)
{
	int n = str.length();
	vector<int>dp(n + 1, 0);
	for (int i = n - 1; i >= 0 ; --i)
	{
		string temp = "";
		int minimum = 1e9;
		int cost;
		for (int j = i; j < n; ++j)
		{
			temp += str[j];
			if (isPallindrome(temp))
			{
				cost = 1 + dp[j + 1];
				//minimum = min(minimum, cost);
			}
			minimum = min(minimum, cost);
		}
		dp[i] = minimum;
	}
	return dp[0];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str = "bababcbadcede";
		int ans = 0;
		int n = str.length();
		vector<int>dp(n + 1, 0);
		//ans = pallindrome_partition_rec(0, str);
		//ans = pallindrome_partition_memorization(0, str, dp);
		ans = pallindrome_partition_Dp(str);
		cout << ans - 1;
	}
}