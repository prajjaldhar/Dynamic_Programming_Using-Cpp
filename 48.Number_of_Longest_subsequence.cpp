#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {5 , 7 , 2 , 3};
    int n = arr.size();
    int maximum = 1;
    vector<int> dp(n + 1, 1), count(n + 1, 1);

    for (int i = 1 ; i < n ; i++) {

        for (int j = 0 ; j < i ; j++) {
            if (arr[i] > arr[j] &&  1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }
            else if (arr[i] > arr[j] &&  1 + dp[j] == dp[i])
            {
                count[i] += count[j];
            }
        }
        maximum = max(maximum, dp[i]);
    }
    int nos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] == maximum)
            nos += count[i];
    }
    cout << nos;
    return 0;
}
//10, 22, 9, 33, 21, 50, 41, 60, 80, 1
//5, 4, 11, 1, 16, 8
//50 3 90 60 80
//1, 5, 4, 3, 2, 6, 7, 10, 8, 9
// 5 ,7 ,2 ,3