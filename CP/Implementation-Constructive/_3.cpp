#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
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

    vector<vector<int>> matrix(5, vector<int>(5)); 

    int x = -1, y = -1;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                x = i; 
                y = j;
            }
        }
    }

    pii target = {2, 2};

    cout<<(abs(target.ff - x) + abs(target.ss - y))<<endl;
    return 0;
}