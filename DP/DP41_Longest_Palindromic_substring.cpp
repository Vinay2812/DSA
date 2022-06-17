/*
link-> https://leetcode.com/problems/longest-palindromic-substring/
*/

#include<bits/stdc++.h>
using namespace std;

string substring(int st, int e, string s){
    string ans;
    for(int i=st;i<=e;i++){
        ans.push_back(s[i]);
    }
    return ans;
}

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>>dp (n, vector<int>(n, 0));
    string ans = substring(0, 0, s);
    for(int i=0;i<n;i++){
       dp[i][i] = 1;
    }
    int maxi = 1;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            if(maxi == 1){
                ans = substring(i, i+1, s);
                maxi = 2;
            }
        }
    }

    for(int i=n-3;i>=0;i++){
        for(int j = i+2;j<n;j++){
            if(s[i] == s[j] and dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                if(j - i + 1 > maxi){
                    maxi = j - i + 1;
                    ans = substring(i, j, s);
                }
            }
        }
    }

    return ans;

}



int main()
{
    string s;
    cin>>s;

    cout<<longestPalindrome(s);
    return 0;
}