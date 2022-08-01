#include<bits/stdc++.h>
using namespace std;
int counter = 0;
int getStairCase(int n, int qb[])
{
	if (n == 0)
	{
		return 1;

	}
	if (n < 0)
	{
		return 0;
	}
	if (qb[n] != 0)
		return qb[n];
	cout << "call for " << n << "\n";
	int n1 = getStairCase(n - 1, qb );
	int n2 = getStairCase(n - 2, qb );
	int n3 = getStairCase(n - 3, qb );
	int min1 = min(n1, n2);
	int total = min(min1, n3) + 1;
	qb[n] = total;
	return total;

}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int qb[n + 1] = {0};
		int ans = getStairCase(n, qb);
		cout << "minimum possible ways=" << ans;

	}
}