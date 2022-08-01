#include<bits/stdc++.h>
using namespace std;
int TaskRec(int days, int task, int last, vector<vector<int>>points)
{
	if (days == 0)
	{
		int maximum = 0;
		for (int i = 0; i < task; ++i)
		{
			if (i != last)
			{
				maximum = max(maximum, points[0][i]);
			}
		}
		return maximum;
	}

	int maximum = 0;
	for (int i = 0; i < task ; ++i)
	{
		if (i != last)
		{
			int point = points[days][i] + TaskRec(days - 1, task, i, points);
			maximum = max(maximum, point);
		}
	}
	return maximum;

}

int TaskMemo(int days, int task, int last, vector<vector<int>>points, vector<vector<int>>dp)
{
	if (days == 0)
	{
		int maximum = 0;
		for (int i = 0; i < task; ++i)
		{
			if (i != last)
			{
				maximum = max(maximum, points[0][i]);
			}
		}
		return maximum;
	}
	if (dp[days][last] != -1)
		return dp[days][last];
	int maximum = 0;
	for (int i = 0; i < task ; ++i)
	{
		if (i != last)
		{
			int point = points[days][i] + TaskMemo(days - 1, task, i, points, dp);
			maximum = max(maximum, point);
		}
	}
	dp[days][last] = maximum;
	return maximum;

}

int TaskDP(int days, int task, int last, vector<vector<int>>points)
{
	vector<vector<int>>dp(days, vector<int>(task + 1, 0));
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
	for (int i = 1; i < days ; ++i)
	{
		for (int last = 0; last < task + 1; ++last)
		{
			dp[i][last] = 0;
			for (int tasks = 0; tasks < task  ; ++tasks)
			{
				if (tasks != last)
				{
					int point = points[i][tasks] + dp[i - 1][tasks];
					dp[i][last] = max(dp[i][last], point);
				}
			}
		}
	}
	for (auto i : dp)
	{
		for (auto ele : i)
		{
			cout << ele << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return dp[days - 1][task];
}

int TaskOptimisation(int days, int task, int last, vector<vector<int>>points)
{
	vector<int>prev(task + 1, 0);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
	for (int i = 1; i < days; ++i)
	{
		vector<int>temp(task + 1, 0);
		for (int last = 0; last < task + 1; ++last)
		{
			temp[last] = 0;
			for (int tasks = 0; tasks < task ; ++tasks)
			{
				if (tasks != last)
				{
					int point = points[i][tasks] + prev[tasks];
					temp[last] = max(temp[last], point);
				}
			}
		}
		prev = temp;
	}
	for (auto i : prev)
		cout << i << " ";
	cout << "\n";
	return prev[task];
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int days, task;
		cin >> days >> task;
		vector<vector<int> >points(days, vector<int>(task));
		for (int i = 0; i < days; ++i)
		{
			for (int j = 0; j < task; ++j)
			{
				cin >> points[i][j];
			}
		}
		vector<vector<int>>dp(days, vector<int>(task + 1, -1));
		// int maximum = TaskRec(days - 1, task, task, points);
		//int maximum = TaskMemo(days - 1, task, task, points, dp);
		// int maximum = TaskDP(days, task, task, points);
		// cout << maximum;
		int maximum = TaskOptimisation(days, task, task, points);
		cout << maximum;
	}
}