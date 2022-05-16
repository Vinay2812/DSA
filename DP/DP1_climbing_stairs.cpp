/*
link-> https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps.
 In how many distinct ways can you climb to the top?
*/
#include<bits/stdc++.h>
using namespace std;
int f(int i, vector<int> &dp)
{
    //memoization
    if(i == 0)return 1;

    if(dp[i]!=-1)return dp[i];

    int one = f(i-1, dp);
    int two = 0;
    if(i>1)two = f(i-2, dp);

    return dp[i] = one + two;
}

int climbStairs(int n)
{
    //memoization
    // vector<int> dp(n+1, -1);
    // return f(n, dp);

    //tabulation
    // vector<int> dp(n + 1, 0);
    // dp[0] = 1;

    // for(int i=1;i<=n;i++){
    //     int one = dp[i-1];
    //     int two = 0;
    //     if (i > 1)
    //         two = dp[i-2];

    //     dp[i] = one + two;
    // }

    // return dp[n];

    //space optimization
    int prev1 = 1;
    int prev2 = 0;

    for(int i=1;i<=n;i++){
        int one = prev1;
        int two = 0;
        if (i > 1)
            two = prev2;

        int curr = one + two;

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    
}
int main()
{
    int n;cin>>n;
    cout<<climbStairs(n);
    return 0;
}