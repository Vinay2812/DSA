/*
link-> https://leetcode.com/problems/target-sum/

ip->
5 3
1 1 1 1 1

op->
5

*/
#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    for (int target = 0; target <= k; target++)
    {
        if (num[0] == 0 and target == 0)
            prev[0] = 2;
        else if (num[0] == target)
            prev[target] = 1;
        else if (num[0] != 0 and target == 0)
            prev[0] = 1;
        else
            prev[target] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto &it : arr)
        total += it;

    if (total - d < 0 || (total - d) % 2 == 1)
        return 0;

    int k = (total - d) / 2; // subset2 sum

    return findWays(arr, k);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartitions(n, target, nums); 
}

int main()
{
    int n;
    int target;

    cin>>n>>target;

    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<findTargetSumWays(nums, target);
    return 0;
}