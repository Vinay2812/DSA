/*
link-> https://leetcode.com/problems/longest-common-subsequence/

ip->
abac
bca

op->
2

Recursion-> tc->O(2^(n*m)) sc->O(n+m)
Memoization-> tc->O(n*m) sc->O(n+m) + O(n*m)
Tabulation-> tc->O(n*m) sc->O(n*m)
Space optimization-> tc->O(n*m) sc->O(2*m)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string a, string b, vector<vector<int>>& dp){
    if(i == 0 || j == 0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    //match
    if(a[i-1] == b[j-1]){
        return dp[i][j] = 1 + f(i-1, j-1, a, b, dp);
    }
    else{
        //not match
        int one = f(i-1, j, a, b, dp);
        int two = f(i, j-1, a, b, dp);

        return dp[i][j] = max(one, two);
    }
}

int longestCommonSubsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();

    //memoization
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return f(n, m, a, b, dp);

    //tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int j=0;j<=m;j++)dp[0][j] = 0;
    for(int i=0;i<=n;i++)dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                // not match
                int one = dp[i-1][j];
                int two = dp[i][j-1];

                dp[i][j] = max(one, two);
            }
        }
    }

    //find the lcs string
    string ans;
    int len = dp[n][m];
    int i = n, j = m;

    while(len > 0 and i>0 and j>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            len--;
            i = i-1;
            j = j-1;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i = i-1;
            }
            else{
                j = j-1;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return dp[n][m];

    //space optimization
    vector<int>prev(m + 1, 0), curr(m+1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;
    
    prev[0] = curr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                // not match
                int one = prev[j];
                int two = curr[j - 1];

                curr[j] = max(one, two);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout << longestCommonSubsequence(a, b);
    return 0;
}