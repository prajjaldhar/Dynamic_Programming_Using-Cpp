#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];
    int omax = 0;

    for (int i = 1 ; i < n ; i++) {
        int max = 0;
        for (int j = 0 ; j < i ; j++) {
            if (arr[i] > arr[j]) {
                if (max < dp[j])
                {
                    max = dp[j];
                }
            }
        }

        if (max == 0)
            dp[i] = arr[i];
        else
            dp[i] = max + arr[i];

        if (omax < dp[i]) {
            omax = dp[i];
        }
    }

    if (omax == 0) {
        omax += arr[0];
    }

    cout << omax << endl;

    return 0;
}