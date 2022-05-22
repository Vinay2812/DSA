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

int countPartitions(int n, int d, vector<int> &arr) {
    int mod = int(1e9 + 7);

    long long count = 0;

    int total_sum = 0;
    for (auto x : arr)
        total_sum += x;

    int k = total_sum ;
    // space optimization

    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    for (int target = 0; target <= k; target++)
        prev[target] = arr[0] == target;

    prev[0] = 1;
    curr[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            int nt = prev[target];
            int t = 0;
            if (arr[i] <= target)
                t = prev[target - arr[i]];

            curr[target] = t + nt;
        }
        prev = curr;
    }

    for(int target=0;target<=k/2;target++){
        int s1 = target;
        int s2 = k - s1;

        if(prev[s1] and prev[s2] and abs(s1 - s2) == d){
            count += min(prev[s1], prev[s2]);
        }
    }
    
    for(int i=0;i<=k;i++)cout<<prev[i]<<" ";
    cout<<endl;

    return count;
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