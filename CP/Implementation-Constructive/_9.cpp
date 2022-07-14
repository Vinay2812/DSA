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

ll solve(vl& nums){
    ll mini = 1e18, maxi = -1e18, min_idx = -1, max_idx = -1, n = nums.size();

    for(int i=0;i<n;i++){
        if(nums[i] > maxi){
            maxi = nums[i];
            max_idx = i;
        }

        if(nums[i] <= mini){
            mini = nums[i];
            min_idx = i; 
        }
    }
    ll ans = 0;
    if(min_idx < max_idx){
        ans = max_idx + n - 1 - min_idx - 1;
    }
    else{
        ans = max_idx + n - 1 - min_idx;
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    vl nums(n);
    for(ll i=0;i<n;i++)cin>>nums[i];
    cout<<solve(nums);
    return 0;
}