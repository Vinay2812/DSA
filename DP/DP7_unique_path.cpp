/*
link -> https://leetcode.com/problems/unique-paths/

There is a robot on an m x n grid.
The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 The robot can only move either down or right at any point in time.
Given the two integers m and n,
return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

ip->
3 7
op->
28

Recursion-> tc-> O(2^n+m) sc -> O(n+m)
Memoization-> tc->O(n*m) sc-> O(n+m) + O(n*m)
Tabulation->  tc->O(n*m) sc-> O(n*m)
Space Optimization-> tc->O(n*m) sc-> O(m)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& dp)
{
    if(i == 0 || j == 0)return 1;

    if(dp[i][j] != -1)return dp[i][j];

    int up = f(i-1, j, dp);
    int left = f(i, j-1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int n, int m) {
    //memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return f(n-1, m-1, dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(m, 0));

    // for(int j=0;j<m;j++)dp[0][j] = 1;
    // for(int i=0;i<n;i++)dp[i][0] = 1;

    // for(int i=1;i<n;i++){
    //     for(int j=1;j<m;j++){
    //         int up = dp[i-1][j];
    //         int left = dp[i][j-1];

    //         dp[i][j] = up + left;
    //     }
    // }
    // return dp[n-1][m-1];

    //space optimization
    vector<int> prev(m, 0), curr(m, 0);

    for(int j=0;j<m;j++)prev[j] = 1;
    curr[0] = 1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int up = prev[j];
            int left = curr[j-1];

            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;

    cout<<uniquePaths(n, m);
    return 0;
}