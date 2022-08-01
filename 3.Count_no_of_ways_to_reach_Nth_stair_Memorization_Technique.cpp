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
	int total = n1 + n2 + n3;
	qb[n] = total;
	return total;
}

int getStairCase_rec(int n)
{
	if (n == 0)
	{
		return 1;

	}
	if (n < 0)
	{
		return 0;
	}

	cout << "call for " << n << "\n";
	int n1 = getStairCase_rec(n - 1);
	int n2 = getStairCase_rec(n - 2);
	int n3 = getStairCase_rec(n - 3);
	int total = n1 + n2 + n3;
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
		cout << "total possible ways=" << ans;
		// int ans = getStairCase_rec(n);
		// cout << "total possible ways=" << ans;

	}
}