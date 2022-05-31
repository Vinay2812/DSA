/*
link->

ip->
brute
groot

op->
bgruoote

*/
#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string a, string b) {

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0;j<=m;j++)dp[0][j] = 0; 
    for(int i=0;i<=n;i++)dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = m;
    string ans;
    while(i>0 and j>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans.push_back(a[i - 1]);
                i--;
            }
            else{
                ans.push_back(b[j - 1]);
                j--;
            }
        }
    }

    while(i>0){
        ans.push_back(a[i - 1]);
        i--;
    }

    while(j>0){
        ans.push_back(b[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout<<shortestCommonSupersequence(a, b);
    return 0;
}