#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {64};
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int omax = 0;
    int index = -1;

    for (int i = 1 ; i < n ; i++) {
        int max = 0;
        for (int j = 0 ; j < i ; j++) {
            if (arr[i] > arr[j]) {
                if (max < dp[j]) {
                    max = dp[j];
                }
            }
        }
        dp[i] = max + 1;
        if (omax < dp[i]) {
            omax = dp[i];
            // index = i;
        }
    }

    if (omax == 0) {
        omax += 1;
        index = 0;
    }

    cout << omax << endl;


    return 0;
}
//10, 22, 9, 33, 21, 50, 41, 60, 80, 1

//method 2
// vector<int> arr = {5, 4, 11, 1, 16, 8};
//    int n = arr.size();
//    int maximum = 1;
//    vector<int> dp(n + 1, 1), count(n + 1, 1);

//    for (int i = 1 ; i < n ; i++) {

//        for (int j = 0 ; j < i ; j++) {
//            if (arr[i] > arr[j]) {
//                dp[i] = max(1 + dp[j], dp[i]);
//            }
//        }
//        maximum = max(maximum, dp[i]);
//    }
//    cout << maximum;
//    return 0;