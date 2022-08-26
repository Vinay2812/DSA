#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define first ff
#define second ss
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define sum_n(res,a) res=0; for(ll x:a) res+=x
#define setbits(n) __builtin_popcountll(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> xdir = {-1, 0, 1, 0};
vector<int> ydir = {0, -1, 0, 1};

bool isValid(int i, int j, int n, int m, vector<vector<int>> &matrix){
    if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == 0)
        return 0;
    return 1;
}

int dfs(int i, int j, int n, int m, vector<vector<int>> &matrix)
{
    if (!isValid(i, j, n, m, matrix))return 0;
        
    int cnt = 1;
    matrix[i][j] = 0;

    for(int k=0;k<4;k++){
        int x = i + xdir[k];
        int y = j + ydir[k];
        cnt += dfs(x, y, n, m, matrix); 
    }
    return cnt;
}

void solve(int n, int m, vector<vector<int>>& matrix){
    // vector<int> temp;
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1 and dfs(i, j, n, m, matrix)>0)cnt++;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
    #endif

    int n, m;     
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    solve(n, m, matrix);
    return 0;
}