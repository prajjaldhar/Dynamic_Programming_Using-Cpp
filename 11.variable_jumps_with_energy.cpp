//you can take either 1 or 2 jump and each jump is associated with some energy
#include<bits/stdc++.h>
using namespace std;
int jumprec(int indx, int k, vector<int>&energy)
{
	if (indx == 0)
		return 0;
	if (indx < 0)
		return 0;
	int minimumStep = INT_MAX;
	int step;
	for (int jumps = 1; jumps <= k; ++jumps)
	{
		if (indx - jumps >= 0)
			step = jumprec(indx - jumps, k, energy) + abs(energy[indx] - energy[indx - jumps]);
		minimumStep = min(minimumStep, step) ;

	}
	return minimumStep;
}

int jumpMemo(int indx, int k, vector<int>&energy, vector<int>&dp)
{
	if (indx == 0)
		return 0;
	if (indx < 0)
		return 0;
	int step;
	int minimumStep = INT_MAX;
	if (dp[indx] != -1)return dp[indx];

	for (int jumps = 1; jumps <= k; ++jumps)
	{
		if (indx - jumps >= 0)
			step = jumprec(indx - jumps, k, energy) + abs(energy[indx] - energy[indx - jumps]);
		minimumStep = min(minimumStep, step) ;

	}
	return dp[indx] = minimumStep;
}

int dpTabulation(int n, int k, vector<int>&energy)
{
	vector<int>dp(n, 0);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int minimumStep = INT_MAX;
		int step;
		for (int jumps = 1; jumps <= k; ++jumps)
		{
			if (i - jumps >= 0)
				step = jumprec(i - jumps, k, energy) + abs(energy[i] - energy[i - jumps]);
			minimumStep = min(minimumStep, step) ;
			dp[i] = minimumStep;
		}
	}
	return dp[n - 1];
}

//here we cant optimise the space for K=N hence no space optimisation

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int>energy = {30, 10, 60, 10, 60, 50};
		vector<int>dp(n + 1, -1);
		int ans = jumprec(n - 1, k, energy);
		cout << ans << "\n";
		ans = jumpMemo(n - 1 , k , energy, dp);
		cout << ans << "\n";
		ans = dpTabulation(n, k, energy);
		cout << ans;
	}
}