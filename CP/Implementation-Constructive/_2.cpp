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


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    string s;
    cin>>s;

    ll n = s.size();

    for(ll i=0;i<n;i++){
        if(i == 0 and s[i] == '9')continue;
        int dig = s[i] - '0';
        if(dig > 9-dig)s[i] = char(9-dig+'0');
    }

    ll num = 0;

    for (ll i = 0; i < n; i++)
    {
        int dig = s[i] - '0';
        num = num * 10 + dig;
    }

    cout<<num<<endl;

    return 0;
}