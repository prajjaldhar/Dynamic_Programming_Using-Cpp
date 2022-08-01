#include<bits/stdc++.h>
using namespace std;

bool comparePossible(string s1 , string s2)
{
    if (s1.size() != s2.size() + 1) return false;
    int first = 0;
    int second = 0;
    while (first < s1.size())
    {
        if (second < s2.size() && s1[first] == s2[second]) {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1.size() && second == s2.size()) return true;
    return false;
}

bool comp(string s1, string s2)
{
    return s1.size() < s2.size();
}

int main() {

    vector<string> arr = {"a", "ba", "b", "bca", "bda", "bdca"};
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int>dp(n + 1, 0);
    dp[0] = 1;
    int omax = 0;

    for (int i = 1 ; i < n ; i++) {
        int max = 0;
        for (int j = 0 ; j < i ; j++) {
            if (comparePossible(arr[i], arr[j])) {
                if (max < dp[j])
                {
                    max = dp[j];
                }
            }
        }


        dp[i] = max + 1;

        if (omax < dp[i]) {
            omax = dp[i];
        }
    }

    if (omax == 0) {
        omax += 1;
    }

    cout << omax << endl;

    return 0;
}