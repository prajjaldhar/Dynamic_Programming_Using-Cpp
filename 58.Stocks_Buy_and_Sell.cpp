#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int>arr = {7, 1, 5, 3, 6, 4};
		int minimum = arr[0];
		int profit = 0;
		int n = arr.size();
		for (int i = 0; i < n; i++)
		{
			int cost = arr[i] - minimum;
			profit = max(profit, cost);
			minimum = min(minimum, arr[i]);
		}
		cout << profit;
	}

}