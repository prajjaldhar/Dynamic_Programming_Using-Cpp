#include<bits/stdc++.h>
using namespace std;

int print_Paths(int indx, int n, int arr[], int qb[])
{

	if (indx > n)
		return 0;

	if (indx == n)
		return 0;

	if (qb[indx] != 0)
		return qb[indx];

	int minimum = INT_MAX;
	for (int i = 1; i <= arr[indx]; ++i)
	{

		int lastminimum = print_Paths(indx + i, n, arr, qb);
		minimum = min(minimum, lastminimum + 1);

	}
	if (minimum != INT_MAX)
		qb[indx] = minimum;
	else
		qb[indx] = 0;
	return minimum;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		//Variable paths
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int qb[n + 1] = {0};
		int ans = print_Paths(0, n, arr, qb);
		cout << ans;
	}
}