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
#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    vector<int> nums(n);
    for(int i=1;i<=n;i++)nums[i-1] = i;
    for(int i=1;i<=n-1;i++){
        if(i%2 == 1){
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.pop_back();
            int c = nums.back();
            nums.pop_back();
            nums.push_back(b);

            nums.push_back(b);
            nums.push_back(((a+c)/2));

            cout<<a<<" "<<c<<endl;

        }
        else{
            int a = nums.back();
            nums.pop_back();

            cout<<a<<" "<<a<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        solve(n);
    }
    return 0;
}