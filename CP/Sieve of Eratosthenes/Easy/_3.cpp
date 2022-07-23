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

int ans[5000001];
vector<int> prime;
int cnt = 0;
void createSieve(int n){
    prime.clear();
    vector<bool> mark(n+1, 1);

    for(int i=2;i*i<=n;i++){
        if(mark[i]){
            for(int j=i*i;j<=n;j+=i){
                mark[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(mark[i]){
            prime.push_back(i);
            ans[cnt++] = i;
        }
    }
}

void solve(){
    int n = 90000001;

    int limit = floor(sqrt(n))+1;
    createSieve(limit-1);
    int low = limit;
    int high = 2*limit;

    int size = prime.size();

    while(low < n){
        if(high > n)high = n;

        bool mark[high-low+1];
        memset(mark, 1, sizeof(mark));

        for(int i=0;i<size;i++){

            int start = (low/prime[i]) * prime[i];

            if(start < low)start+=prime[i];

            start = max(start, prime[i]*prime[i]);

            for(int j=start;j<=high;j+=prime[i]){
                mark[j-low] = false;
            }
        }

        for(int i=low;i<=high;i++){
            if(cnt < 5000000 and mark[i-low]){
                ans[cnt++] = i;
            }
        }

        low = low + limit;
        high = high + limit;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    solve();
    ll t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<ans[n-1]<<endl;
    }
    return 0;
}