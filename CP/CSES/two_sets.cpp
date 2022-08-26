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
    ll n;cin>>n;

    ll sum = (n * (n+1))/2;

    if(sum%2 == 1){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    sum /= 2;
    vector<int> a, b;

    for(int i=n;i>=1;i--){
        if(i <= sum){
            a.push_back(i);
            sum -= i;
        }
        else{
            b.push_back(i);
        }
    }
    cout<<a.size()<<endl;
    for(int x : a)cout<<x<<" ";
    cout<<endl;
    cout<<b.size()<<endl;
    for(int x : b)cout<<x<<" ";
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