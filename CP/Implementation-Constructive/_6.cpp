#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
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

void solve(ll n, vi& ans){
    ll pow = 1;
    while(n){
        if(n%10 == 0){
            n /= 10;
            pow *= 10;
            continue;
        }
        int rem = n%10;
        ans.push_back(rem*pow);
        pow*=10;
        n /= 10;
    }
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
        ll n;cin>>n;
        vi ans;
        solve(n, ans);
        cout<<ans.size()<<endl;
        for(auto it : ans)cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}