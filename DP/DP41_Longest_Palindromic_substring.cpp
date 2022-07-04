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
    vector<vector<int>>palindrome (n, vector<int>(n, 0));
    int maxi = 1;
    int x, y;
   
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i == j){
                palindrome[i][j] = 1;
                maxi = 1;
                x = i;
                y = j;
            }
            else if(j == i+1 and s[i] == s[j]){
                palindrome[i][j] = 1;
                maxi = 2;
                x = i;
                y = j;
            }
            else if(s[i] == s[j] and palindrome[i+1][j-1] == 1){
                palindrome[i][j] = 1;
                if(j-i+1 > maxi){
                    maxi = j-i+1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    return substring(x, y, s);
}



int main()
{
    string s;
    cin>>s;

    cout<<longestPalindrome(s);
    return 0;
}