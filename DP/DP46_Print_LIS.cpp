
#include<bits/stdc++.h>
using namespace std;

void LIS(vector<int> nums){
    int n = nums.size();
    vector<int> lis(n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int pos = 0;

    for(int i=1;i<n;i++){
        hash[i] = i;
        for(int pi=0;pi<i;pi++){
            if(nums[i] > nums[pi]){
                if(lis[pi] + 1 > lis[i]){
                    lis[i] = lis[pi] + 1;
                    hash[i] = pi;
                    if(lis[i] > maxi){
                        maxi = lis[i];
                        pos = i;
                    }
                }
            }
        }
    }
    vector<int> ans;
    while(pos != hash[pos]){
        ans.push_back(nums[pos]);
        pos = hash[pos];
    }

    ans.push_back(nums[pos]);
    reverse(ans.begin(), ans.end());

    for(int it : ans){
        cout<<it<<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    LIS(nums);
    return 0;
}