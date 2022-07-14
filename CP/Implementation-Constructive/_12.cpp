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


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    ll cnt =  0;
    while(n){
        int r = n%10;
        if(r == 7 || r == 4)cnt++;
        n /= 10;
    }
    if(cnt == 0)cout<<"NO";
    else{
        ll cnt1 = 0, cnt2 = 0;
        while(cnt){
            int r = cnt%10;
            if(r!=4 and r!=7)break;
            cnt /= 10;
        }
        if(cnt == 0)cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}