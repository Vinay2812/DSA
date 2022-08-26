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

int dp[16][2][2][1<<16];

int f(int i, bool set, bool tight, int vis, string R){
    if(i == 0)return set;

    if (dp[i][set][tight][vis] != -1)
        return dp[i][set][tight][vis];

    int ub = 9;
    if(tight){
        ub = R[R.size() - i] - '0';
    }

    int cnt = 0;

    for(int dig=0;dig<=ub;dig++){
        if(!set and dig == 0){
            cnt += f(i-1, false, tight & dig == ub, vis, R);
        }
        else if((vis & 1<<dig) == 0){
            cnt += f(i-1, true, (tight&(dig==ub)), vis|(1<<dig), R);
        }
    }
    return dp[i][set][tight][vis] = cnt;
}

int numDupDigitsAtMostN(ll n) {
    string R = to_string(n);
    bool flag = false;
    memset(dp, -1, sizeof dp);
    return n - f(R.size(), false, true, 0, R);
}

void solve(){
    int n;
    cin>>n;
    cout<<numDupDigitsAtMostN(n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll T;
    T = 1;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}