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

bool isPossible(vector<ll> n, vector<ll> p, vector<ll> r, ll money, ll quantity){
    ll mb = max(0ll, r[0]*quantity-n[0]);
    ll ms = max(0ll, r[1]*quantity-n[1]);
    ll mc = max(0ll, r[2]*quantity-n[2]);

    return (mb*p[0] + ms*p[1] + mc*p[2]) <= money;
}

ll solve(vector<ll> n, vector<ll> p, vector<ll> r, ll money){
    ll ans = 0;
    ll l = 0, h = 1e15;

    while(l<=h){
        ll mid = l + (h-l)/2;
        if(isPossible(n,p,r,money, mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
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

    // 0-> bread 1->sausages 2->cheese
    string s;
    cin>>s;
    vector<ll> n(3);
    cin>>n[0]>>n[1]>>n[2];
    vector<ll> p(3);
    cin>>p[0]>>p[1]>>p[2];
    ll money;
    cin>>money;

    vector<ll> r(3, 0);
    for(auto c : s){
        if(c == 'B')r[0]++;
        else if(c == 'S')r[1]++;
        else r[2]++;
    }
    cout<<solve(n, p, r, money);
    return 0;
}