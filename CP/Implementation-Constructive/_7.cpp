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


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll n, m;cin>>n>>m;
    bool atStart = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2 == 0){
                cout<<"#";
            }
            else{
                if(atStart){
                    if(j == 0)
                        cout<<"#";
                    else{
                        cout<<".";
                    }
                }
                else{
                    if(j == m-1){
                        cout<<"#";
                    }
                    else{
                        cout<<".";
                    }
                }
            }
        }
        if(i%2)atStart = !atStart;
        cout<<endl;
    }

    return 0;
}