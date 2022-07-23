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
vector<int> prime;

void simpleSieve(int n, int& cnt){
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
        if(mark[i] == true){
            cnt++;
            prime.push_back(i);
            if((cnt)%100 == 1)cout<<i<<endl; 
        }
    }
}

void solve(){
    int n = int(1e8);
    int cnt = 0;
    int lim = floor(sqrt(n))+1;
    simpleSieve(lim-1, cnt);

    int size = prime.size();

    int low = lim;
    int high = 2*lim;

    while(low < n){
        if(high > n){
            high = n;
        }

        vector<bool> mark(lim, true);

        for(int i=0;i<size;i++){
            int start = (low/prime[i]) * prime[i];

            if(start < low)start+=prime[i];

            start = max(start, prime[i]*prime[i]);

            for(int j=start;j<=high;j+=prime[i]){
                mark[j-low] = false;
            }
        }

        for(int i=low;i<=high;i++){
            if(mark[i-low]){
                cnt++;
                if(cnt%100 == 1)cout<<i<<endl;
            }
        }

        low = low + lim;
        high = high + lim;
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
    return 0;
}