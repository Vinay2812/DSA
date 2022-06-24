#include<bits/stdc++.h>
using namespace std;

void lis(vector<int> nums, vector<int> &lis)
{
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {
            if (nums[i] > nums[pi])
            {
                if (lis[pi] + 1 > lis[i])
                {
                    lis[i] = lis[pi] + 1;
                }
            }
        }
    }
}
int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> inc(n, 1), dec(n, 1);
    lis(nums, inc);
    reverse(nums.begin(), nums.end());
    lis(nums, dec);

    // for(int i=0;i<n;i++)cout<<inc[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++)cout<<dec[i]<<" ";
    // cout<<endl;
    reverse(dec.begin(), dec.end());
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (inc[i] + dec[i] - 1));
    }

    return maxi;
}
int main()
{
    return 0;
}