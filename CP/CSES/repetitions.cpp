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

void solve(){
    string s;cin>>s;

    int maxi = 1;
    int cnt = 1;

    for(int i=1;i<s.size();i++){
        if(s[i] == s[i-1])cnt++;
        else{
            maxi = max(maxi, cnt);
            cnt = 1;
        }
    }
    cout<<max(maxi, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
    #endif

    ll T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}