class Solution {
public:
    int sol(int n)
{
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
    for(int j = 1;j<=n;j++)
    {
        int mini = INT_MAX;
        for(int i = 1;i<=sqrt(j);i++)
       {
           int sq = i*i; 
           int curr = 1 + dp[j - sq];
           mini = min(mini,curr);
       }
       dp[j] = mini;
    }
    return dp[n];
}
    int numSquares(int n) 
    {
       return sol(n);
    }
};