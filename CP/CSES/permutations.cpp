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
    int n;cin>>n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return;
    }
    if(n == 1){
        cout<<1;
        return;
    }
    vector<int> nums(n);
    nums[0] = 2;
    int cnt = (n/2) * 2;
    int i = 1;
    while(cnt > 2){
        nums[i++] = cnt;
        cnt-=2;
    }
    cnt = 1;
    while(cnt <= n){
        nums[i++] = cnt;
        cnt += 2;
    }
    for(auto it : nums)cout<<it<<" ";
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