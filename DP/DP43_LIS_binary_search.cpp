#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums){
    vector<int> ans;
    int len = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
        if(ans.size() == 0 || nums[i] > ans.back()){
            ans.push_back(nums[i]);
            len++;
        }
        else{
            int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[idx] = nums[i];
        }
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << lengthOfLIS(nums);
    return 0;
}