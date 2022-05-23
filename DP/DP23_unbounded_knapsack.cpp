/*
link-> https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

ip->
3 4
1 2 3
4 5 1

op->
12
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int wt, int weight[], int val[], vector<vector<int>>& dp){
    if(wt == 0)return 0;

    if(i == 0){
        int cnt = wt/weight[0];
        return cnt * val[0];
    }
    if(dp[i][wt] != -1)return dp[i][wt];

    int nt = 0 + f(i-1, wt, weight, val, dp);
    int t = -1e9;
    if(weight[i] <= wt)t = val[i] + f(i, wt - weight[i], weight, val, dp);

    return dp[i][wt] = max(t, nt);
}
int knapSack(int n, int W, int val[], int weight[])
{
    //memoization
    // vector<vector<int>> dp(n, vector<int>(W+1, -1));
    // return f(n-1, W, weight, val, dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // for (int wt = 0; wt <= W; wt++)
    // {
    //     int cnt = wt / weight[0];
    //     dp[0][wt] = cnt * val[0];
    // }

    // for(int i=0;i<n;i++){
    //     dp[i][0] = 0;
    // }

    // for(int i=1;i<n;i++){
    //     for(int wt=0;wt<=W;wt++){
    //         int nt = 0 + dp[i-1][wt];
    //         int t = -1e9;
    //         if (weight[i] <= wt)
    //             t = val[i] + dp[i-1][wt - weight[i]];

    //         dp[i][wt] = max(t, nt);
    //     }
    // }
    // return dp[n-1][W];

    //space optimization;
    vector<int>prev(W + 1, 0), curr(W+1, 0);
    for (int wt = 0; wt <= W; wt++)
    {
        int cnt = wt / weight[0];
        prev[wt] = cnt * val[0];
    }

    prev[0] = curr[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= W; wt++)
        {
            int nt = 0 + prev[wt];
            int t = -1e9;
            if (weight[i] <= wt)
                t = val[i] + prev[wt - weight[i]];

            curr[wt] = max(t, nt);
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{
    int n, wt;
    cin >> n >> wt;

    int values[n];
    int weight[n];

    for (int i = 0; i < n; i++)
        cin >> values[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << knapSack(n, wt, values, weight);
    return 0;
}