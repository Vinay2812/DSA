/*
link-> https://leetcode.com/problems/minimum-falling-path-sum/

Given an n x n array of integers matrix,
return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and
chooses the element in the next row that is either directly below or
diagonally left/right. Specifically, the next element from position
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

ip->
3
2 10 3
6 5 1
7 2 9

op->
6

Recursion-> tc->O(3^n) sc->O(n)
Memoization-> tc->O(n^2) sc->O(n) + O(n*n)
Tabulation->  tc->O(n^2) sc->O(n*n)
Space optimization-> tc->O(n^2) sc->O(2n)

*/

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>>& dp)
{
    if(i == 0){
        return matrix[0][j];
    }

    if(dp[i][j] != -1)return dp[i][j];

    int left = 1e9;
    if(j > 0)left = f(i-1, j-1, matrix, n, dp);
    int up = f(i-1, j, matrix, n, dp);
    int right = 1e9;
    if(j < n-1) right = f(i-1, j+1, matrix, n, dp);

    return dp[i][j] = matrix[i][j] + min(min(left, right), up);
}

int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();

    //memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int mini = 1e9;
    // for(int j=0;j<n;j++){
    //     int store = f(n-1, j, matrix, n, dp);
    //     mini = min(mini, store);
    // }
    // return mini;

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(n, 0));

    // for(int j=0;j<n;j++)
    //     dp[0][j] = matrix[0][j];
    
    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         int left = 1e9;
    //         if (j > 0)
    //             left = dp[i-1][j-1];
    //         int up = dp[i-1][j];
    //         int right = 1e9;
    //         if (j < n - 1)
    //             right = dp[i-1][j+1];

    //         dp[i][j] = matrix[i][j] + min(min(left, right), up);
    //     }
    // }

    // int mini = 1e9;
    // for(int j=0;j<n;j++){
    //     int store = dp[n-1][j];
    //     mini = min(mini, store);
    // }
    // return mini;

    //space optimization
    vector<int> prev(n, 0), curr(n, 0);

    for(int j=0;j<n;j++)
        prev[j] = matrix[0][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int left = 1e9;
            if (j > 0)
                left = prev[j-1];
            int up = prev[j];
            int right = 1e9;
            if (j < n - 1)
                right = prev[j+1];

            curr[j] = matrix[i][j] + min(min(left, right), up);
        }
        prev = curr;
    }

    int mini = 1e9;
    for(int j=0;j<n;j++){
        int store = prev[j];
        mini = min(mini, store);
    }
    return mini;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<minFallingPathSum(matrix);    
    return 0;
}