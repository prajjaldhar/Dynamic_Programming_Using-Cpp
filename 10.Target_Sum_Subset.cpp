#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n = 5, target;
		int arr[n] = {4, 2, 7, 1, 3};
		cin >> target;
		bool dp[n + 1][target + 1] = {false};
		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j < target + 1; ++j)
			{
				if (i == 0 && j == 0) //1st cell
					dp[i][j] = true;
				else if (i == 0) //1St row(for null subsets)
					dp[i][j] = false;
				else if (j == 0) //1st column
					dp[i][j] = true;
				else
				{
					if (dp[i - 1][j] == true) //immediate above cell
						dp[i][j] = true;
					else
					{
						int value = arr[i - 1];//fetched the new element
						if (j >= value)//checking whether target sum > value
						{
							if (dp[i - 1][j - value] == true)
							{	//if you include that element then you have to make
								//sure that rest of the target should be achieved by the previous elements
								dp[i][j] = true;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n + 1 ; ++i)
		{
			for (int j = 0; j < target + 1 ; ++j)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		if (dp[n][target] == 1)
			cout << "target can be achieved";
		else
			cout << "cannot achieved";
	}
}