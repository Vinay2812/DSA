/*
link-> https://leetcode.com/problems/triangle/

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below.
More formally, if you are on index i on the current row,
you may move to either index i or index i + 1 on the next row.

ip->
4
2
3 4
6 5 7
4 1 8 3

op->
11

Recursion -> tc->O(2^n+n) sc->O(n+n)
Memoization ->tc->O(n^2) sc->(n+n) + O(n*n)
Tabulation -> tc->O(n^2) sc->O(n*n)
space optimization -> tc->O(n^2) sc->O(2n)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if(i == n-1)return triangle[n-1][j];

    if(dp[i][j] !=-1)return dp[i][j];

    int down = triangle[i][j] + f(i+1, j, n, triangle, dp);
    int down_right = triangle[i][j] + f(i+1, j+1, n, triangle, dp);

    return dp[i][j] = min(down, down_right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    //memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return f(0,0,n,triangle,dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(n, 0));

    // for(int j=0;j<n;j++)
    //     dp[n - 1][j] = triangle[n - 1][j];
    
    // for(int i=n-2;i>=0;i--){
    //     for(int j=i;j>=0;j--){
    //         int down = triangle[i][j] + dp[i+1][j];
    //         int down_right = triangle[i][j] + dp[i+1][j+1];

    //         dp[i][j] = min(down, down_right);
    //     }
    // }
    // return dp[0][0];

    vector<int> curr(n, 0), next(n, 0);
    for(int j=0;j<n;j++)
        next[j] = triangle[n - 1][j];

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + next[j];
            int down_right = triangle[i][j] + next[j+1];

            curr[j] = min(down, down_right);
        }
        next = curr;
    }
    return curr[0];
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> triangle;
    for(int i=1;i<=n;i++){
        vector<int> temp;
        for(int j=0;j<i;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        triangle.push_back(temp);
    }

    cout<<minimumTotal(triangle);
    return 0;
}