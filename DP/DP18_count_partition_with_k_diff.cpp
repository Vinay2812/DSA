/*
link-> https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos#:~:text=Given%20a%20difference%20'D'%2C,10%5E9%20%2B%207'.

Given an array ‘ARR’, partition it into two subsets (possibly empty)
such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the arrber of partitions in which ‘S1’ is greater than or equal to ‘S2’ and
the difference between ‘S1’ and ‘S2’ is equal to ‘D’.
Since the answer may be too large, return it modulo ‘10^9 + 7’.

ip->
5 1
3 2 2 5 1
op->
3
*/
#include<bits/stdc++.h>
using namespace std;
int f(int i, int target, vector<int> &num, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (num[0] == 0 and target == 0)
            return 2;
        else if (num[0] == target)
            return 1;
        else if (target == 0)
            return 1;
        else
            return 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    int nt = f(i - 1, target, num, dp);
    int t = 0;
    if (num[i] <= target)
        t = f(i - 1, target - num[i], num, dp);

    return dp[i][target] = t + nt;
}

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

int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(auto &it : arr)total+=it;

    if(total-d < 0 || (total-d)%2 == 1)return 0;

    int k = (total - d) / 2;//subset2 sum

    return findWays(arr, k);
}

int main()
{
    int n, d;
    cin>>n>>d;
    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<countPartitions(n, d, arr);
    return 0;
}