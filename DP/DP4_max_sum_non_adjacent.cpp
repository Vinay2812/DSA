/*
link -> https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

i/p ->
6
4 2 3 1 5 2
o/p->
12

Recursion -> tc->2^n sc->O(n)
Memoization -> tc-> O(n) sc-> O(n) + O(n)
Tabulation -> tc-> O(n) sc-> O(n)
Space optimization -> tc->O(n) sc->O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, vector<int> arr, vector<int> &dp)
{
    //memoization
    if(i == 0)return arr[0];

    if(dp[i]!=-1)return dp[i];

    int nt = 0 + f(i-1, arr, dp);
    int t = arr[i];
    if(i>1) t += f(i-2, arr, dp);

    return dp[i] = max(nt, t);
}

int rob(vector<int> &arr)
{
    int n = arr.size();
    //memoization
    // vector<int> dp(n, -1);
    // return f(n-1, arr, dp);

    //tabulation
    // vector<int> dp(n, 0);
    // dp[0] = arr[0];

    // for(int i=1;i<n;i++){
    //     int nt = 0 + dp[i-1];
    //     int t = arr[i];
    //     if (i > 1)
    //         t += dp[i-2];

    //     dp[i] = max(nt, t);
    // }
    // return dp[n-1];

    //space optimization
    int prev1 = arr[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        int nt = 0 + prev1;
        int t = arr[i];
        if (i > 1)
            t += prev2;

        int curr = max(nt, t);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<rob(arr);
    return 0;
}