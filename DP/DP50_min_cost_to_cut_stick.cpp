/*
link->https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> cuts, vector<vector<int>> &dp)
{
    if(i > j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int mini = 1e9;
    for(int c=i;c<=j;c++){
        int cost = cuts[j+1] - cuts[i-1] + f(i,c-1, cuts, dp) + f(c+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& cuts) {
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());
    int l = cuts.size();
    vector<vector<int>> dp(l, vector<int>(l, 0));

    for(int i=l-2;i>=1;i--){
        for(int j=i;j<=l-2;j++){
            int mini = 1e9;
            for (int c = i; c <= j; c++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][c-1] + dp[c+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][l-2];
}

int main(){
    int n;
    cin>>n;
    vector<int> cuts(n);
    for(int i=0;i<n;i++)cin>>cuts[i];

    cout<<minCost(n, cuts);
    return 0;
}