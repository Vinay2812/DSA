/*
link -> https://leetcode.com/problems/unique-paths-ii/

You are given an m x n integer array grid.
There is a robot initially located at the top-left corner (i.e., grid[0][0])
The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). 
The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid.
A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

ip->
3 3
0 0 0
0 1 0
0 0 0

op->
2

Recursion-> tc-> O(2^n+m) sc -> O(n+m)
Memoization-> tc->O(n*m) sc-> O(n+m) + O(n*m)
Tabulation->  tc->O(n*m) sc-> O(n*m)
Space Optimization-> tc->O(n*m) sc-> O(m)
*/
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &obstacle, vector<vector<int>> &dp)
{
    if(obstacle[i][j] == 1)return 0;

    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = 0;
    if(i>0) up = f(i - 1, j,obstacle, dp);
    int left = 0;
    if(j>0) left = f(i, j - 1,obstacle, dp);

    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacle)
{
    int n = obstacle.size();
    int m = obstacle[0].size();

    if(obstacle[0][0] == 1 || obstacle[n-1][m-1] == 1)return 0;

    // memoization
    //  vector<vector<int>> dp(n, vector<int>(m, -1));
    //  return f(n-1, m-1, obstacle, dp);

    // tabulation
    // vector<vector<int>> dp(n, vector<int>(m, 0));

    // dp[0][0] = 1;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if (obstacle[i][j] == 1)
    //             dp[i][j] = 0;
    //         else if(i == 0 and j == 0)
    //             dp[i][j] = 1;
    //         else{
    //             int up = 0;
    //             if (i > 0)
    //                 up = dp[i-1][j];
    //             int left = 0;
    //             if (j > 0)
    //                 left = dp[i][j-1];

    //             dp[i][j] = up + left;
    //         }
    //     }
    // }
    // return dp[n-1][m-1];

    // space optimization
    vector<int> prev(m, 0), curr(m, 0);
    prev[0] = curr[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (obstacle[i][j] == 1)
                prev[j] = curr[j] = 0;
            else if(i == 0 and j == 0)
                prev[j] = curr[j] = 1;
            else{
                int up = 0;
                if (i > 0)
                    up = prev[j];
                int left = 0;
                if (j > 0)
                    left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> obstacle(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>obstacle[i][j];
        }
    }

    cout << uniquePathsWithObstacles(obstacle);
    return 0;
}