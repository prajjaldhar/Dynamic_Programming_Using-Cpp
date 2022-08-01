#include<bits/stdc++.h>
using namespace std;
int fun_rec(int i, int j, int isTrue, string &exp)
{
	if (i > j)
		return 0;
	if (i == j)
	{
		if (isTrue)
			return (exp[i] == 'T');
		else
			return (exp[i] == 'F');
	}
	int ways = 0;
	for (int indx = i + 1; indx <= j - 1 ; indx += 2)
	{
		int LT = fun_rec(i, indx - 1, 1, exp);
		int LF = fun_rec(i, indx - 1, 0, exp);
		int RT = fun_rec(indx + 1, j, 1, exp);
		int RF = fun_rec(indx + 1, j, 0, exp);

		if (exp[indx] == '&')
		{
			if (isTrue)
				ways = ways + (LT * RT);
			else
				ways = ways + (RT * LF) + (RF * LT) + (RF * LF);
		}
		else if (exp[indx] == '|')
		{
			if (isTrue)
				ways = ways + (LT * RT) + (RT * LF) + (RF * LT);
			else
				ways = ways + (RF * LF);
		}
		else if (exp[indx] == '^')
		{
			if (isTrue)
				ways = ways + (RT * LF) + (RF * LT);
			else
				ways = ways + (RF * LF) + (LT * RT);
		}
	}
	return ways;
}

int fun_Memorization(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>>&dp)
{
	if (i > j)
		return 0;
	if (i == j)
	{
		if (isTrue)
			return (exp[i] == 'T');
		else
			return (exp[i] == 'F');
	}

	if (dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];

	int ways = 0;
	for (int indx = i + 1; indx <= j - 1 ; indx += 2)
	{
		int LT = fun_Memorization(i, indx - 1, 1, exp, dp);
		int LF = fun_Memorization(i, indx - 1, 0, exp, dp);
		int RT = fun_Memorization(indx + 1, j, 1, exp, dp);
		int RF = fun_Memorization(indx + 1, j, 0, exp, dp);

		if (exp[indx] == '&')
		{
			if (isTrue)
				ways = ways + (LT * RT);
			else
				ways = ways + (RT * LF) + (RF * LT) + (RF * LF);
		}
		else if (exp[indx] == '|')
		{
			if (isTrue)
				ways = ways + (LT * RT) + (RT * LF) + (RF * LT);
			else
				ways = ways + (RF * LF);
		}
		else if (exp[indx] == '^')
		{
			if (isTrue)
				ways = ways + (RT * LF) + (RF * LT);
			else
				ways = ways + (RF * LF) + (LT * RT);
		}
	}
	dp[i][j][isTrue] = ways;
	return ways;
}

fun_Dp(string &exp)
{
	int n = exp.size();
	vector<vector<vector<int>>>dp(n , vector<vector<int>>(n , vector<int>(2, 0)));
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == 'T')
		{
			dp[i][i][1] = 1;
		}
		else if (exp[i] == 'F')
		{
			dp[i][i][0] = 1;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j < n ; j++)
		{
			if (i > j)
				continue;

			for (int ind = i + 1; ind <= j - 1; ind += 2)
			{
				int LF = dp[i][ind - 1][0];
				int LT = dp[i][ind - 1][1];
				int RF = dp[ind + 1][j][0];
				int RT = dp[ind + 1][j][1];
				if (exp[ind] == '&')
				{
					dp[i][j][1] = dp[i][j][1] + (LT * RT) ;
					dp[i][j][0] = dp[i][j][0] + (LT * RF) + (LF * RT) + (LF * RF);

				}
				else if (exp[ind] == '|')
				{
					dp[i][j][1] = dp[i][j][1] + (LT * RT) + (LT * RF) + (LF * RT) ;
					dp[i][j][0] = dp[i][j][0] + (LF * RF) ;
				}
				else
				{
					dp[i][j][1] = dp[i][j][1] + (LT * RF) + (LF * RT) ;
					dp[i][j][0] = dp[i][j][0] + (LF * RF) + (LT * RT);
				}
			}
		}
	}
	return dp[0][n - 1][1];
}

fun_Dp_algo_approach(string &exp)
{
	int n = exp.size();
	vector<vector<int>>dpt(n , vector<int>(n, 0));
	vector<vector<int>>dpf(n , vector<int>(n, 0));
	for (int i = 0; i <= n; i++)
	{
		if (exp[i] == 'T')
		{
			dpt[i][i] = 1;
			dpf[i][i] = 0;
		}
		else if (exp[i] == 'F')
		{
			dpf[i][i] = 1;
			dpt[i][i] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j < n ; j++)
		{
			if (i > j)
				continue;

			for (int ind = i + 1; ind <= j - 1; ind += 2)
			{
				int LT = dpt[i][ind - 1];
				int RT = dpt[ind + 1][j];
				int LF = dpf[i][ind - 1];
				int RF = dpf[ind + 1][j];

				if (exp[ind] == '&')
				{
					dpt[i][j] = dpt[i][j] + (LT * RT) ;
					dpf[i][j] = dpf[i][j] + (LT * RF) + (LF * RT) + (LF * RF);

				}
				else if (exp[ind] == '|')
				{
					dpt[i][j] = dpt[i][j] + (LT * RT) + (LT * RF) + (LF * RT) ;
					dpf[i][j] = dpf[i][j] + (LF * RF) ;
				}
				else
				{
					dpt[i][j] = dpt[i][j] + (LT * RF) + (LF * RT) ;
					dpf[i][j] = dpf[i][j] + (LF * RF) + (LT * RT);
				}
			}
		}
	}
	for (auto i : dpt)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	for (auto i : dpf)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	return dpt[0][n - 1];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string exp = "T&F|T^F";
		int n = exp.length();
		int ans = 0;
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
		//ans = fun_rec(0, n - 1, 1, exp);
		//ans = fun_Memorization(0, n - 1, 1, exp, dp);
		//ans = fun_Dp(exp);
		ans = fun_Dp_algo_approach(exp);
		cout << ans;
	}
}

//8
// T | F ^ F ^ F & T
// F ^ T & T | F | F
// F ^ F | F & T | F ^ F
// F ^ F & T & T & F
// T ^ F | F ^ T | F
// T^T | F ^ F ^ F
// T | F | F ^ F ^ F
//T&F|T^F
// T | F ^ T & F | F & T