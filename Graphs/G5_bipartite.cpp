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

bool dfs(int u , vector<int>& color, vector<vector<int>>&graph){
    for(int v : graph[u]){
        if(color[v] != -1 and color[u] == color[v])return false;

        if(color[v] == -1){
            color[v] = !color[u];//gives opposite color to adjacent
            bool store = dfs(v, color, graph);
            if(store == false)return false;
        }
    }

    return true;
}

bool bfs(int u , vector<int>& color, vector<vector<int>>&graph){
    queue<int> q;

    q.push(u);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int v : graph[node]){
            if(color[v] != -1 and color[node] == color[v])return false;

            if(color[v] == -1){
                color[v] = !color[node];
                q.push(v);
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    //red = 0, blue = 1, not vis = -1
    vector<int> color(V, -1);

    for(int u=0;u<V;u++){
        if(color[u] == -1){
            color[u] = 0;
            // bool ans = dfs(u, color, graph);
            bool ans = bfs(u, color, graph);
            if(ans == false)return false;
        }
    }
    return true;
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

    vector<vector<int>> graph(V);

    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<isBipartite(graph);

    return 0;
}