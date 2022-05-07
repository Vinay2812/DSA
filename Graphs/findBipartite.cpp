#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int v;
    int c;
};

bool checkUsingBfs(int i, int V, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else
            {
                if (color[v] == color[u])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartite_BFS(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!checkUsingBfs(i, V, adj, color))
                return false;
        }
    }
    return true;
}

bool checkBipartite_usingDFS(int curr, int c, int V, vector<int> adj[], vector<int> &color)
{
    color[curr] = c;

    for (auto x : adj[curr])
    {
        if (color[x] == -1)
        {
            if (!checkBipartite_usingDFS(x, (1 - c), V, adj, color))
                return false;
        }
        else
        {
            if (c == color[x])
                return false;
        }
    }
    return true;
}
bool isBipartiteUsingDfs(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!checkBipartite_usingDFS(i, 1, V, adj, color))
                return false;
        }
    }
    return true;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isBipartite_BFS(V, adj);
    return 0;
}
/*
7 9
0 5 
0 1 
1 2 
1 6 
2 3 
3 6 
3 4 
4 6 
4 5 



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