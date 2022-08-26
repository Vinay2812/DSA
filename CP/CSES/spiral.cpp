#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define first ff
#define second ss
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define sum_n(res,a) res=0; for(ll x:a) res+=x
#define setbits(n) __builtin_popcountll(n)

#include<bits/stdc++.h>
using namespace std;
ll eq1(ll x, ll y){
    return (x*x - (y-1ll));
}

ll eq2(ll x, ll y){
    return (x*x - (2ll*x - 2ll) + (y-1ll));
}
void solve(){
    ll x, y;
    cin>>x>>y;

    if(y > x){
        if(y%2 == 1){
            cout<<eq1(y, x);
        }
        else{
            cout<<eq2(y, x);
        }
    }
    else{
        if(x%2 == 1){
            cout<<eq2(x, y);
        }
        else{
            cout<<eq1(x, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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