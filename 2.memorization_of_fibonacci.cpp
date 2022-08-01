//fibonacci_series_DP_approach
//fibonacci_series_recursion_approach
#include<bits/stdc++.h>
using namespace std;
//time complexity is reduced from 2^n to O(n) and space is O(n)
int fibMemo(int n, int qb[])
{

	if (n == 0 || n == 1)
		return n;
	if (qb[n] != 0)
		return qb[n];
	cout << "call for " << n << "\n";
	int fib1 = fibMemo(n - 1, qb);
	int fib2 = fibMemo(n - 2, qb);
	int fibn = fib1 + fib2;
	qb[n] = fibn;
	return fibn;
}

//here time is O(n) and space is O(n)
int fiboTab(int n)
{
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n + 1; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

//space complexity is reduced to O(1)
int fibOptimize(int n)
{
	int prev2 = 0, prev = 1, curr;
	for (int i = 2; i < n + 1; ++i)
	{
		curr = prev + prev2;
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
		int n, ans;
		cin >> n;
		int qb[n + 1] = {0};
		ans = fibMemo(n, qb);
		// cout << ans << "\n";
		//ans = fiboTab(n);
		cout << ans << "\n";
		//ans = fibOptimize(n);
		cout << ans;

	}
}