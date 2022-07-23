#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<long long>
#define pii pasir<int, int>
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

bool isPossible(ll k, vl& time, ll h){
    ll n = time.size();
    ll cnt = 0;
    for(ll i=1;i<n;i++){
        cnt += min(time[i]-time[i-1], k);
        if(cnt >= h)return true;
    }
    return (cnt + k) >= h;
}

ll solve(){
    ll n;ll h;
    cin>>n>>h;

    vl time(n);
    for(ll i=0;i<n;i++){
        cin>>time[i];
    }

    ll l = 1, hi = h+1, ans = -1;

    while(l < hi){
        ll mid = l + (hi-l)/2;

        if(isPossible(mid, time, h)){
            ans = mid;
            hi = mid;
        }
        else{
            l = mid+1;
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

    ll t;cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}