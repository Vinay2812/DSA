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

bool dfs(int u, vector<int>graph[], vector<bool>& vis, vector<bool>& dfs_vis){
    vis[u] = true;
    dfs_vis[u] = true;

    for(int v : graph[u]){
        if(vis[v] == true and dfs_vis[v] == true)return true;

        if(vis[v] == false){
            bool store = dfs(v, graph, vis, dfs_vis);
            if(store == true)return true;
        }
    }

    dfs_vis[u] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V, 0);
    vector<bool> dfs_vis(V,0);

    for(int u=0;u<V;u++){
        if(!vis[u]){
            bool ans = dfs(u, adj, vis, dfs_vis);
            if(ans == true)return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt","w", stdout);
    #endif

    int V, E;
    cin>>V>>E;

    vector<int> graph[V];

    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    cout<<isCyclic(V,graph);

    return 0;
}