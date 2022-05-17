/*
link -> https://leetcode.com/problems/house-robber-ii/

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

i/p->
4
1 2 3 1
o/p->
4

Recursion -> tc->2^n sc->O(n)
Memoization -> tc-> O(n) sc-> O(n) + O(2n)
Tabulation -> tc-> O(n) sc-> O(2n)
Space optimization -> tc->O(n) sc->O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int stop, vector<int> arr, vector<int> &dp)
{
    // memoization
    if (i == stop)
        return arr[stop];

    if (dp[i] != -1)
        return dp[i];

    int nt = 0 + f(i - 1, stop,arr, dp);
    int t = arr[i];
    if (i > stop + 1)
        t += f(i - 2, stop, arr, dp);

    return dp[i] = max(nt, t);
}

int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    // memoization
    //  vector<int> dp1(n, -1);
    //  vector<int> dp2(n, -1);

    // int last = f(n-1, 1, arr, dp1);
    // int not_last = f(n-2, 0, arr, dp2);
     
    // return max(last, not_last); 

    // tabulation
    // vector<int> dp1(n, 0);
    // vector<int> dp2(n, 0);
    
    // //consider we take last element
    // dp1[1] = arr[1];
    // for(int i=2;i<n;i++){
    //     int nt = 0 + dp1[i-1];
    //     int t = arr[i];
    //     if (i > 2)
    //         t += dp1[i-2];

    //     dp1[i] = max(nt, t);
    // } 
    
    // //consider we dont take last element
    // dp2[0] = arr[0];
    // for(int i=1;i<n-1;i++){
    //     int nt = 0 + dp2[i - 1];
    //     int t = arr[i];
    //     if (i > 1)
    //         t += dp2[i - 2];

    //     dp2[i] = max(nt, t);
    // }

    // return max(dp1[n-1], dp2[n-2]);

    // space optimization
    //consider we take last element
    int prev1 = arr[1], prev2 = 0;
    for(int i=2;i<n;i++){
        int nt = 0 + prev1;
        int t = arr[i];
        if (i > 2)
            t += prev2;

        int curr = max(nt, t);
        prev2 = prev1;
        prev1 = curr;
    }

    //consider we dont take last element
    int p1 = arr[0], p2 = 0;
    for(int i=1;i<n-1;i++){
        int nt = 0 + p1;
        int t = arr[i];
        if (i > 1)
            t += p2;

        int curr = max(nt, t);

        p2 = p1;
        p1 = curr;
    }
    return max(p1, prev1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << rob(arr);
    return 0;
}