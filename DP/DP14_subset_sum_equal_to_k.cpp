/*
link-> https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’.
Otherwise, return false.

ip->
4 5
4 3 2 1

5 4
2 5 1 6 7

op->
1

0

Recursion-> tc->O(2^(n*k)) sc->O(n)
Memoization-> tc->O(n*k) sc->O(n) + O(n*k)
Tabulation->  tc->O(n*k) sc->O(n*k)
space optimization-> tc->tc->O(n*k) sc->O(2*k)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int target, vector<int> &arr, vector<vector<int>>& dp)
{
    if(target == 0)return true;

    if(i == 0){
        return arr[0] == target;
    }

    if(dp[i][target] != -1)return dp[i][target];

    int nt = f(i-1, target, arr, dp);
    int t = false;
    if(arr[i] <= target)t = f(i-1, target-arr[i], arr, dp);

    return dp[i][target] = (t || nt);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // memoization
    vector<vector<int>> dp(n, vector<int>(k+1, -1)); 
    return f(n - 1, k, arr, dp);

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
    // return dp[n-1][k];

    //space optimization
    vector<int>prev(k + 1, 0), curr(k+1,0);

    for(int target=1;target<=k;target++)
       prev[target] = arr[0] == target;

    prev[0] = curr[0] = 1;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            int nt = prev[target];
            int t = false;
            if (arr[i] <= target)
                t = prev[target-arr[i]];

            curr[target] = (t || nt);
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<subsetSumToK(n,k,arr);

    return 0;
}