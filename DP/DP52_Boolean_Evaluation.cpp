#include<bits/stdc++.h>
using namespace std;
int mod = 1003;
int f(int l, int h, bool isTrue, string s, vector<vector<vector<int>>> &dp)
{
    if (l > h)
        return 0;

    if (l == h)
    {
        if (isTrue == 1)
        {
            return s[l] == 'T';
        }
        else
        {
            return s[l] == 'F';
        }
    }
    if (dp[l][h][isTrue] != -1)
        return dp[l][h][isTrue];

    int ans = 0;
    for (int i = l + 1; i <= h; i += 2)
    {
        int lf = f(l, i - 1, 0, s, dp);
        int lt = f(l, i - 1, 1, s, dp);
        int rf = f(i + 1, h, 0, s, dp);
        int rt = f(i + 1, h, 1, s, dp);

        if (s[i] == '|')
        {
            if (isTrue)
                ans += (lf * rt) + (lt * rf) + (lt * rt);
            else
            {
                ans += (lf * rf);
            }
        }
        else if (s[i] == '&')
        {
            if (isTrue)
                ans += (lt * rt);
            else
            {
                ans += (lf * rt) + (lt * rf) + (lf * rf);
            }
        }
        else
        {
            if (isTrue)
                ans += (lf * rt) + (lt * rf);
            else
                ans += (lt * rt) + (lf * rf);
        }
    }

    return dp[l][h][isTrue] = int(ans % mod);
}
int countWays(int n, string s)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return f(0, n - 1, 1, s, dp);
}
int main()
{
    string s;
    cin>>s;

    cout<<countWays(s.size(), s);
    return 0;
}