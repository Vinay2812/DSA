#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 1);
    vector<int> count(n, 1);

    int maxi = 1;

    for(int i=1;i<n;i++){
        for(int pi=0;pi<i;pi++){
            if(nums[i] > nums[pi]){
                if(lis[pi] + 1 > lis[i]){
                    lis[i] = lis[pi] + 1;
                    count[i] = count[pi];

                    maxi = max(maxi, lis[i]);
                }
                else if (lis[pi] + 1 == lis[i]){
                    count[i] += count[pi];
                }
            }
        }
    } 

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(lis[i] == maxi){
            cnt += count[i];
        }
    } 
    return cnt; 
}

int main()
{
    return 0;
}