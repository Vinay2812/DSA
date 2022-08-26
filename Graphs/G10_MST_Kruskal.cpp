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

void initialize(vector<int>& parent, int V){
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
}

int getRank(int a, vector<int>& parent){
    while(a!=parent[a]){
        a = parent[a];
    }
    return a;
}

void make_union(int a, int b, vector<int>& parent){
    parent[a] = getRank(a, parent);
    parent[b] = getRank(b, parent);
}


int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> parent(V, 0);
    initialize(parent, V);

    vector<vector<int>> graph;

    for(int u=0;u<V;u++){
        for(auto node : adj[u]){
            graph.push_back({node[1], u, node[0]});//w u v
        }
    }

    sort(graph.begin(), graph.end());

    int n = graph.size();
    int cnt = 0;
    int sum = 0;

    for(int i=0;i<n and cnt < V;i++){
        int u = graph[i][1];
        int v = graph[i][2];

        if(parent[u] != parent[v]){
            sum += graph[i][0];
            cnt++;
            make_union(u, v, parent); // u->parent and v->child
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