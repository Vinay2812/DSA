/*
link->
https://leetcode.com/problems/palindrome-partitioning-ii/submissions/
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
*/
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    int i=0, j=s.size()-1;

    while(i<j){
        if(s[i] != s[j])return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, string s){
    if(i == s.size())return 0;

    string temp;
    int mini = 1e9;
    for(int j=i;j<s.size();j++){
        temp.push_back(s[j]);
        if(isPalindrome(temp)){
            int cuts = 1 + f(j+1, s);
            mini = min(mini, cuts);
        }
    }

    return mini - 1;
}
int palindromicPartition(string s){
    int n = s.size();

    // O(n^3)
    // return f(0, s);
    // vector<int> dp(n+1, 0);

    // for(int i=n-1;i>=0;i--){
    //     string temp;
    //     int mini = 1e9;
    //     for (int j = i; j < n; j++)
    //     {
    //         temp.push_back(s[j]);
    //         if (isPalindrome(temp))
    //         {
    //             int cuts = 1 + dp[j+1];
    //             mini = min(mini, cuts);
    //         }
    //     }

    //     dp[i] = mini;
    // }

    // return dp[0]-1;

    //O(n^2)
    vector<int> dp(n + 1, 0);
    vector<vector<int>>palindrome (n, vector<int>(n, 0));

    // fill palindrome table to get substring is palindrome or not in O(1)
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i == j){
                palindrome[i][j] = 1;
            }
            else if(j == i+1 and s[i] == s[j]){
                palindrome[i][j] = 1;
            }
            else if(s[i] == s[j] and palindrome[i+1][j-1] == 1){
                palindrome[i][j] = 1;
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        int mini = 1e9;
        for (int j = i; j < n; j++)
        {
            if (palindrome[i][j] == 1)
            {
                int cuts = 1 + dp[j+1];
                mini = min(mini, cuts);
            }
        }

        dp[i] = mini;
    }

    return dp[0]-1;
}

int main()
{
    string s;
    cin>>s;

    cout<<palindromicPartition(s);
    return 0;
}