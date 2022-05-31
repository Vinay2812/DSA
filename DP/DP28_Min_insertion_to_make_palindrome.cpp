/*
link-> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/


*/
#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(s.begin(), s.end());
    string b = s;

    int n = a.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int minInsertions(string s)
{
    int n = s.size();

    int len = longestPalindromeSubseq(s);
    return n - len;
}
int main()
{
    string a;
    cin >> a;

    cout << minInsertions(a);
    return 0;
}