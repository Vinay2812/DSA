/*
link-> https://leetcode.com/problems/wildcard-matching/

ip->
"abcabczzzde"
"*abc???de*"

op->
true
*/
#include<bits/stdc++.h>
using namespace std;

bool f(int i, int j, string s, string p){
    if(i == 0 and j == 0)return true;
    if(i == 0){
        //j != 0
        for(int k=1;k<=j;k++){
            if(p[k-1] != '*'){
                return false;
            }
        }
        return true;
    }
    if(j == 0){
        //i != 0
        return false;
    }

    if(s[i-1] == p[j-1]){
        return f(i-1, j-1, s, p);
    }
    else if(p[j-1] == '?'){
        return f(i-1, j-1, s, p);
    }
    else if(p[j-1] == '*'){
        bool t = f(i-1, j-1, s, p);
        bool nt = f(i-1, j, s, p);
        bool empty = f(i, j-1, s, p);

        return (t || nt || empty);
    }
    else{
        return false;
    }
    
}
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    // return f(n, m, s, p); 

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0;i<=n;i++)dp[i][0] = false;

    for(int j=0;j<=m;j++){
        int ans = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                ans =  false;
                break;
            }
        }
        dp[0][j] = ans;
    }

    dp[0][0] = true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == p[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '?'){
               dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                bool t = dp[i-1][j-1];
                bool nt = dp[i-1][j];
                bool empty = dp[i][j-1];

                dp[i][j] =  (t || nt || empty);
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s, p;
    cin>>s>>p;

    cout<<isMatch(s, p);
    return 0;
}