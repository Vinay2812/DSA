#include<bits/stdc++.h>
using namespace std;

int longestcommonsubstring(string a, string b){
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j=0;j<=m;j++)dp[0][j] = 0;
    for(int i=0;i<=n;i++)dp[i][0] = 0;

    int ans = 0;
    int x=0,y=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
               if(dp[i][j] > ans){
                   ans = dp[i][j];
                   x = i;
                   y = j;
               }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int len = ans;
    string res;
    while(len>0 and x>0 and y>0){
        res.push_back(a[x-1]);
        x--;
        y--;
        len--;
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;;
    return ans;
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout<<longestcommonsubstring(a, b);
    return 0;
}