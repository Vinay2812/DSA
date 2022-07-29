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

vector<int> bfs(int V, vector<int>graph[]){
    vector<int> indegree(V, 0);

    for(int u=0;u<V;u++){
        for(int v : graph[u]){
            indegree[v]++;
        }
    }

    queue<int> q;

    for(int u=0;u<V;u++){
        if(indegree[u] == 0)q.push(u);
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(int v : graph[node]){
            indegree[v]--;
            if(indegree[v] == 0)q.push(v);
        }
    }

    return ans;

}

void dfs(int u, vector<int>graph[], vector<bool>& vis, stack<int>& st){
    vis[u] = 1;

    for(int v : graph[u]){
        if(!vis[v]){
            dfs(v, graph, vis, st);
        }
    }

    st.push(u);
}

vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
    stack<int> st;
    vector<int> ans;
    vector<bool> vis(V, 0);

    // for(int u=0;u<V;u++){
    //     if(!vis[u]){
    //         dfs(u, adj, vis, st);
    //     }
    // }

    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }

    ans = bfs(V, adj);

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

    vector<int> graph[V];

    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    auto ans = topoSort(V, graph);

    for(auto &it : ans)cout<<it<<" ";

    return 0;
}