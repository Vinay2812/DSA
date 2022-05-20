/*
link -> https://leetcode.com/problems/cherry-pickup-ii/
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j]
represents the number of cherries that you can collect from the (i, j) cell.
You have two robots that can collect cherries for you:
Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

ip->
4 3
3 1 1
2 5 1
1 5 5
2 1 1

op->
24

Recursion-> tc->(9^(n*m*m)) sc-> O(n)
Memoization-> tc->O(n*m*m*3*3) sc->O(n) + O(n*m*m)
Tabulation-> tc->O(n*m*m*3*3) sc->O(n*m*m)
Space optimization -> tc->O(n*m*m*3*3) sc->O(2*m*m)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>>& dp)
{
    if(i == n-1){
        if(j1 == j2)
            return grid[n-1][j1];
        return grid[n-1][j1] + grid[n-1][j2];
    }

    if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
    //j1-> -1, 0, +1
    //j2-> -1, 0, +1
    int maxi = -1e9;
    for(int c1=-1;c1<=1;c1++){
        for(int c2=-1;c2<=1;c2++){
            
            int sum = 0;
            if (j1 + c1 < 0 || j2 + c2 < 0 || j1 + c1>= m || j2 +c2>= m){
                sum = -1e9;
            }
            else if (j1 == j2){
                sum = grid[i][j1] + f(i + 1, j1 + c1, j2 + c2, grid, n, m, dp);
            }
            else{
                sum = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + c1, j2 + c2, grid, n, m, dp);
            }
            maxi = max(maxi, sum);
        }
        
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    //memoization
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    // return f(0,0,m-1,grid, n, m, dp);

    //tabulation
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    // //base condition
    // for(int j1=0;j1<m;j1++){
    //     for(int j2=0;j2<m;j2++){
    //         if(j1 == j2){
    //             dp[n - 1][j1][j2] = grid[n - 1][j1];
    //         }
    //         else{
    //             dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    //         }
    //     }
    // }

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     for(int j1=m-1;j1>=0;j1--){
    //         for(int j2=0;j2<m;j2++){
    //             int maxi = -1e9;
    //             for(int c1=-1;c1<=1;c1++){
    //                 for(int c2=-1;c2<=1;c2++){
                        
    //                     int sum = 0;
    //                     if (j1 + c1 < 0 || j2 + c2 < 0 || j1 + c1>= m || j2 +c2>= m){
    //                         sum = -1e9;
    //                     }
    //                     else if (j1 == j2){
    //                         sum = grid[i][j1] + dp[i + 1][j1 + c1][j2 + c2] ;
    //                     }
    //                     else{
    //                         sum = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + c1][j2 + c2];
    //                     }
    //                     maxi = max(maxi, sum);
    //                 }
                    
    //             }
    //             dp[i][j1][j2] = maxi;
    //         }
    //     }
    // }
    // return dp[0][0][m-1];

    // space optimization
    vector<vector<int>> next(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1 == j2){
                next[j1][j2] = grid[n - 1][j1];
            }
            else{
                next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for(int j1=m-1;j1>=0;j1--){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e9;
                for(int c1=-1;c1<=1;c1++){
                    for(int c2=-1;c2<=1;c2++){

                        int sum = 0;
                        if (j1 + c1 < 0 || j2 + c2 < 0 || j1 + c1>= m || j2 +c2>= m){
                            sum = -1e9;
                        }
                        else if (j1 == j2){
                            sum = grid[i][j1] + next[j1 + c1][j2 + c2] ;
                        }
                        else{
                            sum = grid[i][j1] + grid[i][j2] + next[j1 + c1][j2 + c2];
                        }
                        maxi = max(maxi, sum);
                    }

                }
                curr[j1][j2] = maxi;
            }
            
        }
        next = curr;
    }
    return next[0][m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    cout<<cherryPickup(grid);
    return 0;
}
