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

const int N = 1e5+1;
vector<bool> prime(N, 1);
void createSieve(){

    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j] = false;
            }
        }
    }
}

int gcd(int a, int b){
    if(a == 0)return b;

    if(a>b){
        return gcd(a%b, b);
    }
    return gcd(b%a, a);
}
int solve(int n, vector<int>& nums){
    vector<int> dp(n, 1);
    vector<int> divisor(n, 1);
    createSieve();

    int maxi = 1;
    
    for(int i=n-1;i>=0;i--){
        divisor[i] = nums[i];
        for(int j=i+1;j<n;j++){
            if(nums[i]%nums[j] == 0){
                divisor[i] = nums[j];
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<solve(n, nums);
    return 0;
}