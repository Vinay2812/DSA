/*
link-> https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
You are given an array containing N non-negative integers.
Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.

ip->
3
8 6 5

op->
3

Recursion-> tc->O(2^(n*k)) sc->O(n)
Memoization-> tc->O(n*k) sc->O(n) + O(n*k)
Tabulation->  tc->O(n*k) sc->O(n*k)
space optimization-> tc->tc->O(n*k) sc->O(2*k)
*/
#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total_sum = 0;
    for (auto x : arr)
        total_sum += x;

    int k = total_sum / 2;

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // for(int i=0;i<n;i++)
    //     dp[i][0] = 1;

    // for(int target=1;target<=k;target++)
    //     dp[0][target] = arr[0] == target;

    // for(int i=1;i<n;i++){
    //     for(int target=1;target<=k;target++){
    //         int nt = dp[i-1][target];
    //         int t = false;
    //         if (arr[i] <= target)
    //             t = dp[i-1][target-arr[i]];

    //         dp[i][target] = (t || nt);
    //     }
    // }
    // int mini = 1e9;
    // for(int target = k;target>=0;target--){
    //     if(dp[n-1][target] == 1){
    //         int sum1 = target;
    //         int sum2 = total_sum - sum1;

    //         mini = min(mini, abs(sum1-sum2));
    //     }
    // }
    // return mini;

    //space optimization
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    for (int target = 1; target <= k; target++)
        prev[target] = arr[0] == target;

    prev[0] = curr[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            int nt = prev[target];
            int t = false;
            if (arr[i] <= target)
                t = prev[target - arr[i]];

            curr[target] = (t || nt);
        }
        prev = curr;
    }

    int mini = 1e9;
    for (int target = k; target >= 0; target--)
    {
        if (prev[target] == 1)
        {
            int sum1 = target;
            int sum2 = total_sum - sum1;

            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<minSubsetSumDifference(arr, n);
    return 0;
}