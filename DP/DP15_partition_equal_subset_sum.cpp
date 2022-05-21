/*
link-> https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array nums containing only positive integers,
find if the array can be partitioned into two subsets such that the
sum of elements in both subsets is equal.

ip->
4
1 5 11 5

op->
1

Recursion-> tc->O(2^(n*k)) sc->O(n)
Memoization-> tc->O(n*k) sc->O(n) + O(n*k)
Tabulation->  tc->O(n*k) sc->O(n*k)
space optimization-> tc->tc->O(n*k) sc->O(2*k)

*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (i == 0)
    {
        return arr[0] == target;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    int nt = f(i - 1, target, arr, dp);
    int t = false;
    if (arr[i] <= target)
        t = f(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = (t || nt);
}

bool canPartition(vector<int>& arr){
    // memoization
    int n = arr.size();

    int sum = 0;
    for(auto x : arr)sum+=x;

    if(sum%2 == 1)return 0;

    int k = sum/2;

    // memoization
    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return f(n - 1, k, arr, dp);

    // tabulation
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

    // for(int i=0;i<n;i++){
    //     for(int target=0;target<=k;target++){
    //         cout<<dp[i][target]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // return dp[n-1][k];

    // space optimization
    // vector<int> prev(k + 1, 0), curr(k + 1, 0);

    // for (int target = 1; target <= k; target++)
    //     prev[target] = arr[0] == target;

    // prev[0] = curr[0] = 1;

    // for (int i = 1; i < n; i++)
    // {
    //     for (int target = 1; target <= k; target++)
    //     {
    //         int nt = prev[target];
    //         int t = false;
    //         if (arr[i] <= target)
    //             t = prev[target - arr[i]];

    //         curr[target] = (t || nt);
    //     }
    //     prev = curr;
    // }
    // return prev[k];
}

int main()
{
    int n;
    cin >> n ;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout<<canPartition(arr);
    return 0;
}