/*
link-> https://leetcode.com/problems/longest-palindromic-subsequence/

ip->
bbabcbcab

op->
bacbcab
7

*/
#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    string a = s;
    reverse(s.begin(), s.end());
    string b = s;

    int n = a.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int j=0;j<=n;j++)dp[0][j] = 0;
    for(int i=0;i<=n;i++)dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = n, j = n;
    string ans;
    int len = dp[n][n];

    while(len>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            len--;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<ans<<endl;
    return dp[n][n];
}
int main()
{
    string a;
    cin>>a;

    cout<<longestPalindromeSubseq(a);
    return 0;
}