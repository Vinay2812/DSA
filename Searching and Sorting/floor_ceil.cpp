#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvl vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define first ff
#define second ss
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#include<bits/stdc++.h>
using namespace std;

int lb(vi& nums, int x){
    int l = 0, h = nums.size()-1, ans = -1;
    while(l <= h){
        int mid = l + (h - l)/2;
        if(nums[mid] <= x){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid - 1;
        }
    }
    return ans;
}


pii solve(vi& nums, int x){
    pii ans = {-1, -1};
    int n = nums.size();
    
    int idx = lb(nums, x);
    if(nums[idx] == x){
        ans.ff = x;
        ans.ss = x;
    }
    else if(idx == -1){
        ans.ss = nums[0];
    }
    else if(idx == n-1){
        ans.ff = nums[n-1];
    }
    else{
        ans.ff = nums[idx];
        ans.ss = nums[idx+1];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    ll x;cin>>x;

    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    pii ans = solve(nums, x);
    cout<<ans.ff<<" "<<ans.ss;

    return 0;
}