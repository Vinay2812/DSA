/*
link-> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/

Recursion tc->O(2^(n+n) * n) sc->O(n) 
Memo -> tc->O(n*n*n) sc-> O(n) + O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, int arr[], vector<vector<int>>& dp)
{
    if(i == j)return 0;//single matrix is formed

    if(dp[i][j] != -1)return dp[i][j];
    int mini= 1e9;

    for(int p=i;p<j;p++){
        int cost = arr[i-1] * arr[p] * arr[j] +  f(i,p,arr, dp) + f(p+1, j, arr, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(int n, int arr[]){
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0;i<n;i++)dp[i][i] = 0;

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){

            int mini= 1e9;
            for(int p=i;p<j;p++){
                int cost = arr[i-1] * arr[p] * arr[j] +  dp[i][p] + dp[p+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int main()
{
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<matrixMultiplication(n, arr);
    return 0;
}