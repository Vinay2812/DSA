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

ll solve(vector<vector<char>> mat){
    int n = mat.size();
    int m = mat[0].size();

    ll cnt = 0;

    for(int j=0;j<m-1;j++){
        if(mat[n-1][j] == 'D')cnt++;
    }

    for(int i=0;i<n-1;i++){
        if(mat[i][m-1] == 'R')cnt++;
    }
    return cnt;
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
        ll n, m;
        cin>>n>>m;

        vector<vector<char>> mat(n, vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        cout<<solve(mat)<<endl;
    }
    return 0;
}