/*
link -> https://leetcode.com/problems/minimum-path-sum/
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

ip->
3 3
1 3 1
1 5 1
4 2 1

op->
7


*/

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>>& dp)
{
    if(i == 0 and j == 0)return grid[0][0];

    if(dp[i][j]!=-1)return dp[i][j];

    int up = 1e9;
    if(i>0) up = grid[i][j] + f(i-1, j, grid, dp);
    int left = 1e9;
    if(j>0) left = grid[i][j] + f(i, j-1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    //memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));

    // return f(n-1, m-1, grid, dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // dp[0][0] = grid[0][0];

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 and j==0){
    //             continue;
    //         }
    //         else{
    //             int up = 1e9;
    //             if (i > 0)
    //                 up = grid[i][j] + dp[i-1][j];
    //             int left = 1e9;
    //             if (j > 0)
    //                 left = grid[i][j] + dp[i][j-1];

    //             dp[i][j] = min(up, left);
    //         }
    //     }
    // }
    // return dp[n-1][m-1];

    // space optimization
    vector<int>prev(m, 0), curr(m, 0);

    prev[0] = curr[0] = grid[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                continue;
            }
            else{
                int up = 1e9;
                if (i > 0)
                    up = grid[i][j] +prev[j];
                int left = 1e9;
                if (j > 0)
                    left = grid[i][j] + curr[j-1];

                curr[j] = min(up, left);
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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid);
    return 0;
}