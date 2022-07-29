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

bool dfs(int u, int parent, vector<bool>& vis, vector<int> graph[]){
    vis[u] = 1;

    for(auto v : graph[u]){
        if(vis[v] == true and v != parent)return true;
        if(!vis[v]){
            bool store = dfs(v, u, vis, graph);
            if(store == true)return true;
        }
    }

    return false;
}

bool bfs(int u, vector<bool>& vis, vector<int>graph[]){
    queue<pii> q;
    q.push({u,-1});
    vis[u] = 1;

    while(!q.empty()){
        int node = q.front().ff;
        int parent = q.front().ss;

        q.pop();

        for(int v : graph[node]){
            if(vis[v] == 1 and v != parent)return true;

            if(!vis[v]){
                vis[v] = 1;
                q.push({v,node});
            }
        }
    }

    return false;
}
bool isCycle(int V, vector<int> graph[]) {
    vector<bool> vis(V, false);

    for(int u=0;u<V;u++){
        if(!vis[u]){
            // int ans = dfs(u, -1, vis, graph);
            int ans = bfs(u, vis, graph);
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
        graph[v].push_back(u);
    }

    cout<<isCycle(V, graph);

    return 0;
}