/*
link-> https://leetcode.com/problems/coin-change-2/

ip->
3 5
1 2 5

op->
4
*/
#include<bits/stdc++.h>
using namespace std;

int mod = int(1e9 + 7);
int f(int i, int a, vector<int>& coins, vector<vector<int>>& dp){
    if(a == 0)return 1;

    if(i == 0){
        return (a % coins[0] == 0);
    }

    if(dp[i][a] != -1)return dp[i][a];

    int nt = f(i-1, a, coins, dp);
    int t = 0;
    if(coins[i] <= a)t = f(i, a - coins[i], coins, dp);

    return dp[i][a] = (t + nt);
}

int change(int amount, vector<int> &coins){
    int n = coins.size();

    // memoization
    // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // return f(n-1, amount, coins, dp);

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // for(int a=0;a<=amount;a++){
    //         dp[0][a] = (a % coins[0] == 0); 
    // }

    // for(int i=0;i<n;i++)dp[i][0] = 1;

    // for(int i=1;i<n;i++){
    //     for(int a=1;a<=amount;a++){
    //         int nt = dp[i-1][a];
    //         int t = 0;
    //         if (coins[i] <= a)
    //             t = dp[i][a-coins[i]];

    //         dp[i][a] = (t + nt);
    //     }
    // }
    // return dp[n-1][amount];

    //space optimization
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for(int a=0;a<=amount;a++){
            prev[a] = (a % coins[0] == 0);
    }

    prev[0] = curr[0] = 1;

    for(int i=1;i<n;i++){
        for(int a=1;a<=amount;a++){
            int nt = prev[a];
            int t = 0;
            if (coins[i] <= a)
                t = curr[a-coins[i]];

            curr[a] = (t + nt);
        }
        prev = curr;
    }
    return prev[amount];
}

int main()
{
    int n, amount;
    cin>>n>>amount;

    vector<int> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];

    cout<<change(amount, coins);
    return 0;
}