//fibonacci_series_recursion_approach
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
	cout << "call for " << n << "\n";
	if (n == 0 || n == 1)
		return n;
	cout << "call for" << n << "\n";
	int fib1 = fib(n - 1);
	int fib2 = fib(n - 2);
	int fibn = fib1 + fib2;
	return fibn;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, ans;
		cin >> n;
		ans = fib(n);
		cout << ans;

	}
}