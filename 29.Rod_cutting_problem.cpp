#include<bits/stdc++.h>
using namespace std;
int rod_cutting_rec(int n, vector<int>price, int total_length)
{
	if (n == 0)
	{
		return total_length * price[0];
	}

	int not_take = 0 + rod_cutting_rec(n - 1, price, total_length);
	int take = (-1e9);
	int rod_length = n + 1;
	if (total_length >= rod_length)
		take = price[n] + rod_cutting_rec(n, price, total_length - rod_length);
	return max(take, not_take);
}

int rod_cutting_Memorization(int n, vector<int>price, int total_length, vector<int>dp)
{
	if (n == 0)
	{
		return total_length * price[0];
	}
	if (dp[n] != -1)
		return dp[n];
	int not_take = 0 + rod_cutting_Memorization(n - 1, price, total_length, dp);
	int take = (-1e9);
	int rod_length = n + 1;
	if (total_length >= rod_length)
		take = price[n] + rod_cutting_Memorization(n, price, total_length - rod_length, dp);
	dp[n] = max(not_take, take);
	return max(take, not_take);
}

int rod_cutting_Dp(int n, vector<int>price, int total_length)
{
	//i=n and j=total_length
	//dp[n][total_length]
	vector<vector<int>>dp(n, vector<int>(total_length + 1, 0));
	for (int i = 0; i <= total_length; ++i)
	{
		dp[0][i] = i * price[0];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= total_length; ++j)
		{
			int not_take = 0 + dp[i - 1][j];
			int take = (-1e9);
			int rod_length = i + 1;
			if (rod_length <= j)
				take = price[i] + dp[i] [j - rod_length];
			dp[i][j] = max(not_take, take);
		}
	}

	//dp_table
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}

	return dp[n - 1][total_length];
}


int rod_cutting_Optimisation(int n, vector<int>price, int total_length)
{
	//i=n and j=price
	//dp[n][price]
	vector<int>prev(total_length + 1, 0);
	for (int i = 0; i <= total_length; ++i)
	{
		prev[i] = i * price[0];
	}
	for (int i = 1; i < n; ++i)
	{
		vector<int>current(total_length + 1, 0);
		for (int j = 0; j <= total_length; ++j)
		{
			int not_take = 0 + prev[j];
			int take = (-1e9);
			int rod_length = i + 1;
			if (rod_length <= j)
				take = price[i] + current [j - rod_length];
			current[j] = max(not_take, take);
		}
		prev = current;
	}

	return prev[total_length];
}

//

int rod_cutting_single_row_Optimisation(int n, vector<int>price, int total_length)
{
	//i=n and j=price
	//dp[n][price]
	vector<int>prev(total_length + 1, 0);
	for (int i = 0; i <= total_length; ++i)
	{
		prev[i] = i * price[0];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= total_length; ++j)
		{
			int not_take = 0 + prev[j];
			int take = -1e9;
			int rod_length = i + 1;
			if (rod_length <= j)
				take = price[i] + prev[j - rod_length];
			prev[j] = max(not_take, take);
		}
	}

	return prev[total_length];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, total_length;
		cin >> n;
		vector<int>price(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> price[i];
		}
		cin >> total_length;
		int ans = 0;
		//ans = rod_cutting_rec(n - 1, price, total_length);
		vector<int>dp(n, -1);
		//ans = rod_cutting_Memorization(n - 1, price, total_length, dp);
		ans = rod_cutting_Dp(n , price, total_length);
		//ans = rod_cutting_Optimisation(n , price, total_length);
		//ans = rod_cutting_single_row_Optimisation(n , price, total_length);
		cout << ans;
	}
}

// 5
// 2 5 7 8 10
// 5

//3   5   8   9  10  17  17  20