/*
link -> https://leetcode.com/problems/min-cost-climbing-stairs/
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &cost, vector<int> &dp)
{
    if(i == 0)return cost[0];
    if(i == 1)return cost[1];

    if(dp[i]!=-1)return dp[i];

    int one = cost[i] + f(i-1, cost, dp);
    int two = cost[i] + f(i-2, cost, dp);

    return dp[i] = min(one, two);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    cost.push_back(0);

    //memoization
    // vector<int> dp(n+1, -1);
    // int ans = f(n, cost, dp);

    //tabulation
    // vector<int> dp(n + 1, 0);
    // dp[0] = cost[0];
    // dp[1] = cost[1];

    // for(int i=2;i<=n;i++){
    //     int one = cost[i] + dp[i-1];
    //     int two = cost[i] + dp[i-2];

    //     dp[i] = min(one, two);
    // }
    // int ans = dp[n];

    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i=2;i<=n;i++){
        int one = cost[i] + prev1;
        int two = cost[i] + prev2;

        int curr = min(one, two);

        prev2 = prev1;
        prev1 = curr;
    }
    int ans = prev1;

    cost.pop_back();
    return ans;
}

int main()
{
    int n;cin>>n;
    vector<int> cost(n);
    for(int i=0;i<n;i++)cin>>cost[i];

    cout << minCostClimbingStairs(cost);
    return 0;
}