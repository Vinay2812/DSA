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

auto buildGraph(string dict[], int n){
    // vector<vector<int>> graph(26);
    unordered_map<int, vector<int>> graph;

    for(int i=1;i<n;i++){
        string a = dict[i-1];
        string b = dict[i];

        int len = min(a.size(), b.size());

        for(int j=0;j<len;j++){
            if(a[j] != b[j]){
                int u = a[j] - 'a';
                int v = b[j] - 'a';
                graph[u].push_back(v);
                break;
            }
        }
    }

    return graph;
}
void dfs(int u, unordered_map<int, vector<int>> graph, vector<bool>& vis, stack<int>& st){
    vis[u] = 1;

    for(int v : graph[u]){
        if(!vis[v]){
            dfs(v, graph, vis, st);
        }
    }

    st.push(u);
}

string topoSort(int V, unordered_map<int, vector<int>> adj) {
	    // code here
    stack<int> st;
    string ans;
    vector<bool> vis(V, 0);

    for(auto it : adj){
        int u = it.first;
        if(!vis[u]){
            dfs(u, adj, vis, st);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top() + 'a');
        st.pop();
    }

    return ans;
}
string findOrder(string dict[], int N, int K) {
        //code here
    auto graph = buildGraph(dict, N);
    return topoSort(26, graph);

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    ll k;cin>>k;
    string words[n];
    for(int i=0;i<n;i++)cin>>words[i];

    cout<<findOrder(words, n, k);
    return 0;
}