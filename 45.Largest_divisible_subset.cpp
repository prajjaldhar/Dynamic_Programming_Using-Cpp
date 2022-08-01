#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {2, 3, 4, 8};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 0);
    dp[0] = 1;
    int omax = 0;
    int index = -1;

    for (int i = 1 ; i < n ; i++) {
        int max = 0;
        for (int j = 0 ; j < i ; j++) {
            if (arr[i] % arr[j] == 0) {
                if (max < dp[j]) {
                    max = dp[j];
                }
            }
        }
        dp[i] = max + 1;
        if (omax < dp[i]) {
            omax = dp[i];
            index = i;
        }
    }

    if (omax == 0) {
        omax += 1;
        index = 0;
    }

    cout << omax << endl;
    queue<pair<int, string>> myqueue;
    myqueue.push(make_pair(index, to_string(arr[index])));

    while (!myqueue.empty()) {
        pair<int, string> temp = myqueue.front();
        int indx = temp.first;
        string value = temp.second;
        int length = dp[indx] - 1;
        myqueue.pop();

        if (indx == 0) {
            cout << value << endl;
            continue;
        }

        for (int pq = 0 ; pq < indx ; pq++) {
            if (arr[indx] % arr[pq] == 0 && dp[pq] == length )
            {
                myqueue.push(make_pair(pq, to_string(arr[pq]) + "->" + value));
            }
        }
    }
    return 0;
}

//1, 16, 7, 8, 4
//2, 4, 3, 8