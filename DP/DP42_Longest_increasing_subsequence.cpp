/*
link-> https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include<bits/stdc++.h>
using namespace std;
int f(int i, int pi, int n, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][pi] != -1)
        return dp[i][pi];

    int nt = 0 + f(i + 1, pi, n, nums, dp);
    int t = -1e9;
    if (pi == 0 || nums[i] > nums[pi - 1])
        t = 1 + f(i + 1, i + 1, n, nums, dp);//pi = i+1 since shifting of index

    return dp[i][pi] = max(t, nt);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    //recursion - tabulation
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return f(0, 0, n, nums, dp);

    // for (int pi = 0; pi <= n; pi++)
    //     dp[n][pi] = 0;

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int pi = 0; pi <= i; pi++)
    //     {
    //         int nt = 0 + dp[i + 1][pi];
    //         int t = -1e9;
    //         if (pi == 0 || nums[i] > nums[pi - 1])
    //             t = 1 + dp[i + 1][i + 1];

    //         dp[i][pi] = max(t, nt);
    //     }
    // }
    // return dp[0][0];

    vector<int> lis(n, 1);
    int maxi = 1;
    int pos = 0;

    for(int i=1;i<n;i++){
        for(int pi=0;pi<i;pi++){
            if(nums[i] > nums[pi]){
                if(lis[pi] + 1 > lis[i]){
                    lis[i] = lis[pi] + 1;
                    if(lis[i] > maxi){
                        maxi = lis[i];
                        pos = i;
                    }
                }
            }
        }
    }
    
    int len = maxi;
    int prev = -1;
    vector<int> ans;

    while(len > 0){
        
        if(ans.size() == 0 || nums[pos] < prev){
            ans.push_back(nums[pos]);
            prev = nums[pos];
            len--;
        }
        pos--;
    }
    reverse(ans.begin(), ans.end());
    
    for(auto it : ans)
        cout<<it<<" ";

    cout<<endl;
    return maxi;
}

int main()
{
    int n;cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<lengthOfLIS(nums);

    return 0;
}