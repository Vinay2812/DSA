/*
link-> https://leetcode.com/problems/minimum-falling-path-sum-ii/

Given an n x n integer matrix grid, 
return the minimum sum of a falling path with non-zero shifts.
A falling path with non-zero shifts is a choice of exactly one element from each row 
of grid such that no two elements chosen in adjacent rows are in the same column.

ip->
3
2 10 3
6 5 1
7 2 9

op->
5


*/

#include <bits/stdc++.h>
using namespace std;
int f(int i, int prev_task, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        int mini = 1e9;
        for (int task = 0; task < n; task++)
        {
            if (task != prev_task)
            {
                int store = matrix[0][task];
                mini = min(store, mini);
            }
        }
        return mini;
    }

    if (dp[i][prev_task] != -1)
        return dp[i][prev_task];

    int mini = 1e9;
    for (int task = 0; task < n; task++)
    {
        if (task != prev_task)
        {
            int store = matrix[i][task] + f(i - 1, task, matrix, n, dp);
            mini = min(store, mini);
        }
    }
    return dp[i][prev_task] = mini;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 1)
        return matrix[0][0];

    // memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int mini = 1e9;
    // for (int j = 0; j < n; j++)
    // {
    //     int store = f(n - 1, j, matrix, n, dp);
    //     mini = min(mini, store);
    // }
    // return mini;

    // tabulation
    //     vector<vector<int>> dp(n, vector<int>(n, 0));

    //     for(int prev_task=0;prev_task<n;prev_task++){
    //         int mini = 1e9;
    //         for (int task = 0; task < n; task++)
    //         {
    //             if (task != prev_task)
    //             {
    //                 int store = matrix[0][task];
    //                 mini = min(store, mini);
    //             }
    //         }
    //         dp[0][prev_task] =  mini;
    //     }

    //     for(int i=1;i<n;i++){
    //         for(int prev_task=0;prev_task<n;prev_task++){
    //             int mini = 1e9;
    //             for (int task = 0; task < n; task++){
    //                 if (task != prev_task){
    //                     int store = matrix[i][task] + dp[i-1][task];
    //                     mini = min(store, mini);
    //                 }
    //             }
    //             dp[i][prev_task] = mini;
    //         }
    //     }

    //     int mini = 1e9;
    //     for(int j=0;j<n;j++){
    //         int store = dp[n-1][j];
    //         mini = min(mini, store);
    //     }
    //     return mini;

    // space optimization
        vector<int> prev(n, 0), curr(n, 0);

        for(int prev_task=0;prev_task<n;prev_task++){
            int mini = 1e9;
            for (int task = 0; task < n; task++)
            {
                if (task != prev_task)
                {
                    int store = matrix[0][task];
                    mini = min(store, mini);
                }
            }
            prev[prev_task] =  mini;
        }

        for(int i=1;i<n;i++){
            for(int prev_task=0;prev_task<n;prev_task++){
                int mini = 1e9;
                for (int task = 0; task < n; task++){
                    if (task != prev_task){
                        int store = matrix[i][task] + prev[task];
                        mini = min(store, mini);
                    }
                }
                curr[prev_task] = mini;
            }
            prev = curr;
        }

        int mini = 1e9;
        for(int j=0;j<n;j++){
            int store =  prev[j];
            mini = min(mini, store);
        }
        return mini;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cout << minFallingPathSum(matrix);
    return 0;
}