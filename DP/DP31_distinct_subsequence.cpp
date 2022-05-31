/*
link-> https://leetcode.com/problems/distinct-subsequences/

ip->
babgbag
bag

op->
5
*/
#include<bits/stdc++.h>
using namespace std;

int mod = int(1e9 + 7);
int f(int i, int j, string s, string t, vector<vector<int>>& dp){
    if(j == 0)return 1;
    if(i == 0)return 0;

    if(dp[i][j] != -1)return dp[i][j];

    if(s[i-1] == t[j-1]){
        int take = f(i-1, j-1, s, t, dp);
        int nt = f(i-1, j, s, t, dp);
        return dp[i][j] = (take + nt)%mod;
    }
    else{
        int nt = f(i - 1, j, s, t, dp);
        return dp[i][j] =  nt;
    }
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    if(m > n)return 0;

    //memoization
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return f(n, m, s, t, dp);

    //tabulation
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // for(int j=0;j<=m;j++)dp[0][j] = 0;
    // for(int i=0;i<=n;i++)dp[i][0] = 1;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if (s[i - 1] == t[j - 1])
    //         {
    //             int take = dp[i-1][j-1];
    //             int nt = dp[i-1][j];
    //             dp[i][j] = (take + nt)%mod;
    //         }
    //         else
    //         {
    //             int nt = dp[i-1][j];
    //             dp[i][j] = nt;
    //         }
    //     }
    // }

    // return dp[n][m];

    //space optimization
    vector<int>prev(m + 1, 0), curr(m+1, 0);

    for(int j=0;j<=m;j++)prev[j] = 0;
    prev[0] = curr[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (s[i - 1] == t[j - 1])
            {
                int take = prev[j-1];
                int nt = prev[j];
                curr[j] = (take + nt)%mod;
            }
            else
            {
                int nt = prev[j];
               curr[j] = nt;
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main()
{
    string s, t;
    cin>>s>>t;

    cout<<numDistinct(s, t);
    return 0;
}