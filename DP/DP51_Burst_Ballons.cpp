/*
link-> https://leetcode.com/problems/burst-balloons/
*/
#include<bits/stdc++.h>
using namespace std;

int f(int l, int h, vector<int> &nums, vector<vector<int>>& dp)
{
    if(l > h)return 0;

    if(dp[l][h] != -1)return dp[l][h];

    int max_cost = -1e9;

    for(int i=l;i<=h;i++){
        int cost =( nums[l-1] * nums[i] * nums[h+1]) + f(l, i-1, nums, dp) + f(i+1, h, nums, dp);
        max_cost = max(max_cost, cost);
    }

    return dp[l][h] = max_cost;
}
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int l=n-2;l>=1;l--){
        for(int h=l;h<=n-2;h++){
            int max_cost = -1e9;

            for (int i = l; i <= h; i++)
            {
                int cost = (nums[l - 1] * nums[i] * nums[h + 1]) + dp[l][i-1] + dp[i+1][h];
                max_cost = max(max_cost, cost);
            }

            dp[l][h] = max_cost;
        }
    }

    return dp[1][n-2]; 
}

int main()
{
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<maxCoins(nums);
    return 0;
}