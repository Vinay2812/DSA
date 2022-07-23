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

bool isPossible(vl req, vl has, ll n, ll m, ll quantity){
    for(ll i=0;i<n;i++){
        ll need = req[i] * quantity;
        if(need > has[i]){
            if(need-m>has[i]){
                return false;
            }
            else{
                m -= need-has[i];
            }
        }
    }
    return true;
}

ll solve(vl req, vl has, ll n, ll m){
    ll l = 0, h = 1e12, ans = 0;
    while(l <= h){
        ll mid = l + (h-l)/2;
        if(isPossible(req, has, n, m, mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid -1;
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
    ll m;cin>>m;

    vl req(n), has(n);
    for(ll i=0;i<n;i++)cin>>req[i];
    for(ll i=0;i<n;i++)cin>>has[i];

    cout<<solve(req, has, n, m);

    return 0;
}