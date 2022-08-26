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
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int &it : nums)cin>>it;

    ll cnt = 0;

    for(int i=1;i<n;i++){
        
        if(nums[i] < nums[i-1]){
            cnt += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];
        }
    }
    cout<<cnt;
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