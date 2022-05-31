/*
link-> https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/

ip->
good
mode

op->
4
*/
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    // space optimization
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    prev[0] = curr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                // not match
                int one = prev[j];
                int two = curr[j - 1];

                curr[j] = max(one, two);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minOperations(string a, string b)
{
    // Your code goes here
    int n = a.size();
    int m = b.size();

    int lcs = longestCommonSubsequence(a, b);

    return (n+m - (2*lcs));
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout<<minOperations(a, b);
    return 0;
}