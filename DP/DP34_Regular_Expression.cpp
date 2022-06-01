/*
link-> https://leetcode.com/problems/regular-expression-matching/

ip->
abnejjeeeeg
a.*j*ee*g*

op->
1
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string p){
    if(i ==0 and j == 0){
        return true;
    }

    if(i == 0){
        if(j%2 == 1)return false;
        else{
            for(int k=2;k<=j;k += 2){
                if(p[k-1] != '*')return false;
            }
            return true;
        }

    }

    if(j == 0){
        return false;
    }

    if(s[i-1] == p[j-1]){
        return f(i-1, j-1, s, p);
    }
    else if(p[j-1] == '.'){
        return f(i - 1, j - 1, s, p);
    }
    else if(p[j-1] == '*'){
        if(p[j-2] == s[i-1] || p[j-2] == '.'){
            int t = f(i-1, j, s, p);
            int nt = f(i, j-2, s, p);

            return (t || nt);
        }
        else{
            int nt = f(i, j - 2, s, p);
            return nt;
        }
    }
    else{
        return false;
    }
}

bool isMatch(string s, string p) {
    
    int n = s.size(), m = p.size();
    // return f(n, m, s, p);

    // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // for(int i=0;i<=n;i++)dp[i][0] = 0;

    // for(int j=0;j<=m;j++){
    //     if (j % 2 == 1)
    //         dp[0][j] = false;
    //     else
    //     {
    //         for (int k = 2; k <= j; k += 2)
    //         {
    //             if (p[k - 1] != '*')
    //                 dp[0][j] =  false;
    //                 break;
    //         }
    //         dp[0][j] = true;
    //     }
    // }

    // dp[0][0] = 1;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i-1] == p[j-1]){
    //             dp[i][j] =  dp[i-1][j-1];
    //         }
    //         else if(p[j-1] == '.'){
    //             dp[i][j] = dp[i-1][j-1];
    //         }
    //         else if(p[j-1] == '*'){
    //             if(p[j-2] == s[i-1] || p[j-2] == '.'){
    //                 int t = dp[i-1][j];
    //                 int nt = dp[i][j-2];

    //                 dp[i][j] = (t || nt);
    //             }
    //             else{
    //                 int nt = dp[i][j-2];
    //                 dp[i][j] = nt;
    //             }
    //         }
    //         else{
    //             dp[i][j] = false;
    //         }
    //     }
    // }
    // return dp[n][m];

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for (int j = 0; j <= m; j++)
    {
        if (j % 2 == 1)
            prev[j] = false;
        else
        {
            int ans = true;
            for (int k = 2; k <= j; k += 2)
            {
                if (p[k - 1] != '*')
                {
                    ans = false;
                    break;
                }
            }
            prev[j] = ans;
        }
    }

    curr[0] = prev[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == p[j-1]){
               curr[j] =  prev[j-1];
            }
            else if(p[j-1] == '.'){
                curr[j] = prev[j-1];
            }
            else if(p[j-1] == '*'){
                if(p[j-2] == s[i-1] || p[j-2] == '.'){
                    int t = prev[j];
                    int nt = curr[j-2];

                    curr[j] = (t || nt);
                }
                else{
                    int nt = curr[j-2];
                   curr[j] = nt;
                }
            }
            else{
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s, p;
    cin>>s>>p;

    cout<<isMatch(s, p);
    return 0;
}