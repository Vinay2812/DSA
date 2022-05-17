/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can climb k steps

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Recursion -> tc->k^n sc->O(n)
Memoization -> tc -> O(n*k) sc-> O(n) + O(n)
Tabulation -> tc -> O(n*k) sc-> O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &cost, vector<int> &dp, int k)
{
    if (i == 0)
        return cost[0];
    if (i == 1)
        return cost[1];

    if (dp[i] != -1)
        return dp[i];

    int mini = 1e9;
    for(int step=1;step<=k;step++){
        int store = 1e9;
        if(i>=step)store = f(i-step, cost, dp, k);
        mini = min(mini, store);
    }

    return dp[i] = cost[i] + mini;
}
int minCostClimbingStairs(vector<int> &cost, int k)
{
    int n = cost.size();
    cost.push_back(0);

    // memoization
    //  vector<int> dp(n+1, -1);
    //  int ans = f(n, cost, dp, k);

    // tabulation
     vector<int> dp(n + 1, 0);
     dp[0] = cost[0];
     dp[1] = cost[1];

    for(int i=2;i<=n;i++){
        int mini = 1e9;
        for (int step = 1; step <= k; step++)
        {
            int store = 1e9;
            if (i >= step)
                store = dp[i-step];
            mini = min(mini, store);
        }
        dp[i] = cost[i] + mini;
    }
    int ans = dp[n];

    for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;

    cost.pop_back();
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << minCostClimbingStairs(cost, k);
    return 0;
}