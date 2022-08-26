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

int dp[10][2];

int count(int n, bool tight, string R){
    if(!tight){
        return (pow(10, n) + 0.01);
    }
    
    if (n == 0)
        return 1;
    
    int ub = R[R.size() - n] - '0';
    int cnt = 0;
    for(int dig=0;dig<=ub;dig++){
        cnt += count(n-1, tight & (dig == ub), R);
    }
    // cout<<cnt<<" ";
    return cnt;
}

int f(int i, bool tight, string R){
    if(i == 0)return 0;

    if(dp[i][tight] != -1)return dp[i][tight];

    int ub = 9;
    if(tight){
        ub = R[R.size() - i] - '0';
    }
    // cout<<ub<<" ";
    int cnt = 0;
    for(int dig=0;dig<=ub;dig++){
        if(dig == 1){
            cnt += count(i-1, (tight & (dig == ub)), R);
        }
        cnt += f(i-1, (tight & (dig == ub)), R);
        
    }
    // cout << R.size() - i << " " << cnt << endl;
    return dp[i][tight] = cnt;
}

int countDigitOne(int n){
    string R = to_string(n);
    memset(dp, -1, sizeof dp);
    return f(R.size(), 1, R);
}

void solve(){
    int n;
    cin>>n;
    cout<<countDigitOne(n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll T;
    // cin>>T;
    T = 1;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}