#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    int n = arr.size();
    vector<int>lis(n + 1, 0);
    lis[0] = 1;
    int omax = 0;
    for (int i = 1 ; i < n ; i++) {
        int max = 0;
        for (int j = 0 ; j < i ; j++) {
            if (arr[i] > arr[j]) {
                if (max < lis[j]) {
                    max = lis[j];
                }
            }
        }
        lis[i] = max + 1;
    }
    vector<int>lds(n + 1, 0);
    lds[n] = 0;
    for (int i = n - 1 ; i >= 0 ; i--) {
        int max = 0;
        for (int j = n - 1 ; j > i ; j--) {
            if (arr[i] > arr[j]) {
                if (max < lds[j]) {
                    max = lds[j];
                }
            }
        }
        lds[i] = max + 1;

    }

    for (int i = 0; i < arr.size(); ++i)
    {
        if (lis[i] + lds[i] - 1 > omax)
            omax = lis[i] + lds[i] - 1;
    }

    cout << omax << endl;


    return 0;
}
//10, 22, 9, 33, 21, 50, 41, 60, 80, 1