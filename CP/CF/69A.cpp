#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define first ff
#define second ss
#define sum_n(res,a) res=0; for(ll x:a) res+=x
#define setbits(n) __builtin_popcountll(n)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int a = 0, b = 0, c = 0;

    for(int i=0;i<n;i++){
        int x, y, z;
        cin>>x>>y>>z;
        a += x;
        b += y;
        c += z;
    }

    if(a == 0 and b == 0 and c == 0)cout<<"YES";
    else cout<<"NO";
}

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
        freopen("D:/Desktop/DSA/debug.txt","w", stderr);
    #endif

    ll T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}