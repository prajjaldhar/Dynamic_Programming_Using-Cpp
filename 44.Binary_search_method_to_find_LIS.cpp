//TC -> (nlogn)
#include<bits/stdc++.h>
using namespace std;

int main() {

	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
	int n = arr.size();
	vector<int>temp;
	int len = 1;
	temp.push_back(arr[0]);
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > temp.back())
		{
			temp.push_back(arr[i]);
			len++;
		}
		else {
			int indx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[indx] = arr[i];
		}

	}
	cout << len;
}