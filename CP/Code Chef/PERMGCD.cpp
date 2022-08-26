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

void solve(){
    int N;
    int sum;
    cin>>N>>sum;

    // vi ans(N, 0);

    if(sum < N){
        cout<<-1;
        return;
    }
    int prefix = sum - (N - 1);
    cout<<prefix<<" ";

    for(int i=1;i<=N;i++){
        if(i!=prefix)cout<<i<<" ";
    }

    // for(int i=0)
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll T;cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}