#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int v;
    int w;
};

bool isCycle(int i,vector<Node>adj[],vector<int> &vis)
{
    queue<pair<int,int>>q;//curr,parent
    q.push({i,-1});
    vis[i]=1;

    while (!q.empty())
    {
        int u=q.front().first;
        int par=q.front().second;
        q.pop();

        for(auto x : adj[u])
        {
            if(!vis[x.v])
            {
                q.push({x.v,u});
                vis[x.v]=1;
            }
            else
            {
                if(par!=x.v)
                    return true;
            }
        }
    }
    return false;
}
bool checkCycle(int V,vector<Node>adj[])
{
    vector<int>vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && isCycle(i,adj,vis))
            return true;
    }

    return false;
}

int main()
{
    int V, E;
    cout << "Enter V,E and edges :\n";
    cin >> V >> E;
    vector<Node> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "\nGraph is :\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " : ";
        for (auto x : adj[i])
            cout << x.v << " ";
        cout << endl;
    }

    cout<<checkCycle(V,adj);
    return 0;
}

/*
7 9
0 5 10
0 1 28
1 2 16
1 6 14
2 3 12
3 6 18
3 4 22
4 6 24
4 5 25

             0
      10  /    \
        /       \  28
      /          \
     5            1
     \       14 /   \ 16
      \        /     \
       \      6       2
    25  \      \      /
         \   18 \    /12
          \      \  /
           4_______3
              22
*/