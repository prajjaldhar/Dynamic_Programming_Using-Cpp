#include<bits/stdc++.h>
using namespace std;
int Longest_Increasing_Subsequence_rec(int indx, int prev, vector<int>arr)
{
	if (indx == arr.size())
		return 0;
	int not_take, take = (-1e9);
	not_take = 0 + Longest_Increasing_Subsequence_rec(indx + 1, prev, arr);
	if (prev == -1 or arr[indx] > arr[prev])
		take = 1 + Longest_Increasing_Subsequence_rec(indx + 1, indx, arr);
	return max(not_take, take);
}
int Longest_Increasing_Subsequence_Memorization(int indx, int prev, vector<int>arr, vector<vector<int>>dp)
{
	if (indx == arr.size())
		return 0;
	if (dp[indx][prev + 1] != -1)
		return dp[indx][prev];
	int not_take, take = (-1e9);
	not_take = 0 + Longest_Increasing_Subsequence_Memorization(indx + 1, prev, arr, dp);
	if (prev == -1 or arr[indx] > arr[prev])
		take = 1 + Longest_Increasing_Subsequence_Memorization(indx + 1, indx, arr, dp);
	dp[indx][prev + 1] = max(not_take, take);
	return max(not_take, take);
}

int Longest_Increasing_Subsequence_Dp(vector<int>arr)
{
	int n = arr.size();
	vector<vector<int>>Dp(n + 1, vector<int>(n + 1 , 0));
	int not_take, take = (-1e9);
	for (int indx = n - 1 ; indx >= 0 ; --indx)
	{
		for (int prev = indx - 1 ; prev >= -1 ; --prev)
		{
			not_take = 0 + Dp[indx + 1][prev + 1];
			if (prev == -1 or arr[indx] > arr[prev + 1])
				take = 1 + Dp[indx + 1][indx + 1];
			Dp[indx][prev + 1] = max(not_take, take);
		}
	}
	for (auto i : Dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	return Dp[0][0];
}

int Longest_Increasing_Subsequence_Dp_Space_Optimised(vector<int>arr)
{
	int n = arr.size();
	vector<int>next(n + 1, 0);
	vector<int>current(n + 1 , 0);
	int not_take, take = (-1e9);
	for (int indx = n - 1 ; indx >= 0 ; --indx)
	{
		for (int prev = indx - 1 ; prev >= -1 ; --prev)
		{
			not_take = 0 + next[prev + 1];
			if (prev == -1 or arr[indx] > arr[prev + 1])
				take = 1 + next[indx + 1];
			current[prev + 1] = max(not_take, take);
		}
		next = current;
	}

	return current[0];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {10, 9, 2, 5, 3, 7, 101, 18};
		int n = arr.size();
		int ans = 0;
		vector<vector<int>>dp(n, vector<int>(n, -1));
		//ans = Longest_Increasing_Subsequence_rec(0, -1, arr); //f(ind1,ind2);
		//ans = Longest_Increasing_Subsequence_Memorization(0, -1, arr, dp);
		//ans = Longest_Increasing_Subsequence_Dp(arr);
		//ans = Longest_Increasing_Subsequence_Space_Optimised(s1.length(), s2.length(), s1, s2);
		//ans = Longest_Increasing_Subsequence_single_row_Space_Optimised(s1.length(), s2.length(), s1, s2);
		ans = Longest_Increasing_Subsequence_Dp_Space_Optimised(arr);
		cout << ans;
	}

}
//10, 9, 2, 5, 3, 7, 101, 18
//50, 3, 10, 7, 40, 80
//3, 10, 2, 1, 20
//10, 22, 9, 33, 21, 50, 41, 60, 80