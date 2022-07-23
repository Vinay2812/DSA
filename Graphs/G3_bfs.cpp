#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#include<bits/stdc++.h>
using namespace std;

/*
tc-> O(V+E)
sc-> O(V+V)
*/

void findBFS(int u, vector<vector<int>> graph, vector<bool>& vis, vector<int>& ans){
    queue<int> q;
    vis[u] = 1;
    q.push(u);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int v : graph[node]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
vector<int> BFS(vector<vector<int>> graph, int V){
    vector<bool> vis(V, false);

    vector<int> ans;

    for(int u=0;u<V;u++){
        if(!vis[u]){
            findBFS(u, graph, vis, ans);
        }
    }
    
    return ans;
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

    //Unweighted Graph -> 2D
    vector<int> graph1[V];
    vector<vector<int>> graph2(V);
    
   //Weighted ->3D
    // vector<pii> graph1[V];
    // vector<vector<int>> graph2[V];
    


    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        graph2[u].push_back(v);
        graph2[v].push_back(u);
    }

    auto bfs = BFS(graph2, V);

    for(auto it : bfs)cout<<it<<" ";

    return 0;
}