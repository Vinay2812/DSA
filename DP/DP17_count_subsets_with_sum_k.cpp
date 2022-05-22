/*
link->https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
You are given an array (0-based indexing) of positive integers and
you have to tell how many different ways of selecting the elements from the array
are there such that the sum of chosen elements is equal to the target number “tar”.

ip->
4 5
2 5 3 2

op->
3

Recursion-> tc->O(2^(n*k)) sc->O(n)
Memoization -> tc->O(n*k) sc->O(n) + O(n*k)
Tabulation -> tc->O(n*k) sc-> O(n*k)
Space optimization-> tc->O(n*k) sc-> O(2*k)
*/

#include<bits/stdc++.h>
using namespace std;

int f(int i, int target, vector<int> &num, vector<vector<int>>& dp)
{
    if(target == 0)return 1;

    if(i == 0)return num[0] == target;

    if(dp[i][target] != -1)return dp[i][target];

    int nt = f(i-1, target, num, dp);
    int t = 0;
    if(num[i] <= target)t = f(i-1, target - num[i], num, dp);

    return dp[i][target] = t + nt;
}

int findWays(vector<int> &num, int k){
    int n = num.size();

    //memoization
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    // return f(n-1, k, num, dp);

    // tabulation
    // vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // for(int target=0;target<=k;target++)
    //     dp[0][target] = num[0] == target;
    
    // for(int i=0;i<n;i++)dp[i][0] = 1;

    // for(int i=1;i<n;i++){
    //     for(int target=1;target<=k;target++){
    //         int nt = dp[i-1][target];
    //         int t = 0;
    //         if (num[i] <= target)
    //             t = dp[i - 1][target - num[i]];

    //         dp[i][target] = t + nt;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // return dp[n-1][k];

    //space optimization
    vector<int>prev(k + 1, 0), curr(k+1, 0);

    for(int target=0;target<=k;target++)
        prev[target] = num[0] == target;

    prev[0] = 1;
    curr[0] = 1;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            int nt = prev[target];
            int t = 0;
            if (num[i] <= target)
                t = prev[target - num[i]];

            curr[target] = t + nt;
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> num(n);

    for(int i=0;i<n;i++)cin>>num[i];

    cout<<findWays(num, k);
    return 0;
}