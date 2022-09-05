#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define first ff
#define second ss
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define sum_n(res,a) res=0; for(ll x:a) res+=x
#define setbits(n) __builtin_popcountll(n)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include<bits/stdc++.h>
using namespace std;

bool isPossible(ll k, ll num, ll n){
    return (n-1) * num >= (k - num);
}

void solve(){
    ll n, k;cin>>n>>k;

    k = ceil((double)n/k) * k;
    

    ll l = 1, h = k, ans = -1;

    while(l <= h){
        ll mid = l + (h - l)/2;

        if(isPossible(k, mid, n)){
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<ans;
}

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
    #endif

    ll T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}