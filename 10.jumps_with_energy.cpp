//you can take either 1 or 2 jump and each jump is associated with some energy
#include<bits/stdc++.h>
using namespace std;
int jumprec(int indx, vector<int>&energy)
{
	if (indx == 0)
		return 0;
	if (indx < 0)
		return 0;
	int left = jumprec(indx - 1, energy) + abs(energy[indx] - energy[indx - 1]);
	int right = INT_MAX;
	if (indx > 1)
		right = jumprec(indx - 2, energy) + abs(energy[indx] - energy[indx - 2]);
	return min(left, right)  ;
}

int jumpMemo(int indx, vector<int>&energy, vector<int>&dp)
{
	if (indx == 0)
		return 0;
	if (indx < 0)
		return 0;
	if (dp[indx] != -1)return dp[indx];
	int left = jumpMemo(indx - 1, energy, dp) + abs(energy[indx] - energy[indx - 1]);
	int right = INT_MAX;
	if (indx > 1)
		right = jumpMemo(indx - 2, energy, dp) + abs(energy[indx] - energy[indx - 2]);
	return dp[indx] = min(left, right)  ;
}

int dpTabulation(int n, vector<int>&energy)
{
	vector<int>dp(n, 0);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int f = dp[i - 1] + abs(energy[i] - energy[i - 1]);
		int s = INT_MAX;
		if (i > 1)
			s = dp[i - 2] + abs(energy[i] - energy[i - 2]);
		dp[i] = min(f, s);
	}
	return dp[n - 1];
}

int jumpOptimisation(int n, vector<int>&energy)
{
	int curr, prev = 0, prev2 = 0;
	for (int i = 1; i < n ; ++i)
	{
		int f = prev + abs(energy[i] - energy[i - 1]);
		int s = INT_MAX;
		if (i > 1)
			s = prev2 + abs(energy[i] - energy[i - 2]);
		curr = min(f, s);
		prev2 = prev;
		prev = curr;

	}
	return prev;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>energy = {30, 10, 60, 10, 60, 50};
		vector<int>dp(n + 1, -1);
		//int ans = jumprec(n - 1, energy);
		//int ans = jumpMemo(n - 1 , energy, dp);
		//int ans = dpTabulation(n, energy);
		int ans = jumpOptimisation(n, energy);
		cout << ans;
	}
}