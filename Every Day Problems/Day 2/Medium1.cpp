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
#define sum_n(res,a) res=0; for(ll x:a) res+=x;
#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> nums, int n, int k){
    deque<int> dq;
    // list<int> li;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!dq.empty() and nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    int l=0;
    for(int i=k;i<n;i++){
        while (!dq.empty() and nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        //window start-> l+1
        //window end-> i

        //doesnt belong to curr window
        while(dq.front() < l+1)dq.pop_front();

        ans.push_back(nums[dq.front()]);
        l++;
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
    vector<int> nums(n);
    for(ll i=0;i<n;i++)cin>>nums[i];

    auto ans = max_of_subarrays(nums, n, k);

    for(auto it : ans)cout<<it<<" ";
    return 0;
}