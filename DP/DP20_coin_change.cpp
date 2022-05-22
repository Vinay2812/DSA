/*
link-> https://leetcode.com/problems/coin-change/ 

ip->
3 11
1 2 5

op->
3

*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int a, vector<int>&coins, vector<vector<int>>& dp){
    if(a == 0)return 0;

    if(i == 0){
        if(a % coins[0] == 0)return a / coins[0];
        else return 1e9;
    }

    if(dp[i][a] != -1)return dp[i][a];

    int nt = 0 + f(i-1, a, coins, dp);
    int t = 1e9;
    if(coins[i] <= a)t = 1 + f(i, a-coins[i], coins, dp);

    return dp[i][a] = min(nt, t);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    if(amount == 0)return 0;

    //memoization
    // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // int ans = f(n-1, amount, coins, dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // for (int a = 0; a <= amount; a++)
    // {
    //     if (a % coins[0] == 0)
    //         dp[0][a] = a / coins[0];
    //     else
    //         dp[0][a] = 1e9;
    // }

    // for(int i=0;i<n;i++){
    //     dp[i][0] = 0;
    // }

    // for(int i=1;i<n;i++){
    //     for(int a=1;a<=amount;a++){
    //         int nt = 0 + dp[i-1][a];
    //         int t = 1e9;
    //         if (coins[i] <= a)
    //             t = 1 +dp[i][a - coins[i]];

    //         dp[i][a] = min(nt, t);
    //     }
    // }
    // int ans = dp[n-1][amount];
    // if(ans >= 1e9)return -1;
    // return ans;

    //space optimization
    vector<int> prev(amount+1, 0), curr(amount+1, 0);
    for (int a = 0; a <= amount; a++)
    {
        if (a % coins[0] == 0)
            prev[a] = a / coins[0];
        else
            prev[a] = 1e9;
    }

    prev[0] = curr[0] = 0;

    for(int i=1;i<n;i++){
        for(int a=1;a<=amount;a++){
            int nt = 0 + prev[a];
            int t = 1e9;
            if (coins[i] <= a)
                t = 1 + curr[a - coins[i]];

            curr[a] = min(nt, t);
        }
        prev = curr;
    }
    int ans = prev[amount];
    if(ans >= 1e9)return -1;
    return ans;
}

int main()
{
    int n, amount;
    cin>>n>>amount;

    vector<int> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];

    cout<<coinChange(coins, amount);
    return 0;
}