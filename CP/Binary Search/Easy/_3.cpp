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

// bool f(ll i, ll target, vl& nums, vector<vector<vector<ll>>>& dp, ll k){
//     if(target <= 0)return true;
//     if(k == 0)return false;
//     if(i == 0)return nums[0] >= target;

//     if(dp[i][target][k]!=-1)return dp[i][target][k];
//     bool t = false, nt = false;

//     nt = f(i-1, target, nums, dp, k);
//     t = f(i-1, target-nums[i], nums, dp, k-1);

//     return dp[i][target][k] = t || nt;

// }
ll max_possible(ll target, ll k, vl& nums){
    // unordered_map<ll, ll> mp;
    ll n = nums.size();
    ll sum = 0;
    for(ll i=n-1;i>n+k-1;i--){
        
    }
}   


ll solve(ll n, ll k){
    vl nums;
    ll cnt = 2;
    ll i= 0;
    while(cnt <= k){
        nums.push_back(cnt++);
    }
    ll l = 2, h = k+2;
    ll ans = -1;
    // isPossible(8, 4);
    while(l < h){
        ll mid = l + (h-l)/2;
        dbg(mid);
        ll max_sum = max_possible(n, mid, nums);
        if(max_sum == n){
            ans = mid;
            h = mid;
        }
        else if(max_sum < n){
            ans = mid;
            l = mid+1;
        }
        else{
            h= mid;
        }
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
    ll k;cin>>k;

    cout<<solve(n,k);

    return 0;
}