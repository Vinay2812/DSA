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

int spanningTree(int V, vector<vector<int>> graph[]){
    vector<bool> vis(V, false);
    vector<int> value(V, INT_MAX);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    value[0] = 0;
    int sum = 0;

    pq.push({value[0], 0});

    int i = 0;
    while(i<V){
        auto node = pq.top();
        pq.pop();

        int u = node.ss;
        int u_val = node.ff;
        if(vis[u] == 1)continue;

        i++;
        sum += u_val;
        vis[u] = true;

        for(auto no : graph[u]){
            int v = no[0];
            int uv_val = no[1];
            if(!vis[v]){
                if(value[v] > uv_val){
                    value[v] = uv_val;
                    pq.push({value[v], v});
                }
            }
        }
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt","w", stdout);
    #endif
    int V,E;
    cin>>V>>E;
    vector<vector<int>> graph[V];
    
    for(int i=0;i<E;i++){
        int u, v, w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cout<<spanningTree(V, graph);
    return 0;
}