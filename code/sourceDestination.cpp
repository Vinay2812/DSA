#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&v,int x,int y,int n,int m){
    if(x<0 || y<0 || x>=n || y>=m || v[x][y]<=0)
        return;
    
    //vis[x][y]=true;
    v[x][y]=-v[x][y];
    dfs(v,x+1,y,n,m);
    dfs(v,x-1,y,n,m);
    dfs(v,x,y+1,n,m);
    dfs(v,x,y-1,n,m);
}
int main()
{
    int n,m;
    cin>>n>>m;



/*
 // vector<int>v(5,-1)     => -1 -1 -1 -1 -1

    vector<vector<int>>(5,vector<int>(2,-1))     => {{-1,-1} 
                                                     {-1,-1} 
                                                    {-1,-1} 
                                                    {-1,-1} 
                                                    {-1,-1}}
*/



    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

//vector<vector<bool>>vis(n,vector<bool>(m,false));
    int sx,sy,dx,dy;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1){
                sx=i;
                sy=j;
            }
            if(v[i][j]==2){
                dx=i;
                dy=j;
            }
        }
    }

    dfs(v,sx,sy,n,m);

    if(v[dx][dy]>0)
    cout<<"True";
    else
    cout<<"False";
    return 0;

}
/*
//0->wall  //1->source   //2->destination    //3->empty cell (travel only through empty cells)
3 0 0 0 
0 -3 -3 0         x-1,y   x,y+1
0 -1 0 3         x,y-1   x+1,y
0 -2 3 3 

s(x,y)   d(x,y)
  2,1      3,1
*/

