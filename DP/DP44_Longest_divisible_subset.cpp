#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> lis(n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int pi = 0; pi < i; pi++)
        {
            if (nums[i] % nums[pi] == 0)
            {
                if (lis[pi] + 1 > lis[i])
                {
                    lis[i] = lis[pi] + 1;
                    hash[i] = pi;
                    if (lis[i] > maxi)
                    {
                        maxi = lis[i];
                        pos = i;
                    }
                }
            }
        }
    }
    vector<int> ans;
    while (pos != hash[pos])
    {
        ans.push_back(nums[pos]);
        pos = hash[pos];
    }

    ans.push_back(nums[pos]);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    return 0;
}